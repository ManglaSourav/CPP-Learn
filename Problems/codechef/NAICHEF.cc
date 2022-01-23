#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        int x[n];
        for(int i=0; i<n; i++)
            cin>>x[i];

        float countA = 0.0;
        float countB = 0.0;
        for(int j = 0; j < n; j++)
        {
            if(x[j] == a)
            {
                countA++;
            }
            if(x[j] == b)
            {
                countB++;
            }
        }

        float result = countA*countB/(n*n);
        cout<<fixed<<showpoint<<result<<setprecision(10)<<endl;
    }
}
