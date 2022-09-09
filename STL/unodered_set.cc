#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    string str;
    cin >> str;
    std::unordered_set<char> log;
    str.erase(
            std::remove_if(
                    str.begin(),
                    str.end(),
                    [&](char const c) { return !(log.insert(c).second); }
            ),
            str.end());
    std::cout << str;
    return 0;
}
