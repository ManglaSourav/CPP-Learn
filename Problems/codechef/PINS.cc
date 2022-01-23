//#include<bits/stdc++.h>
#include "iostream";
#include "math.h"

using namespace std;

int main() {

    int t;
    cin >> t;
    int n;
    while (t--) {
        cin >> n;
        int pin = floor((n + 1) / 2);
        cout << "1 ";

        //cout<<pin;
        for (int i = 0; i <= n - pin; i++) {
            if (i == 0)
                cout << "1";
            else
                cout << "0";
        }

        cout << endl;
    }
    return 0;
}

