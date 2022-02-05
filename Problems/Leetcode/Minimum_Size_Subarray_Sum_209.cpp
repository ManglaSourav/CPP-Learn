#include "iostream";
#include "vector";

using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums, int target) {
        int left = 0, right = 0;
        int sum = 0;
        int result = INT_MAX;

        while (right < nums.size()) {
            sum += nums[right];
            while (sum >= target) {
                result = min(result, right + 1 - left);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return result == INT_MAX ? 0 : result;
    }
};


int main() {

    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 11;
    Solution soln;
    cout << soln.subarraySum(nums, k);
    return 0;

}
