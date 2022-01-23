#include<iostream>
using namespace std;




class Index
{
public:
    int i,j,val;
};

void doWork(Index index, int &arr){

  cout<<index.i<<index.j<<index.val;
}

int main()
{
    int t;
    cin>>t;
    int n,m,**arr;
    while(t--)
    {
        cin>>n>>m;

        arr = new int*[n];
        for(int i = 0; i < n; i++)
            arr[i] = new int[m];
    }

    Index index[n*m];
    int k = 0;
    for(int i = 0; i < n; i++ )
        for(int j = 0; j < m; j++ )
        {
            cin>>arr[i][j];

        }
      for(int i = 0; i < n; i++ )
        for(int j = 0; j < m; j++ )
          if(arr[i][j] > 0)
            {
                index[k].i = i;
                index[k].j = j;
                index[k].val = arr[i][j];
                k++;
            }

    for(int x = 0; x < k ; k++ )
            doWork(index[k],**arr);

    return 0;
}
