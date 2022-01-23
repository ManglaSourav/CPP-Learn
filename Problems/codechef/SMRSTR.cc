#include<iostream>
using namespace std;


int main()
{

    int testCase;

    int n,q;
    cin>>testCase;
    while(testCase--)
    {

        cin>>n>>q;
        int d[n],x[q];

        for(int i=0; i<n; i++)
            cin>>d[i];

        for(int i=0; i<q; i++)
            cin>>x[i];



        for(int i=0; i < q; i++)
        {
            int temp = x[i];

            for(int j = 0; j < n; j++)
            {
                temp /= d[j];
            }
            cout<<temp<<" ";
        }
        cout<<endl;

    }
    return 0;
}
