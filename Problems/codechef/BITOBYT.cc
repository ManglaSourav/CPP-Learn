#include<iostream>
using namespace std;

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        n = n%16;
        if(n == 0)
            cout<<"0 0 1"<<endl;
        else if(n<=2)
            cout<<"1 0 0"<<endl;
        else if(n<=8)
            cout<<"0 1 0"<<endl;
        else
            cout<<"0 0 0"<<endl;

    }
    return 0;
}
