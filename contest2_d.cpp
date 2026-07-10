#include <iostream>
#include <algorithm>
using namespace std;

struct BlackHole {
    long long mass;
    int number;
};

bool cmp(BlackHole a, BlackHole b) {
    return a.mass < b.mass;
}

int main() {
    int n;
    long long omega;

    cin >> n >> omega;

    BlackHole a[200000];

    for (int i = 0; i < n; i++) {
        cin >> a[i].mass;
        a[i].number = i + 1;
    }

    sort(a, a + n, cmp);

    for (int i = 0; i < n; i++) {
        if (omega <= a[i].mass) {
            cout << "NO";
            return 0;
        }

        omega = omega + a[i].mass;
    }

    cout << "YES" << endl;

    for (int i = 0; i < n; i++) {
        cout << a[i].number << " ";
    }

    return 0;
}