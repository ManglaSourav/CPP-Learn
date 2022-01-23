
#include<iostream>
using namespace std;

int main(){

int n;
cin>>n;
int a[2][n];

for(int i = 0; i < n; i++)
    cin>>a[0][i];

for(int i = 0; i < n; i++)
    cin>>a[1][i];

int min = a[0][0];
int index;
for(int i = 1; i < n; i++){
    if(a[0][i] < min){
        min = a[0][i];
        index = i;
    }
}
if(a[1])
return 0;
}



