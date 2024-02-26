#include <iostream>
#include <string>

using namespace std;

int valid(string x){
    const int n = (int) x.size();

    for(int i = 1; i < n; i++){
        if(x[i] == x[i-1])
            return false;
    }

    return true;
}

int maint(int argc, char** argv){
    int asd;
    cin >> asd;

    string s;
    cin >> s;
    int ans = 0;

    for(char a = 'a'; a <= 'z'; ++a)
    for(char b = 'b'; b <= 'z'; ++b)
    if(a != b){
        if(s.find(a) == string::npos) continue;
        if(s.find(b) == string::npos) continue;

        string x;
        for(const char ch : s)
            if(ch == a || ch == b)
                x.push_back(ch);

        if(valid(x))
            ans = max(ans, (int) x.size());
    }
    
    cout << ans << endl;
}