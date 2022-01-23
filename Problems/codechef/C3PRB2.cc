#include<iostream>
#include<cmath>

using namespace std;


float findE(int xi, int yi, int xj, int yj){
float result = sqrt(pow((xi-xj), 2) + pow((yi-yj), 2));
return result;
}
float findM(int xi, int yi, int xj, int yj){

float result = abs(xi-xj)+abs(yi-yj);
}
int main(){

float *x,*y;
int n,count = 0 ;
cout<<"Input:\n";
cin>>n;

x = new float[n];
y = new float[n];

for(int i = 0; i < n; i++)
    cin>>x[i]>>y[i];

for(int i = 0; i < n; i++)
for(int j = i+1; j < n; j++)
if(findE(x[i],y[i],x[j],y[j]) == findM(x[i],y[i],x[j],y[j])){
    count++;
}
cout<<"Output:\n";
cout<<count<<endl;
return 0;
}
