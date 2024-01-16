#include <bits/stdc++.h>

using namespace std;

void minimumBribes(vector<int> q){
    int bribes = 0;
    const int n = (int) q.size();

    for(int i = 0; i < n; i++){
        int o = q[i];
        int curr = i + 1;

        if(o - curr > 2){
            cout << "Too chaotic" << endl;
            return;    
        }

        for(int k = max(o - 2, 0); k < i; k++){
            if(q[k] > o)
                bribes++;
        }
    }

    cout << bribes << endl;
}

int main(){
    int n;

    cin >> n;
    vector<int> q(n);
    for(int i = 0; i < n; i++)
        cin >> q[i];

    minimumBribes(q);

    return 0;
}