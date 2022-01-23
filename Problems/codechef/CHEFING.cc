#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    int countGrad;
    string sub;
    while (t--)
    {
        std::unordered_set<char> log;
        countGrad = 0;
        cin >> n;
        string str[n];
        for (int i = 0; i < n; i++)
        {
            cin >> str[i];
        }
        int j;
        bool flag;
        int count;
        sub = str[0];
        sub.erase(std::remove_if(sub.begin(), sub.end(), [&](char const c) { return !(log.insert(c).second); }), sub.end());
        str[0] = sub;
        for (int i = 0; i < str[0].length(); i++)
        {
            j = 1;
            count = 0;
            while (j < n)
            {
                flag = false;
                for (int k = 0; k < str[j].length(); k++)
                {
                    if (str[0].at(i) == str[j].at(k))
                    {
                        flag = true;
                    }
                }
                if (flag == true)
                {
                    count++;
                    // cout << "jth " << j << " count " << count << " ";
                }
                // cout << endl;
                j++;
            }
            if (count == n - 1)
            {
                countGrad++;
            }
        }
        cout << countGrad << endl;
    }
    return 0;
}