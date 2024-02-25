#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, p[100005], d[100005];
    
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> p[i] >> d[i];
    
    int tank = 0, idx = 0, sum = 0;
    for(int i = 0; i< n; ++i){
        p[i] -= d[i];
        sum += p[i];

        if(tank + p[i] < 0){
            tank = 0;
            idx = i + 1;
        } else tank += p[i];
    }

    cout << (sum >= 0 ? idx : -1) << endl;
}

int main(int argc, char** argv){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
    return 0;
}