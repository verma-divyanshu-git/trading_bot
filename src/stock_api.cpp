#include "stock_api.h"

StockAPI::StockAPI()
    : currentPrice(100.0), distribution(-0.05, 0.05) {}

double StockAPI::getPrice()
{
    return currentPrice;
}

void StockAPI::simulatePriceMovement()
{
    // Random price fluctuation
    currentPrice += currentPrice * distribution(generator);
}