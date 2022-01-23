
#include<iostream>
using namespace std;
 int main(){
 int t;
 cin>>t;
 int n;
 while(t--){

    cin>>n;
    int a[n],b[n];

    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];

     int maxa=a[0],ai=0;
     int maxb=b[0],bi=0;
     for(int i=0;i<n;i++){
        if(maxa<a[i]){
            maxa=a[i];
            ai=i;
        }
        if(maxb<b[i]){
            maxb=b[i];
            bi=i;
        }
     }
     a[ai]=0;
     b[bi]=0;
     int suma=0,sumb=0;
     for(int i=0;i<n;i++){
        suma+=a[i];
        sumb+=b[i];
     }

     if(suma>sumb)
        cout<<"Bob\n";
     else if(suma<sumb)
        cout<<"Alice\n";
     else
        cout<<"Draw\n";
 }


 return 0;
 }
