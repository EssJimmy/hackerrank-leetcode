#include <iostream>
#include <map>
#include <string>

using namespace std;

int sherlockAndAnagrams(string s){
    map<string, int> stringMap;
    int count = 0;

    for(int i = 0; i < (int) s.length(); i++){
        for(int j = 1; j <= s.length() - i; j++){
            char letter = 'a';
            string substr, sortedSubstr;
            substr = s.substr(i, j);

            for(int k = 0; k < 27; k++){
                for(int l = 0; l < substr.length(); l++){
                    if(substr[l] == letter)
                        sortedSubstr += letter;
                }
                letter++;
            }

            if(stringMap.count(sortedSubstr) == 0)
                stringMap[sortedSubstr] = 0;
            else
                stringMap[sortedSubstr]++;
        }
    }

    for(auto it : stringMap){
        int value = it.second;

        if(value > 0)
            count += (value*(value+1)/2);
    }

    return count;
}