#include <iostream>
using namespace std;

int main() {
    long long n;
    int k;

    cin >> n;
    cin >> k;

    long long step = 1;

    for (int i = 0; i < k; i++) {
        step = step * 2;
    }

    if (step > n) {
        cout << -1;
        return 0;
    }

    long long x = n / step;

    if (x % 2 == 0) {
        x = x - 1;
    }

    if (x <= 0) {
        cout << -1;
    } else {
        cout << x * step;
    }

    return 0;
}