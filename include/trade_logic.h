#pragma once
#include "stock_api.h"

enum class TradeAction
{
    HOLD,
    BUY,
    SELL
};

class TradeLogic
{
public:
    TradeLogic(double buyThreshold, double sellThreshold);
    TradeAction decide(double currentPrice, double previousPrice);

private:
    double buyThreshold;
    double sellThreshold;
};
