//
// Created by Sourav Mangla on 26/01/22.
//
#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestMountain(vector<int> &arr) {
        int n = arr.size();
        int largest = 0;
        for (int i = 1; i <= n - 2;) {

            if (arr[i - 1] < arr[i] && arr[i + 1] < arr[i]) { //at peak
                cout << "here";

                int count = 1; // 1 is for peak value
                // count backwards
                for (int j = i; j > 0;) {
                    if (arr[j] > arr[j - 1]) {
                        count++;
                        j--;
                    } else {
                        break;
                    }
                }
                //count forwards
                for (int j = i; j <= n - 2;) {
                    if (arr[j] > arr[j + 1]) {
                        count++;
                        j++;
                        i++;
                    } else {
                        break;
                    }
                }
                // check value is greater than largest of not
                if (count > largest) {
                    largest = count;
                }

            } else {
                i++;
            }
        }
        return largest;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 1, 4, 7, 3, 2, 5};
    cout << sol.longestMountain(arr);
}