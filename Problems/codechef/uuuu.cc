
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        ll a[n] = {'\n'};
        ll d[n] = {'\n'};
        ll b[k] = {'\n'};
        for(ll i=0; i<n; i++){
            cin>>a[i];
        }

        for(ll i=0; i<n; i++){
            cin>>d[i];
        }

        for(ll i=0; i<k; i++){
            cin>>b[i];
        }
        ll l = 0;

        for(ll i=0; i<n; i++){
            l += d[i];
        }

        ll z = 0;
        ll e[100000] = {'\n'};
        for(ll i=0; i<n; i++){
            while(d[i] != 0){
                e[z] = a[i];

                    z++;

                --d[i];

                if(z == l){
                    e[z] = '\n';
                    break;
                }
            }

        if(z == l){

            break;
        }
        }

        e[l] = '\n';
            sort(e, e+l);
            e[l] = '\n';

        ll x = 0;
        ll y = l-1;
            for(ll i=0; i<k; i++){
            if(i%2 == 0){
                x = y - b[i] + 1;
            }else{
                y = x + b[i] - 1;
            }
        }

        ll s = 0;
        for(ll i = x; i<=y; i++){
            s += e[i];
        }

        cout<<s<<"\n";

    }
return 0;
}
