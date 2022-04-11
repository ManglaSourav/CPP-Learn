//
// Created by Sourav Mangla on 11/04/22.
//
#include "iostream";

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {

        int uglyNumbers[n];
        uglyNumbers[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        int two_multiple = 2;
        int three_multiple = 3;
        int five_multiple = 5;
        int next = 1;
        for (int i = 1; i < n; i++) {
            next = min(two_multiple, min(three_multiple, five_multiple));
            uglyNumbers[i] = next;
            if (next == two_multiple) {
                i2++;
                two_multiple = uglyNumbers[i2] * 2;
            }
            if (next == three_multiple) {
                i3++;
                three_multiple = uglyNumbers[i3] * 3;
            }
            if (next == five_multiple) {
                i5++;
                five_multiple = uglyNumbers[i5] * 5;
            }
        }
        return next;
    }
};


int main() {
    Solution s1;
    cout << s1.nthUglyNumber(150);
    return 0;
}