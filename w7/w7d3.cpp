#include <iostream>
#include <vector>

using namespace std;

int pylons(int n, int k, vector<int> bm){
    int ans = 0;
    
    for(int i = 0; i < n;){
        int j = k + i - 1;

        for(; j + k > i; --j){
            if(!!bm[j + k])
                break;
        }

        if(j + k == i){
            return -1;
        }

        ++ans;
        i = j + k;
    }

    return ans;
}

int main(int argc, char* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    vector<int> bm;

    cin >> n >> k;
    bm.resize(n + 2 * k);
    for(int i = 0; i < n; ++i){
        cin >> bm[k + i];
    }

    cout << pylons(n, k, bm) << endl;

    return 0;
}