#pragma once
#include <vector>
#include <random>

class StockAPI {
public:
    StockAPI();
    double getPrice();
    void simulatePriceMovement();

private:
    double currentPrice;
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution;
};
