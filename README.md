# Trading Bot Simulation

## Overview
This is a basic trading bot simulation implemented in C++. It monitors stock price fluctuations and executes trades based on predefined strategies, including dynamic strategy switching (e.g., buy when the price drops by 2% and sell when it rises by 3%).

## Components

- **StockAPI**: Simulates real-time stock prices using mock data.
- **TradingStrategy**: Implements trading strategies based on price changes, including:
  - Threshold-based strategy
  - Momentum trading
  - Moving average crossover
- **ProfitTracker**: Tracks the bot’s balance, held shares, and profit/loss.
- **Main Execution Loop**: Handles strategy switching, trade execution, and profit/loss tracking.

## Build Instructions

```bash 
g++ -std=c++17 -Iinclude -Iconfig src/.cpp config/.cpp -o trading_bot -lfmt -pthread
```
## Run the Application

```bash
./trading_bot
```

## Configuration
You can adjust thresholds (e.g., 2% buy, 3% sell) in the environment variables.  
The initial balance is set via environment variables or defaults to $10,000.

### Environment Variables

- **BUY_THRESHOLD**: The percentage drop that triggers a "buy" action. Default is 0.02 (2%).
- **SELL_THRESHOLD**: The percentage rise that triggers a "sell" action. Default is 0.03 (3%).
- **INITIAL_BALANCE**: The initial cash balance the bot uses for trading. Default is 10000 ($10,000).

### Example usage

```bash
export BUY_THRESHOLD=0.02  
export SELL_THRESHOLD=0.03  
export INITIAL_BALANCE=15000  
./trading_bot
```

## Strategy Switching
The bot dynamically switches between multiple trading strategies:

- **Threshold Strategy**: Buys when the price drops by a percentage threshold and sells when it rises.
- **Momentum Strategy**: Buys when prices are consistently increasing and sells when they start decreasing.
- **Moving Average Crossover**: Buys when the short-term moving average crosses above the long-term moving average and sells when it crosses below.

The strategy switching is done dynamically based on predefined rules (switching strategies every 20 price ticks).

## Logging and Analytics

- **Logging**: The bot logs all buy, sell, and hold actions to a log file (`trading_bot.log`) along with timestamps and prices.
- **Analytics**: At the end of the trading session, the bot outputs detailed analytics, including:
  - Total profit
  - Average profit per trade
  - Number of winning and losing trades
  - Win/Loss ratio

## Example Log Output
Each trading session generates a log file (`trading_bot.log`) that records actions such as buying, selling, and holding at specific price points.

```bash
Buying at $96.3154  
Selling at $99.0136  
Holding at $95.9171 
... 
```

The final balance and analytics summary are printed at the end of the session.

## Advanced Features

- **Multiple Trading Strategies**: The bot can switch between multiple strategies (momentum trading, moving averages, threshold-based) dynamically based on market conditions or predefined criteria.
- **Logging & Analytics**: Detailed logs of trading actions and performance analytics, including win/loss ratio and total profits.

## Conclusion
This structure is modular and can be easily extended for additional trading strategies or improved analytics, depending on the needs of the trading bot or the complexity of the simulation.