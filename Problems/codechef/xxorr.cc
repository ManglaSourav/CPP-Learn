
#include<iostream>
#include<cmath>
using namespace std;
int binary[100000][32];
int prefixsum[100000][32];
void initialize(int n)
{
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<32;j++)
		{
			binary[i][j] = 0;
		}
	}
}
void converttobinary(long long int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		int j=0;
		while(a[i] > 0)
		{
			binary[i][j] = a[i]%2;
			a[i] = a[i]/2;
			j++;
		}
	}
}
/* To reduce Time complexity of repetitive calculation of Number of 1 and 0 in range L to R*/
void calculateprefixsum(int n)
{
	for(int i=0;i<32;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j == 0)
			{
				prefixsum[j][i] = binary[j][i];
			}
			else
			{
				prefixsum[j][i] = binary[j][i] + prefixsum[j-1][i];
			}
		}
	}
}
int main()
{
	int n,q,l,r;
	long long int a[100000],b[100000],ans,count1,count0;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i] = a[i];
	}
	initialize(n);
	converttobinary(b,n);
	calculateprefixsum(n);
	for(int i = 0; i<n;i++){
        for(int j = 0; j<10;j++)
        cout<<binary[i][j];
        cout<<" ";
        for(int k = 0;  k < 10;k++)
        cout<<prefixsum[i][k];
        cout<<endl;

	}
	// for(int i=0;i < n;i++)
	// {
	// 	for(int j=0;j<32;j++)
	// 	{
	// 		cout<<binary[i][j];
	// 	}
	// 	cout<<endl;
	// }
	// cout<<endl;
	// for(int i=0;i < n;i++)
	// {
	// 	for(int j=0;j<32;j++)
	// 	{
	// 		cout<<prefixsum[i][j];
	// 	}
	// 	cout<<endl;
	// }
	/*while(q--)
	{
		ans = 0;
		cin>>l>>r;
		for(int i = 0;i<31;i++)
		{
			if(binary[l-1][i] == 1 ) //If there is one at l position in binary array. Then Number of 1 increases by 1.
			{
				count1 = prefixsum[r-1][i] - prefixsum[l-1][i] + 1;
				// cout<<"in 1\n";
			}
			else
			{
				count1 = prefixsum[r-1][i] - prefixsum[l-1][i];
				// cout<<"in 2\n";
			}
			count0 = r-l+1 - count1;
			// cout<<count0<<" "<<count1<<endl;
			if(count1 < count0)
			{
				ans = ans + pow(2,i);
				// cout<<ans<<endl;
			}
		}
		cout<<ans<<endl;
	}*/
}
