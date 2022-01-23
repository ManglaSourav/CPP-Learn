#include<algorithm>
#include<iostream>

using namespace std;
int main()
{
    int testcase;
    cin>>testcase;
    string s;
    int n;
    while(testcase--)
    {

        cin>>s;
        cin>>n;
        string str;
        for(int i = 0; i<n; i++)
            str += s;
        int c = 0;
        for(int i = 0; i < str.size(); i++)
        {
            string a;
            a.assign(str,0,i+1);
            if( count(a.begin(), a.end(), 'a') > count(a.begin(), a.end(), 'b'))
            {
                c++;
            }
        }
        cout<<c<<endl;

    }

}
