#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv){
    int q;
    set<int> set;

    cin >> q;
    while(q--){
        int t, v;
        
        cin >> t;
        if(t != 3){
            cin >> v;

            if(t == 1){
                set.insert(v);
            }
            else{
                set.erase(set.find(v));
            }
        }
        else{
            cout << *set.begin() << endl;
        }
    }

    return 0;
}