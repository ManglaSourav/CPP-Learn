#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int n, a, b, k;

    int count;
    while (t--)
    {
        cin >> n >> a >> b >> k;
        count = 0;

        for (int i = 1; i <= n; i++)
        {
            if (i % a == 0 && i % b != 0)

                count++;

            else if (i % b == 0 && i % a != 0)

                count++;
        }
        if (count >= k)
        {
            cout << "Win\n";
        }
        else
        {
            cout << "Lose\n";
        }
    }
    return 0;
}
