//
// Created by Sourav Mangla on 09/04/22.
//

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;


int fib_recursive(int n) {

    if (n <= 1) {
        return n;
    }
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}


/**
The memoized program for a problem is similar to the recursive version with a small modification that looks into a
 lookup table before computing solutions. We initialize a lookup array with all initial values as NIL.
 Whenever we need the solution to a subproblem, we first look into the lookup table. If the precomputed value is
 there then we return that value, otherwise, we calculate the value and put the result in the lookup table so that it
 can be reused later.
 */

int fib_memoization(int n, int *dp) {

    if (n <= 1) {
        return n;
    }
    if (dp[n] != 0) {
        return dp[n];
    }
    return dp[n] = fib_memoization(n - 1, dp) + fib_memoization(n - 2, dp);
}


/**
 The tabulated program for a given problem builds a table in a bottom-up fashion and
 returns the last entry from the table. For example, for the same Fibonacci number,
 we first calculate fib(0) then fib(1) then fib(2) then fib(3), and so on. So literally,
 we are building the solutions of subproblems bottom-up.
 */
int fib_tabulation(int n) {

    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
//        cout << " " << dp[i] << " ";
    }
//    cout << sizeof(dp) / sizeof(*dp) << endl;

    return dp[n];
}

int main() {
    int dp[100] = {0};

    auto start = high_resolution_clock::now();
    cout << fib_recursive(10) << endl; //55
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by recursive function: "
         << duration.count() << " microseconds" << endl;


    start = high_resolution_clock::now();
    cout << fib_memoization(10, dp) << endl; //55
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by memoized function: "
         << duration.count() << " microseconds" << endl;


    start = high_resolution_clock::now();
    cout << fib_tabulation(10) << endl; //55
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by tabular function: "
         << duration.count() << " microseconds" << endl;


    return 0;
}