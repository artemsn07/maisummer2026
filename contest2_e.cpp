#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long d[200000];

    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    sort(d, d + n);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        long long s, f;
        cin >> s >> f;

        long long l = min(s, f);
        long long r = max(s, f);

        int left = lower_bound(d, d + n, l) - d;
        int right = upper_bound(d, d + n, r) - d;

        cout << right - left << '\n';
    }

    return 0;
}