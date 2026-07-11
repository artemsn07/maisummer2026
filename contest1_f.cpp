#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;

    long long celayaSum = 0;
    long long drobSum = 0;

    long long base = 1000000000000000LL;

    while (cin >> s) {
        long long celaya = 0;
        long long drob = 0;

        int i = 0;

        while (s[i] != '.') {
            celaya = celaya * 10 + (s[i] - '0');
            i++;
        }

        i++;

        for (int j = 0; j < 15; j++) {
            drob = drob * 10 + (s[i] - '0');
            i++;
        }

        celayaSum = celayaSum + celaya;
        drobSum = drobSum + drob;
    }

    celayaSum = celayaSum + drobSum / base;
    drobSum = drobSum % base;

    cout << celayaSum << ".";

    long long p = base / 10;

    while (p > 0) {
        cout << drobSum / p;
        drobSum = drobSum % p;
        p = p / 10;
    }

    return 0;
}