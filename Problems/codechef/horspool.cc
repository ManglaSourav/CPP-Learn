#include<iostream>
#include<cstring>

using namespace std;

void shiftTable(char *subStr, int *table)
{

    int i,j,m;

    m = (int)strlen(subStr);  // m = length of sub--String

    for(int i = 0; i < 500; i++)
    {
        table[i] = m;
        for(int j = 0; j < m; j++)
            table[subStr[j]] = m-1-j;
    }
}

int horspool(char *mainStr, char *subStr, int *table)
{
    int i,k,m,n;

    m = (int)strlen(mainStr);
    n = (int)strlen(subStr);
    i = n-1;
    while(i < m)
    {
        k = 0;
        while((k < n) && (subStr[n-1-k] == mainStr[i-k])) // continue loop till character matches
            k++;

        if(k == n)
            return i-n+1;
        else
        {
            i += table[mainStr[i]];  //shift move
        }
        return -1;
    }
    int main()
    {

        char mainStr[500],subStr[500];
        int table[500];
        cout<<"Enter the main String : ";
        cin>>mainStr;
        cout<<"Enter the sub String : ";
        cin>>subStr;
        shiftTable(subStr, table);
        int pos = horspool(mainStr, subStr, table);
        if(pos>=0)
            cout<<"String is found at index "<<pos;
        else
            cout<<"String nt found";
        return 0;
    }
