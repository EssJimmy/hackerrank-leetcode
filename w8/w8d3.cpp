#include <bits/stdc++.h>

using namespace std;

vector<int> icecreamParlor(int m, vector<int> arr){
    unordered_map<int, int> mpp;
    vector<int> ans(2);

    for(int i = 0; i < (int) arr.size(); i++){
        if(mpp.find(m - arr[i]) != mpp.end()){
            ans[0] = mpp[m - arr[i]] + 1; ans[1] = i + 1;
            return ans;
        }
        mpp[arr[i]] = i;
    }

    return ans;
}

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> m >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int& i : icecreamParlor(m, arr))
        cout << i << " ";

    cout << endl;
    
    return 0;
}

