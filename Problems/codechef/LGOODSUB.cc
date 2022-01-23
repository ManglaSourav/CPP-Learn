#include<iostream>
using namespace std;

int findLarge(int a[], int len, int startingIndex) //max length = 2
{
    int subLen = len-1;
    int subA[subLen], subB[subLen];
    if(len > 2)
    {
        int j = 0;
        for(int i = startingIndex; i < len-1; i++,j++)
        {
            subA[j] = a[i];
        }

        j = 0;
        for(int i = startingIndex+1; i < len; i++,j++)
        {
            subB[j] = a[i];
        }


         for(int i=0; i<subLen; i++)
         {
             cout<<subA[i];
         }
         cout<<endl;
        for(int i=0; i<subLen; i++)
         {
             cout<<subB[i];
         }
         cout<<endl;
         cout<<subLen<<endl;

        if(subA[0] >= subA[subLen-1])
        {
            return subLen;
        }
        else if(subB[0] >= subB[subLen-1])
        {
            return subLen;
        }
        else
        {   int maxi = max(findLarge(subA,subLen,0),findLarge(subB,subLen,0));
            return maxi;
        }

    }
    else if(len == 2)
    {
        if(a[startingIndex]>a[startingIndex+1])
            return 2;
    }
    else
    {
        return -1;
    }

}

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        if(a[0]>=a[n-1])
        {
            cout<<n<<endl;
            continue;
        }

        int maxi = findLarge(a,n,0);
        cout<<maxi<<endl;
        /*        int countA = 0, countB = 0;

                for(int i = 0; i < n; i++)
                {
                    if(a[i] >= a[n-1] && i+1 > countA)
                    {
                        countA=i+1;
                    }
                }
                for(int i = n-1; i >= 0; i--){

                    if(a[i] <= a[0] && countB > i){

                        countB = i;
                    }
                }
                if(countA>countB)
                    cout<<countA<<endl;
                else
                    cout<<countB<<endl;
                    */

    }
    return 0;
}
