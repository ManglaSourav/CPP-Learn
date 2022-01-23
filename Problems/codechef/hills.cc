
#include<iostream>


using namespace std;


int main(){

int n,u,d,t;
cin>>t;

while(t--){
    int count = 0;
    int use_parachute = 1;
    cin>>n>>u>>d;
    int h[n];
    for(int i = 0; i < n; i++)
        cin>>h[i];

    for(int i = 0; i < n-1; i++){
        if(h[i] == h[i+1])
            count++;
        else if( (h[i] < h[i+1]) && (h[i]+u >= h[i+1]) )
            count++;
        else if(  (h[i] > h[i+1]) && (h[i]-d <= h[i+1]) )
            count++;
        else if( (h[i] > h[i+1]) && !(h[i]-d <= h[i+1]) && use_parachute == 1){
            count++;
            use_parachute--;
        }
        else
            break;
    }
    cout<<count+1<<endl;

}


return 0;
}
