# Explanation: Best Time to Buy and Sell Stock (LeetCode 121)

## Problem Recap
We are given an array `prices` where `prices[i]` is the price of a stock on day `i`.  
We need to **maximize profit** by choosing:
- **One day to buy** the stock.
- **A later day to sell** it.

If no profit can be made, return `0`.

---

## Code

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX; // Store the minimum price seen so far
        int diff = 0;       // Temporary difference for current day
        int profit = 0;     // Maximum profit so far

        for (int i = 0; i < prices.size(); i++) {
            diff = prices[i] - mini;          // Possible profit if selling today
            profit = max(profit, diff);       // Update max profit
            mini = min(mini, prices[i]);      // Update minimum price
        }

        return profit;
    }
};
```

---

## How the Algorithm Works
1. We **track the minimum price** seen so far (`mini`).
2. On each day:
   - We calculate `diff = prices[i] - mini` (profit if we sell today).
   - We update the best `profit` so far.
   - We update `mini` if we find a lower price.
3. At the end, `profit` contains the **maximum profit possible**.

---

## Step-by-Step Diagram

Example: `prices = [3, 2, 6, 1, 4]`

| Day | Price | mini (so far) | diff (sell today) | profit (max so far) |
|-----|-------|---------------|-------------------|---------------------|
| 0   | 3     | 3             | 0                 | 0                   |
| 1   | 2     | 2             | -1                | 0                   |
| 2   | 6     | 2             | 4                 | 4                   |
| 3   | 1     | 1             | -1                | 4                   |
| 4   | 4     | 1             | 3                 | 4                   |

---

## Why This Line is Important
```cpp
mini = min(mini, prices[i]);
```

### Edge Case Example
```
prices = [3, 2, 6, 1, 4]
```
Without updating `mini` **before** calculating profit each day, you risk selling **before buying**.

If you instead used:
```cpp
if (prices[i] < mini) {
    mini = prices[i];
}
```
and placed it **after** profit calculation, the minimum might be updated **too late**, producing incorrect results.

---

## Why `int mini = prices[0]; for (int i = 2; ...)` Fails

If you start with:
```cpp
int mini = prices[0];
for (int i = 2; i < prices.size(); i++) { ... }
```
You **skip day 1 entirely**.

Example:
```
prices = [7, 1, 5]
```
You miss updating `mini` to `1` before checking later days → wrong profit.

---

## Why `INT_MAX` Works Best
By starting with:
```cpp
int mini = INT_MAX;
```
We ensure:
- Any price will be smaller than `mini` initially.
- We can track the minimum price **from the first day** without skipping.

---

## Complexity
- **Time Complexity**: `O(n)` — one pass through `prices`.
- **Space Complexity**: `O(1)` — constant extra memory.

---

## Key Takeaway
Always:
- Track the **minimum price so far**.
- Update `profit` after checking all possible sell days.
