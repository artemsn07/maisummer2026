#include <iostream>
using namespace std;

int main() {
    long long cnt1, cnt2, x, y;
    cin >> cnt1 >> cnt2 >> x >> y;

    long long left = 1;
    long long right = 4000000000LL;

    while (left < right) {
        long long mid = (left + right) / 2;

        long long notX = mid - mid / x;
        long long notY = mid - mid / y;
        long long notBoth = mid - mid / (x * y);

        if (notX >= cnt1 && notY >= cnt2 && notBoth >= cnt1 + cnt2) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << left;

    return 0;
}