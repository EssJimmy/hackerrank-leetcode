#include <bits/stdc++.h>

using namespace std;

void solve(int n, int k, int* arr){
    int i = 0, count = 0;

    sort(arr, arr+n);
    while(i < n){
        int loc = arr[i] + k;
        while(i < n && arr[i] <= loc)
            i++;

        i--; count++;
        loc = arr[i] + k;
        while(i < n && arr[i] <= loc)
            i++;
    }
}

int main(){
    int n, k;
    
    cin >> n >> k;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    solve(n, k, arr);
    return 0;
}