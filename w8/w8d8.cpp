#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

string isBalanced(string s) {
    stack<char> chars;
    unordered_map<char, char> mpp;
    vector<char> open{'(', '{', '['};

    mpp[')'] = '('; mpp[']'] = '['; mpp['}'] = '{';

    for(char& c : s){
        if(chars.empty() || find(open.begin(), open.end(), c) != open.end())
            chars.push(c);
        
        else if(mpp[c] == chars.top())
            chars.pop();

        else return "NO";
    }
    
    return "YES";
}

int main(){
    return 0;
}