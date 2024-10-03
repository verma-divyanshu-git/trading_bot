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

private:
    double balance;
    double heldShares;
    std::vector<std::pair<std::string, double>> tradeHistory;
};
