#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

vector<int> maxSubarray(vector<int> arr){
    int prevSubarray = std::numeric_limits<int>::min();
    int subarray = 0;
    int subsequence = 0;
    

    for(const int i : arr){
        subarray += i;
        prevSubarray = max(prevSubarray, subarray);
        if(subarray < 0)
            subarray = 0;
        
        if(i > 0)
            subsequence += i;
    }

    if(subsequence == 0)
        subsequence = *max_element(arr.begin(), arr.end());

    return {prevSubarray, subsequence};
}

int main(int argc, char** argv){
    int t, n;

    cin >> t;

    while(t--){
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        for(const int i : maxSubarray(arr))
            cout << i << " ";
        
        cout << endl;
    }

    return 0;
}