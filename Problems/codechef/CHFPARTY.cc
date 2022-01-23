#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    int n;
    while (t--)
    {
        int count = 0;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a + n);
        if (a[0] == 0)
        {
            count++;
            for (int i = 1; i < n; i++)
            {
                if (a[i] <= count)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
        }
        cout << count << endl;
    }

    return 0;
}
