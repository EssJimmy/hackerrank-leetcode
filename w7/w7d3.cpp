#include <iostream>
#include <vector>

using namespace std;

int pylons(int k, vector<int> arr){
    int towers = 0;
    const int n = (int) arr.size();
    
    for(int i = 0; i < n;){
        int j = i + k - 1;

        for(; j + k > i; --j){
            if((bool) arr[j + k])
                break;
        }

        if(j + k == i)
            return -1;

        towers++;
        i = j + k;
    }

    return towers;
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> arr(n + 2*k);
    for(int i = 0; i < n; i++)
        cin >> arr[k + i];
    

    cout << pylons(k, arr) << endl;
    
    return 0;
}