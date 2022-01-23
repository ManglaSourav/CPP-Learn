#include<iostream>
using namespace std;

int main(){

int t;
cin>>t;
int n;
while(t--){
    cin>>n;
    float a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int count = 0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){
        float k = (a[i]+a[j])/2;
        for(int z=0;z<n;z++)
        if(k == a[z]){
            count++;
            break;
        }
    }
    cout<<count<<endl;

}
return 0;
}





