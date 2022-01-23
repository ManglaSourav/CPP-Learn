#include<iostream>
#include<iomanip>

using namespace std;



int main()
{

    int t;
    int n;
    cin>>t;

    while(t--)
    {
        cin>>n;
        double loss = 0;
        int arr[3];

        for(int j=0; j< n; j++)
        {
            for(int i=0; i<=2; i++)
            cin>>arr[i];
            double priceInc  = arr[0] + (double)arr[0]*arr[2]/100;
            double priceDec  = (double)priceInc*arr[2]/100;
            loss += arr[1]*(arr[0] - (priceInc - priceDec));
        }

        cout<<setprecision(20)<<loss<<endl;
    }
    return 0;
}
