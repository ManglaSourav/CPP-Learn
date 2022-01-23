#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        int n;
        cin>>n;

        int station = 1,time = 1,count=1;
        int a,b;
        while(true)
        {

            if(n > station)
            {
                count++;
                a=station;
                station+=count;

                b=station;
                if((b+a)/2 >= n){
                    time += n-a;
                  break;
                }
                time++;

            }
            else if(n == station)
            {
                break;
            }
            else
            {
                time += b - n;
                break;
            }
        }
        cout<<time<<endl;

    }


    return 0;
}
