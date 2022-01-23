#include<iostream>
using namespace std;


int main()
{

    int t,n,vote,sum;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        vote = 0;
        for(int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j<n; j++)
            {

                if(i == j)
                    continue;
                else if(j == i+1 || j == i-1)
                {
                    vote++;
                    continue;
                }
                sum = 0;

                //for(int x=0;x<n;x++)
                //    cout<<arr[x]<<endl;
                //cout<<endl;
                if(i>j)
                    for(int k = j+1; k < i; k++)
                    {
                        //cout<<"from if "<<a[k]<<" "<<k<<" ";
                        sum = sum + arr[k];
                        //cout<<" "<<a[k]<<" "<<k<<" "<<sum<<" ";
                    }
                else
                    for(int k = i+1; k < j; k++)
                    {
 //                       cout<<"from else\n";
                       //cout<<"from else "<<a[k]<<" "<<k<<" ";
                        sum = sum + arr[k];
   //                     cout<<" "<<sum<<" "<<a[k]<<" ";
                    }

                if(arr[j] >= sum)
                {
                    vote++;
                }
                if(arr[j] < sum && j > i)
                {
                    break;
                }
            }
            cout<<vote<<" ";
            vote = 0;
        }
        cout<<endl;
    }

    return 0;
}

