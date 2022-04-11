//
// Created by Sourav Mangla on 27/01/22.
//

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {

        int n = height.size();
        int total_water = 0;
        if (n <= 2) {
            return total_water;
        }

        vector<int> left(n, 0);
        left[0] = height[0];
        vector<int> right(n, 0);
        right[n - 1] = height[n - 1];

        for (int i = 1; i <= n - 1; i++) {
            left[i] = max(left[i - 1], height[i]); //filling left side
            right[n - i - 1] = max(right[n - i], height[n - i - 1]); // fill right array

        }

        //other wat to fill the right side
//        for (int i = n - 2; i >= 0; i--) {
//            right[i] = max(right[i + 1], height[i]);
//        }

        for (int i = 0; i <= n - 1; i++) {
            total_water += min(left[i], right[i]) - height[i];
        }

        return total_water;
    }
};


int main() {
    vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution soln;
    cout << soln.trap(heights);
    return 0;
}