#include "stock_api.h"
#include "profit_tracker.h"
#include "env_config.h"
#include "threshold_strategy.h"
#include "momentum_strategy.h"
#include "moving_average_strategy.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <memory>

int main()
{

    auto logger = spdlog::basic_logger_mt("file_logger", "trading_bot.log", true);
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S] [%l] %v");
    logger->info("Trading bot started");

    double buyThreshold = EnvConfig::getEnvDouble("BUY_THRESHOLD", 0.02);        // Default: 2% drop
    double sellThreshold = EnvConfig::getEnvDouble("SELL_THRESHOLD", 0.03);      // Default: 3% rise
    double initialBalance = EnvConfig::getEnvDouble("INITIAL_BALANCE", 10000.0); // Default: $10,000

    StockAPI stockAPI;
    ProfitTracker profitTracker(initialBalance);

    // Create strategy objects
    std::unique_ptr<TradingStrategy> strategy = std::make_unique<ThresholdStrategy>(buyThreshold, sellThreshold);

    double previousPrice = stockAPI.getPrice();

    for (int i = 0; i < 100; ++i)
    {
        // Simulate 100 price ticks
        stockAPI.simulatePriceMovement();
        double currentPrice = stockAPI.getPrice();

        // Dynamic strategy switching based on some condition (e.g., every 20 iterations)
        if (i == 20)
        {
            strategy = std::make_unique<MomentumStrategy>(5); // Switch to Momentum Strategy
            logger->info("Switched to Momentum Strategy");
        }

        else if (i == 50)
        {
            strategy = std::make_unique<MovingAverageStrategy>(5, 10); // Switch to Moving Average Strategy
            logger->info("Switched to Moving Average Strategy");
        }

        TradeAction action = strategy->decide(currentPrice, previousPrice);
        
        switch (action)
        {
        case TradeAction::BUY:
            logger->info("Buying at ${:.2f}", currentPrice);
            std::cout << "Buying at $" << currentPrice << "\n";
            profitTracker.buy(currentPrice);
            break;
        case TradeAction::SELL:
            logger->info("Selling at ${:.2f}", currentPrice);
            std::cout << "Selling at $" << currentPrice << "\n";
            profitTracker.sell(currentPrice);
            break;
        case TradeAction::HOLD:
            logger->info("Holding at ${:.2f}", currentPrice);
            std::cout << "Holding at $" << currentPrice << "\n";
            break;
        }

        previousPrice = currentPrice;

        // std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // 1-second delay to simulate real-time
    }

    logger->info("Trading session completed");
    profitTracker.printReport();
    return 0;
}