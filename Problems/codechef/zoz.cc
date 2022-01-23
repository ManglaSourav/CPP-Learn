#include<iostream>
using namespace std;


int main(){
int t;
cin>>t;
int n,k;

while(t--){

    cin>>n>>k;
    int a[n];

    for(int i=0; i<n;i++)
        cin>>a[i];

    int count = 0;
    for(int i = 0; i < n; i++){
     int sum = a[i]+k;
     int sumA = 0;
     for(int j = 0; j < n; j++)
       if(i!=j)
       sumA += a[j];
     if(sum > sumA)
        count++;
    }
    cout<<count<<endl;



}

return 0;
}
