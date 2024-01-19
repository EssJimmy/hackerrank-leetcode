#include <bits/stdc++.h>

using namespace std;

vector<string> bigSorting(vector<string> unsorted) {
    sort(unsorted.begin(), unsorted.end(), [](const string& a, const string& b){
        return a.length() < b.length() || a.length() == b.length() && a < b;
    });
    
    
    return unsorted;
}

int main(){
    int n;

    cin >> n;
    vector<string> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(string& s : bigSorting(arr))
        cout << s << endl;
    return 0;
}