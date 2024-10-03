#include "profit_tracker.h"

ProfitTracker::ProfitTracker(double initialBalance)
    : balance(initialBalance), heldShares(0) {}

void ProfitTracker::buy(double price)
{
    heldShares += balance / price;
    tradeHistory.emplace_back("BUY", price);
    balance = 0;
}

void ProfitTracker::sell(double price)
{
    if (heldShares > 0)
    {
        balance += heldShares * price;
        tradeHistory.emplace_back("SELL", price);
        heldShares = 0;
    }
}

void ProfitTracker::printReport()
{
    std::cout << "Trade History:\n";
    for (const auto &trade : tradeHistory)
    {
        std::cout << trade.first << " at $" << trade.second << "\n";
    }
    std::cout << "Final balance: $" << balance << "\n";
}
