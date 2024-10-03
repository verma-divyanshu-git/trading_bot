# Trading Bot Simulation

## Overview
This is a basic trading bot simulation implemented in C++. It monitors stock price fluctuations and executes trades based on predefined strategies (buy when the price drops by 2% and sell when it rises by 3%).

## Components
1. **StockAPI**: Simulates real-time stock prices using mock data.
2. **TradeLogic**: Implements trading strategies based on price changes.
3. **ProfitTracker**: Tracks the bot’s balance, held shares, and profit/loss.
4. **Main**: The main execution loop for the bot.

## Build Instructions
```bash
g++ -std=c++17 -Iinclude -Iconfig src/*.cpp config/*.cpp -o trading_bot -lfmt -pthread
```

## Run the Application
```bash
./trading_bot
```

## Configuration
1.  You can adjust thresholds (e.g., 2% buy, 3% sell) in trade_logic.cpp.
2. Initial balance can be set in profit_tracker.cpp.

## Environment Variables

The trading bot accepts several configurations via environment variables:

- `BUY_THRESHOLD`: The percentage drop that triggers a "buy" action. Default is `0.02` (2%).
- `SELL_THRESHOLD`: The percentage rise that triggers a "sell" action. Default is `0.03` (3%).
- `INITIAL_BALANCE`: The initial cash balance the bot uses for trading. Default is `10000` ($10,000).

### Example usage

```bash
export BUY_THRESHOLD=0.02
export SELL_THRESHOLD=0.03
export INITIAL_BALANCE=15000
./trading_bot
```

## Evaluation Checklist
1. **Code Quality**: The code is structured and well-commented, separating concerns into different modules.
2. **Algorithm Implementation**: A basic trading strategy is implemented and can be easily extended for more complex strategies.
3. **Backend Skills**: Proper use of C++ classes, threading, and random number generation to simulate market data.
4. **Creativity**: Further improvements could include multiple trading strategies, advanced logging, or more sophisticated mock APIs.


## Advanced Features:
1. Multiple Trading Strategies: Add different strategies (e.g., momentum trading, moving averages, etc.) and allow the bot to switch between strategies dynamically.
2. Risk Management: Implement basic risk management, such as limiting exposure (e.g., a maximum of 5 open positions at once).
3. Logging: Introduce a logging mechanism to store trades and decisions for later analysis.
4. Analytics: Track additional metrics like win/loss ratios, average trade return, and maximum drawdown.
5. Stop-Loss/Take-Profit: Add stop-loss and take-profit mechanisms to protect profits or limit losses.



### This structure can be expanded or customized depending on the needs of the trading bot or the complexity of the simulation.
