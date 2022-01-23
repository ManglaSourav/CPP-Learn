#include<iostream>

using namespace std;


int main()
{

    int t;
    cin>>t;
    int a[5],count;

    while(t--)
    {    count = 0;
        for(int i = 0; i < 5; i++)
          cin>>a[i];
        for(int i = 0; i < 5; i++)
          if( a[i] == 1)
            count++;
        if(count == 0)
            cout<<"Beginner\n";
        else if(count == 1)
            cout<<"Junior Developer\n";
        else if(count == 2)
            cout<<"Middle Developer\n";
        else if(count == 3)
            cout<<"Senior Developer\n";
        else if(count == 4)
            cout<<"Hacker\n";
        else if(count == 5)
            cout<<"Jeff Dean\n";

    }

}
