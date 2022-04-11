
#include<iostream>
#include "vector"

using namespace std;

int test() {
    return 15;
}

int main() {
    cout << "Vector Demo" << endl;
    vector<int> vec;
    cout << vec.size() << endl;

    vec.push_back(14);
    cout << vec.front();

    auto val = test();
    cout << endl << val;
    return 0;
}

