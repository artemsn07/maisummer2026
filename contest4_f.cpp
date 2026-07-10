#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;

    cin >> n >> k;

    long long a[200001];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    long long answer = 0;

    int left = 0;

    for (int right = 0; right < n; right++) {
        while (a[right] - a[left] > k) {
            left++;
        }

        long long count = right - left;

        if (count >= 2) {
            answer = answer + count * (count - 1) / 2;
        }
    }

    cout << answer;

    return 0;
}