#include<iostream>

using namespace std;


void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main()
{
    int n;
    cin>>n;

    int coin[n],worker[n];
    for(int i = 0; i < n; i++)
        cin>>coin[i];
    for(int i = 0; i < n; i++)
        cin>>worker[i];


    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (coin[j] > coin[j+1])
            {
                swap(&coin[j], &coin[j+1]);
                swap(&worker[j], &worker[j+1]);

            }


    if(worker[0] == 3)
        cout<<coin[0]<<endl;
    else  if(worker[1] == 3)
        cout<<coin[1]<<endl;
    else{
        int s = worker[0];
        int sum = coin[0];
        int i = 1;
        while(s == worker[i])
            i++;
        if(worker[i] == 3)
            cout<<coin[i]<<endl;
        else
            cout<<coin[i]+sum<<endl;
    }

    return 0;
}
