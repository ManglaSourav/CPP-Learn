#include<iostream>
using namespace std;


int main()
{
    int t;
    int d[31];
    d[0]=0;
    d[1]=1;
    d[2]=2;
    cin>>t;
    for(int i=3;i<=30;i++){
    d[i]=2*d[i-1]+1;
    }
    int n,m;
    while(t--)
    {
        cin>>n>>m;
        int a[n];
        int c = 0;
        for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%m==0)
            c++;
        }
        cout<<d[c]<<endl;

    }


    return 0;
}
