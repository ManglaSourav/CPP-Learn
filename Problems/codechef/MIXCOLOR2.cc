#include<iostream>
#include <set>
using namespace std;

int main()
{
    int a[] = { 1, 9, 4, 5, 8, 3, 1, 3, 5 };

    int t;
    cin>>t;
    int n;

    while(t--){

    cin>>n;
    int a[n];

    for(int i=0;i<n;i++)
        cin>>a[i];

    set<int> sa(a, a + n);
    cout << n - sa.size() << endl;


    }

}
