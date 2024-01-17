#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player){
    set<int> s;

    for(int& i : ranked)
        s.insert(i);

    vector<int> arr(s.begin(), s.end());
    vector<int> ans;
    for(int i = 0; i < (int) player.size(); i++){
        int pos = (upper_bound(arr.begin(), arr.end(), player[i]) - arr.begin());
        ans.push_back((int) arr.size() - pos + 1);
    }
    return ans;
}

int main(){
    int n, m;

    cin >> n >> m;
    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> brr(m);
    for(int i = 0; i < m; i++)
        cin >> brr[i];

    for(int& i : climbingLeaderboard(arr, brr))
        cout << i << " ";

    cout << endl;
    return 0;
}