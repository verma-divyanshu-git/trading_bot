#include "stock_api.h"
#include "trade_logic.h"
#include "profit_tracker.h"
#include "env_config.h"
#include <iostream>
#include <chrono>
#include <thread>

int main()
{
    double buyThreshold = EnvConfig::getEnvDouble("BUY_THRESHOLD", 0.02);        // Default: 2% drop
    double sellThreshold = EnvConfig::getEnvDouble("SELL_THRESHOLD", 0.03);      // Default: 3% rise
    double initialBalance = EnvConfig::getEnvDouble("INITIAL_BALANCE", 10000.0); // Default: $10,000

    StockAPI stockAPI;
    TradeLogic tradeLogic(buyThreshold, sellThreshold); // Buy on 2% drop, sell on 3% rise
    ProfitTracker profitTracker(initialBalance);        // Start with $10,000

    double previousPrice = stockAPI.getPrice();

    for (int i = 0; i < 100; ++i)
    {
        // Simulate 100 price ticks
        stockAPI.simulatePriceMovement();
        double currentPrice = stockAPI.getPrice();
        TradeAction action = tradeLogic.decide(currentPrice, previousPrice);

        switch (action)
        {
        case TradeAction::BUY:
            std::cout << "Buying at $" << currentPrice << "\n";
            profitTracker.buy(currentPrice);
            break;
        case TradeAction::SELL:
            std::cout << "Selling at $" << currentPrice << "\n";
            profitTracker.sell(currentPrice);
            break;
        case TradeAction::HOLD:
            std::cout << "Holding at $" << currentPrice << "\n";
            break;
        }

        previousPrice = currentPrice;

        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // 1-second delay to simulate real-time
    }

    profitTracker.printReport();
    return 0;
}