#include "profit_tracker.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

ProfitTracker::ProfitTracker(double initialBalance)
    : balance(initialBalance), initialBalance(initialBalance), heldShares(0), totalTrades(0), winningTrades(0), losingTrades(0), totalProfit(0) {}

void ProfitTracker::buy(double price)
{
    if (balance > 0)
    {
        heldShares += balance / price;
        tradeHistory.emplace_back("BUY", price);
        balance = 0;
    }
}

void ProfitTracker::sell(double price)
{
    if (heldShares > 0)
    {
        double profit = heldShares * price - initialBalance;
        if (profit > 0)
        {
            winningTrades++;
        }
        else
        {
            losingTrades++;
        }
        totalProfit += profit;
        balance += heldShares * price;
        tradeHistory.emplace_back("SELL", price);
        heldShares = 0;
        totalTrades++;
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
    std::cout << "Total trades: " << totalTrades << "\n";
    calculateAnalytics();
}

void ProfitTracker::calculateAnalytics()
{
    double averageProfit = totalTrades > 0 ? totalProfit / totalTrades : 0;
    double winLossRatio = losingTrades > 0 ? (double)winningTrades / losingTrades : winningTrades;

    std::cout << "Analytics Summary:\n";
    std::cout << "Total profit: $" << totalProfit << "\n";
    std::cout << "Average profit per trade: $" << averageProfit << "\n";
    std::cout << "Winning trades: " << winningTrades << "\n";
    std::cout << "Losing trades: " << losingTrades << "\n";
    std::cout << "Win/Loss ratio: " << winLossRatio << "\n";

    auto logger = spdlog::get("file_logger");
    logger->info("Total profit: ${:.2f}", totalProfit);
    logger->info("Average profit per trade: ${:.2f}", averageProfit);
    logger->info("Winning trades: {}", winningTrades);
    logger->info("Losing trades: {}", losingTrades);
    logger->info("Win/Loss ratio: {:.2f}", winLossRatio);
}