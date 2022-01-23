#include<iostream>
using namespace std;


int main(){
int test;

cin>>test;


while(test--){
  int n;
  cin>>n;
  int a[n];

  for(int i=0;i<n;i++)
        cin>>a[i];
  for(int i=0;i<n;i++){
    if(a[i]%10 == 7){}
    else{
        cout<<a[i]<<" ";
    }
  }
    cout<<endl;




}

return 0;
}
