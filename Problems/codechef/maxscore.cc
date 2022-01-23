#include<iostream>
using namespace std;


int findMax(int **a,int s,int i)
{
    int max = a[i][0],col;
    for(int j = 0; j < s; j++)
        if(max < a[i][j])
        {

            max = a[i][j];
            col = j;
        }

    return col;
}

int main()
{

    int t,n,**a,**b,no;
    cin>>t;

    while(t--)
    {

        cin>>n;
        a = new int*[n];
        for(int i=0; i<n; i++)
            a[i] = new int[n];

        b = new int*[n];
        for(int i=0; i<n; i++)
            b[i] = new int[n];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                cin>>a[i][j];

            }

        for(int i=0; i<n; i++)
        {
            no = findMax(a,n,i); //send array,size of each row and  no. of row


        }
    }

    return 0;
}
