#include "trade_logic.h"

TradeLogic::TradeLogic(double buyThreshold, double sellThreshold)
    : buyThreshold(buyThreshold), sellThreshold(sellThreshold) {}

TradeAction TradeLogic::decide(double currentPrice, double previousPrice)
{
    if (currentPrice <= previousPrice * (1 - buyThreshold))
    {
        return TradeAction::BUY;
    }
    else if (currentPrice >= previousPrice * (1 + sellThreshold))
    {
        return TradeAction::SELL;
    }
    else
    {
        return TradeAction::HOLD;
    }
}
