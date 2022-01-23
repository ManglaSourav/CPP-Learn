#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, b;
        cin >> n >> b;
        int w, h, p;
        int area = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> w >> h >> p;
            if (p <= b)
            {
                // cout << area << "  ";
                if (area < w * h)
                {
                    area = w * h;
                }
            }
        }
        if (area != 0)
            cout << area << endl;
        else
            cout << "no tablet" << endl;
    }
    return 0;
}