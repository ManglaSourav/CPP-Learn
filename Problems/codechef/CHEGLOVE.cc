#include<iostream>
using namespace std;

int main()
{

    int t,n,lc,rc;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int f[n],s[n];
        lc = 0;
        rc = 0;

        for(int i=0; i<n; i++)
            cin>>f[i];
        for(int i=0; i<n; i++)
            cin>>s[i];

        for(int i=0; i<n; i++)
            if(f[i]<=s[i])
                lc++;
            else
                break;

        for(int i=0; i<n; i++)
            if(f[i]<=s[n-i-1])
                rc++;
            else
                break;

        if((lc == n) && (rc == n))
            cout<<"both"<<endl;
        else if(lc == n)
            cout<<"front"<<endl;
        else if(rc == n)
            cout<<"back"<<endl;
        else
            cout<<"none"<<endl;
    }


    return 0;
}
