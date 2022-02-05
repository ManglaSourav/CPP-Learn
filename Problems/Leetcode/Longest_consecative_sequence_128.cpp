//
// Created by Sourav Mangla on 26/01/22.
//
#include<iostream>
#include<vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        int largest = 1;
        unordered_set<int> set;
        for (int x: nums) {
            set.insert(x);
        }
        for (auto element: set) {
//            cout << element << endl;
            int parent = element - 1;
            //check for head : lets say for 1 we are checking if 0 is present it means 1 is not head.
            if (set.find(parent) == set.end()) {
                int count = 1;
                int next = element + 1;
                while (set.find(next) != set.end()) {
                    next++;
                    count++;
                }
                if (count > largest) {
                    largest = count;
                }

            }


        }

        return largest;
    }
};

int main() {
    Solution soln;
    vector<int> arr = {1, 9, 3, 0, 18, 5, 2, 10, 7, 12, 6};
    cout << soln.longestConsecutive(arr);
    return 0;
}