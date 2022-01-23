//#include<bits/stdc++.h>
#include <iostream>
#include <math.h>

using namespace std;

int main() {


    long int n, t;
    cin >> n >> t;

    unsigned long a[n][32], p, c[32], b[32];
    for (long i = 0; i < n; i++) {
        cin >> p;
        for (long j = 31; j >= 0; j--) {
            if (i == 0) {
                a[i][j] = p % 2;
                p /= 2;
                c[j] = 0;
            }
            if (i != 0) {
                a[i][j] = p % 2 + a[i - 1][j];
                p /= 2;
                c[j] = 0;
            }
        }
    }

    while (t--) {
        int l, r;
        cin >> l >> r;

        for (long j = 31; j >= 0; j--) {
            if (l != 1)
                c[j] = a[r - 1][j] - a[l - 2][j];
            if (l == 1)
                c[j] = a[r - 1][j];
        }
        for (int j = 31; j >= 0; j--) {
            if (c[j] >= r - l + 1 - c[j])b[j] = 0;
            if (c[j] < r - l + 1 - c[j])b[j] = 1;
            c[j] = 0;
        }
        unsigned long sum = 0;
        p = 31;
        for (int i = 31; i >= 1; i--) {
            sum += pow(2, p - i) * b[i];
        }
        cout << sum << endl;
    }

    return 0;
}
