#include<iostream>
#include<vector>
#include<math.h>
#include "algorithm"

using namespace std;

struct bundle {
    int low;
    int high;
    int sum;
};

vector<int> prefixSum(vector<int> arr, int low, int high) {

    vector<int> temp(high - low);
    temp[0] = arr[low];
    cout << arr[low] << endl;
    int j = 1;
    for (auto a: temp) {
        cout << a << " ";
    }
    cout << endl;
    for (int i = low + 1; i <= high; i++) {
        temp[j] = arr[i] + temp[j - 1];
        j++;
    }
    return temp;
}

bundle minPosSubArr(vector<int>
                    arr,
                    int low,
                    int high
) {
    if (low == high) {
        return bundle{
                low, high, arr[low]
        };
    }
    int mid = floor((low + high) / 2);
    struct bundle leftBundle = minPosSubArr(arr, low, mid);
    struct bundle rightbundle = minPosSubArr(arr, mid + 1, high);
    vector<int> B = prefixSum(arr, low, mid);
    vector<int> C = prefixSum(arr, mid + 1, high);
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());


    return bundle{
            low, high, arr[low]
    };
}


int main() {

    vector<int> arr = {13, 3, -25, 20, -3, 16, -35, -1};

    for (auto a: prefixSum(arr, 0, 5)) {
        cout << a << " ";
    }
//    cout << prefixSum(arr, 0, 5).at(4);
//    cout << minPosSubArr(arr, 0, arr.size()).low;
    return 0;
}

