#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int n,k;
    while(t--)
    {
        cin>>n>>k;
        int a[n];

        for(int i=0; i<n; i++)
            cin>>a[i];
        int steps = 0;
        for(int i = 1; i < n;i++)
        {
            if(a[i] - a[i-1] <= k)
            {
                continue;
            }else{

             if((a[i] - a[i-1])%k == 0)
             steps += (a[i] - a[i-1])/k-1;
             else
             steps += (a[i] - a[i-1])/k;
            }
        }
        cout<<steps<<endl;
    }
}
