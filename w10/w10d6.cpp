#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solve(int* arr, int n, int k){
    if(n == 1){
        if(arr[0] < k)
            return -1;
        else
            return 0;
    }

    int movs = 0; 
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++)
        pq.emplace(arr[i]);

    while(!pq.empty() && pq.top() < k){
        int n1 = pq.top(); pq.pop();
        int n2 = pq.top(); pq.pop();

        if(n2 >= k)
            return -1;

        pq.emplace(n1 + (2*n2));

        
        movs++;
    }

    if(pq.empty())
        return -1;
    return movs;
}

int main(){
    int n, k;

    cin >> n >> k;
    int* arr = new int[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << solve(arr, n, k) << endl;
    free(arr);
    return 0;
}