#include<iostream>
#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n],d[n],b[k],tc[10000];

        for(int i = 0; i < n; i++)
            cin>>a[i];
        for(int i = 0; i < n; i++)
            cin>>d[i];

        for(int i = 0; i < k; i++)
            cin>>b[i];
        sort(a,a+4);


        int index = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < d[i]; j++ )
            {
                tc[index] = a[i];
                index++;
            }
        }
        int start_index = 0;
        for(int i = 0; i < k; i++) //k rounds
        {

            if(i%2 == 0) //chef turns
            {
                start_index = index - b[i];

            }
            else
            {
                index = start_index+b[i];
            }
        }

        int sum=0;
        for(int i = start_index; i<index; i++)
        {
            sum += tc[i];
        }
        cout<<sum<<endl;

    }

    return 0;
}
