#include <bits/stdc++.h>

using namespace std;

vector<string> solve(string s, vector<int> queries){
    unordered_map<char, int> mpp;
    int a = 1;
    for(char c = 'a'; c <= 'z'; c++, a++){
        mpp[c] = a;
    }

    unordered_set<int> set;
    string subs;
    subs.push_back(s[0]);
    for(int i = 1; i < (int) s.length(); i++){
        set.insert(mpp[subs[0]]*int(subs.length()));

        if(subs[0] == s[i])
            subs += s[i];
        else{
            subs = "";
            subs.push_back(s[i]);
        }
    }

    set.insert(mpp[subs[0]]*int(subs.length()));

    cout << endl;

    vector<string> ans;
    for(int q : queries){
        if(set.find(q) != set.end())
            ans.push_back("Yes");
        else
            ans.push_back("No");
    }

    return ans;
}

int main(int argc, char** argv){
    string s;
    int n;

    cin >> s >> n;
    vector<int> queries(n);
    for(int i = 0; i < n; i++)
        cin >> queries[i];
    
    for(string c : solve(s, queries))
        cout << c << endl;

    return 0;
}