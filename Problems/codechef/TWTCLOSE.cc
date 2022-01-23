//#include<bits/stdc++.h>
#include "iostream"

using namespace std;

void set0(int t[], int n) {
    int i;
    for (i = 1; i <= n; i++)
        t[i] = 0;
    cout << "0" << endl;
}

void inv(int t[], int n, int temp) {
    if (t[temp] == 0)
        t[temp] = 1;
    else
        t[temp] = 0;
    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (t[i] == 1)
            c++;
    }
    cout << c << endl;
}

int main() {
    int n, k;
    cin >> n >> k;
    int i, temp;
    string s;
    int t[n + 1] = {0};
    for (i = 0; i < k; i++) {
        cin >> s;
        if (s.length() == 8) {
            set0(t, n);
            continue;
        } else {
            cin >> temp;
            inv(t, n, temp);
        }
    }
    return 0;
}
