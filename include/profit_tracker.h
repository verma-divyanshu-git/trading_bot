#pragma once
#include <vector>
#include <iostream>

class ProfitTracker
{
public:
    ProfitTracker(double initialBalance);
    void buy(double price);
    void sell(double price);
    void printReport();
    void calculateAnalytics();

private:
    double balance;
    double heldShares;
    double initialBalance;
    int totalTrades;
    int winningTrades;
    int losingTrades;
    double totalProfit;
    std::vector<std::pair<std::string, double>> tradeHistory;
};