#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int p1,p2,k;
    while(t--)
    {
        cin>>p1>>p2>>k;
        if( ((p1+p2)/k) % 2 == 0)
            cout<<"CHEFF"<<endl;
        else
            cout<<"COOK"<<endl;
    }
    return 0;
}
