#include <bits/stdc++.h>

using namespace std;

int isPalindrome(string s){
    const int n = (int) s.size();
    
    int idx = 0;
    while(idx < n/2){
        if(s[idx] != s[n - idx - 1])
            return idx;

        idx++;
    }

    return -1;
}

int palindromeIndex(string s){
    const int n = (int) s.size();
    int x = isPalindrome(s);

    if(x == -1)
        return -1;

    s.erase(x, 1);
    if(isPalindrome(s) == -1)
        return x;
    else
        return n - 1 - x;
}

int main(){
    string s;

    cin >> s;
    cout << palindromeIndex(s) << endl;
    return 0;
}