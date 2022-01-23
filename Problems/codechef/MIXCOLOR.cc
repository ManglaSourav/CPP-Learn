#include<iostream>
using namespace std;


int main()
{
    int t,n;

    cin>>t;
    int arr[50];
    while(t--)
    {
        cin>>n;
        int count=0;

        int a[n];
        for(int i=0; i<50; i++)
            arr[i]=0;
        for(int i=0; i<n; i++)
            cin>>a[i];
        for(int i = 0; i < n; i++)
            arr[a[i]]++;
        for(int i=0; i<n; i++)
        {
            if(arr[a[i]] > 1)
            {
                count += arr[a[i]]-1;
                arr[a[i]]--;
            }
        }
        cout<<count<<endl;

    }

    return 0;
}
