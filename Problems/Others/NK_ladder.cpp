#include<iostream>
#include<vector>

using namespace std;

int NK_ladder_recursive(int n, int k) {
// O(n^k)
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 0;
    }
    int ans = 0;
    for (int jump = 1; jump <= k; jump++) {
        ans += NK_ladder_recursive(n - jump, k);
    }

    return ans;

}

// O(n*k)
int NK_ladder_Top_Down(int n, int k, vector<int> state) {

    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 0;
    }

    if (n < state.size()) {
        return state[n];
    }
    int ans = 0;
    for (int jump = 1; jump <= k; jump++) {
        ans += NK_ladder_Top_Down(n - jump, k, state);
    }
    state.push_back(ans);
    return ans;

}


// O(n*k)
int NKLadder_bottomup(int n, int k) {

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int jump = 1; jump <= k; jump++) {
            if (i - jump >= 0) {
                dp[i] += dp[i - jump];
            }
        }
    }
    return dp[n];

}

// O(n+k)
int NKLadder_optimised(int n, int k) {

    vector<int> dp(n + 1, 0);

    dp[0] = dp[1] = 1;
    for (int i = 2; i <= k; i++) {
        dp[i] = 2 * dp[i - 1];
    }
    for (int i = k + 1; i <= n; i++) {
        dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
    }

    return dp[n];

}

int main() {
    vector<int> state;
    int n = 4, k = 3;
    cout << NK_ladder_recursive(n, k) << endl;
    cout << NK_ladder_Top_Down(n, k, state) << endl;
    cout << NKLadder_bottomup(n, k) << endl;
    cout << NKLadder_optimised(n, k) << endl;
    return 0;
}


