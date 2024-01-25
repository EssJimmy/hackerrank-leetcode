#include <iostream>
#include <string>
#include <stack>

using namespace std;

string superReducedString(string s){
    bool isZero = false;

    int i = 0; 
    while(i < (int) s.length() && !isZero){
        if(s[i] == s[i+1]){
            s.erase(s.begin() + i);
            s.erase(s.begin() + i);

            i = -1;
        }
        else
            ++i;

        isZero = s.length() == 0;
    }

    if(isZero)
        return "Empty String";
    else
        return s;
}

int main(){

}