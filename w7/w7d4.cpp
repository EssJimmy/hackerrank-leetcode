#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string isValid(string s){
    int l = (int) s.size();
    int count = 0;
    vector<int> arr(26);

    for(int i = 0; i < l; i++){
        int x = s[i] - 97;
        arr[x]++;
    }
    
    l = 0;
    sort(arr.begin(), arr.end());

    for(int i = 0; i < 26; i++){
        if(arr[i] == 0)
            l++;

        if(arr[l] == 1){
            l++;
            count++;
        }
    }

    for(int i = l + 1; i < 26; i++){
        if(arr[i] != arr[l])
            count++;
    }

    if(arr[l + 1] + 1 < arr[25])
        return "NO";

    if(count > 1)
        return "NO";
    else
        return "YES";
}


int main() {
    string s;

    cin >> s;

    cout << isValid(s) << endl;

    return 0;
}