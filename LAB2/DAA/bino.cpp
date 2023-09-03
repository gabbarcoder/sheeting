#include <iostream>
#include <vector>

using namespace std;

int binomialCoefficient(int n, int k) {
    vector<int> dp(k + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = min(i, k); j > 0; --j) {
            dp[j] += dp[j - 1];
        }
    }

    return dp[k];
}

int main() {
    int n, k;

    cout << "Enter the values of n and k: ";
    cin >> n >> k;

    if (n < 0 || k < 0 || k > n) {
        cout << "Invalid input. n and k should be non-negative, and k should be less than or equal to n." << endl;
    } else {
        int result = binomialCoefficient(n, k);
        cout << "Binomial Coefficient C(" << n << ", " << k << ") = " << result << endl;
    }

    return 0;
}
