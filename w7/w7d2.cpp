#include <bits/stdc++.h>

using namespace std;

void minimumBribes(vector<int> q){
    int bribes = 0;

    int i = 0;
    bool ans = true;
    while(i < (int) q.size() && ans){
        ans = q[i] - (i+1) < 3;
        i++;
    }

    if(ans)
        cout << bribes << endl;
    else
        cout << "Too chaotic" << endl; 
}

/*
8
1 2 5 3 7 8 6 4
*/

int main(){
    int n;

    cin >> n;
    vector<int> q(n);
    for(int i = 0; i < n; i++)
        cin >> q[i];

    minimumBribes(q);

    return 0;
}