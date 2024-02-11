#include <bits/stdc++.h>

using namespace std;

int alterante(string s){
    unordered_map<char, vector<int>> mpp;

    for(int i = 0; i < (int) s.size(); i++)
        mpp[s[i]].push_back(i);

    
}