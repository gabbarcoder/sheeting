#include <iostream>
#include <vector>

using namespace std;

int knapsack(int W, const vector<int> &wt, const vector<int> &val)
{
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int w = 1; w <= W; ++w)
        {
            if (wt[i - 1] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main()
{
    int W = 10;                     // Knapsack capacity
    vector<int> wt = {2, 3, 4, 5};  // Weight of items
    vector<int> val = {3, 4, 5, 6}; // Value of items

    int result = knapsack(W, wt, val);
    cout << "Maximum value: " << result << endl;

    return 0;
}
