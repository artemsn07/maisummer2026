#include <iostream>
using namespace std;

long long dp[20000001];

int main() {
    int n;
    cin >> n;

    dp[1] = 0;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + i;

        if (i % 2 == 0) {
            if (dp[i / 2] + i < dp[i]) {
                dp[i] = dp[i / 2] + i;
            }
        }

        if (i % 3 == 0) {
            if (dp[i / 3] + i < dp[i]) {
                dp[i] = dp[i / 3] + i;
            }
        }
    }

    cout << dp[n];

    return 0;
}