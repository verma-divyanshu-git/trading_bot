// main.cpp
#include "stock_api.h"
#include "trade_logic.h"
#include "profit_tracker.h"
#include <iostream>
#include <chrono>
#include <thread>

int main()
{
    StockAPI stockAPI;
    TradeLogic tradeLogic(0.02, 0.03);  // Buy on 2% drop, sell on 3% rise
    ProfitTracker profitTracker(10000); // Start with $10,000

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