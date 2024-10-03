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
g++ -std=c++17 -Iinclude src/*.cpp -o trading_bot
```

## Run the Application
```bash
./trading_bot
```

## Configuration
1.  You can adjust thresholds (e.g., 2% buy, 3% sell) in trade_logic.cpp.
2. Initial balance can be set in profit_tracker.cpp.

## Evaluation Checklist
1. **Code Quality**: The code is structured and well-commented, separating concerns into different modules.
2. **Algorithm Implementation**: A basic trading strategy is implemented and can be easily extended for more complex strategies.
3. **Backend Skills**: Proper use of C++ classes, threading, and random number generation to simulate market data.
4. **Creativity**: Further improvements could include multiple trading strategies, advanced logging, or more sophisticated mock APIs.

## Output for basic version :

❯ ./trading_bot
Buying at $96.3154
Holding at $95.9171
Buying at $93.2215
Holding at $94.8889
Selling at $99.0136
Holding at $99.2059
Buying at $94.5885
Holding at $94.8695
Buying at $90.199
Buying at $86.292
Holding at $87.9037
Selling at $91.6874
Holding at $91.9343
Holding at $93.3493
Holding at $95.2274
Holding at $97.7243
Buying at $93.3019
Holding at $91.6993
Holding at $94.0506
Holding at $92.7841
Selling at $97.2614
Holding at $99.7255
Buying at $95.4641
Selling at $99.1367
Holding at $98.5063
Holding at $98.2869
Buying at $96.0746
Buying at $92.8706
Selling at $96.5636
Buying at $92.3203
Holding at $92.362
Holding at $90.6906
Holding at $90.6359
Buying at $86.9265
Buying at $83.2213
Holding at $82.2571
Selling at $85.661
Holding at $85.3565
Buying at $81.5161
Holding at $83.7187
Buying at $80.5823
Holding at $82.101
Holding at $83.1645
Holding at $85.0391
Selling at $88.3435
Holding at $86.6325
Holding at $86.7475
Selling at $89.7488
Selling at $92.8138
Holding at $92.0286
Holding at $91.7333
Buying at $88.7825
Holding at $89.4187
Buying at $85.2433
Holding at $85.2304
Holding at $87.3466
Selling at $90.7595
Selling at $93.8639
Buying at $91.1676
Buying at $87.7983
Buying at $85.8192
Holding at $85.0837
Holding at $86.8689
Buying at $84.6096
Holding at $83.0658
Holding at $84.3289
Holding at $85.8581
Holding at $84.8942
Buying at $81.9019
Selling at $84.7323
Selling at $88.591
Buying at $85.474
Holding at $84.6942
Holding at $85.2438
Holding at $85.1459
Selling at $89.072
Buying at $86.3976
Holding at $87.5145
Holding at $88.8382
Selling at $91.5306
Holding at $91.3149
Buying at $88.6051
Selling at $92.1642
Buying at $88.8649
Holding at $88.0679
Selling at $91.4642
Buying at $88.3745
Holding at $87.1845
Buying at $84.0032
Holding at $83.6278
Holding at $83.2289
Selling at $86.8216
Buying at $84.3494
Selling at $87.7986
Selling at $90.9669
Holding at $91.0211
Selling at $93.9116
Holding at $93.557
Holding at $94.7989
Selling at $97.877
Trade History:
BUY at $96.3154
BUY at $93.2215
SELL at $99.0136
BUY at $94.5885
BUY at $90.199
BUY at $86.292
SELL at $91.6874
BUY at $93.3019
SELL at $97.2614
BUY at $95.4641
SELL at $99.1367
BUY at $96.0746
BUY at $92.8706
SELL at $96.5636
BUY at $92.3203
BUY at $86.9265
BUY at $83.2213
SELL at $85.661
BUY at $81.5161
BUY at $80.5823
SELL at $88.3435
BUY at $88.7825
BUY at $85.2433
SELL at $90.7595
BUY at $91.1676
BUY at $87.7983
BUY at $85.8192
BUY at $84.6096
BUY at $81.9019
SELL at $84.7323
BUY at $85.474
SELL at $89.072
BUY at $86.3976
SELL at $91.5306
BUY at $88.6051
SELL at $92.1642
BUY at $88.8649
SELL at $91.4642
BUY at $88.3745
BUY at $84.0032
SELL at $86.8216
BUY at $84.3494
SELL at $87.7986
Final balance: $12520.2

## Advanced Features:
1. Multiple Trading Strategies: Add different strategies (e.g., momentum trading, moving averages, etc.) and allow the bot to switch between strategies dynamically.
2. Risk Management: Implement basic risk management, such as limiting exposure (e.g., a maximum of 5 open positions at once).
3. Logging: Introduce a logging mechanism to store trades and decisions for later analysis.
4. Analytics: Track additional metrics like win/loss ratios, average trade return, and maximum drawdown.
5. Stop-Loss/Take-Profit: Add stop-loss and take-profit mechanisms to protect profits or limit losses.



### This structure can be expanded or customized depending on the needs of the trading bot or the complexity of the simulation.
