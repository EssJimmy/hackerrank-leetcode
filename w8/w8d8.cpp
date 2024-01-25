#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

string isBalanced(string s) {
    stack<char> chars;
    unordered_map<char, char> mpp;
    
    mpp['('] = ')'; mpp['['] = ']'; mpp['{'] = '}';

    for(char& c : s){
        if(chars.empty() || mpp.find(c) != mpp.end())
            chars.push(c);
        
        else if(mpp[chars.top()] == c)
            chars.pop();

        else return "NO";
    }
    
    return "YES";
}

int main(){
    return 0;
}