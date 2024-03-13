#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <stack>

typedef long long ll;

using namespace std;

ll solve(int n, int* arr){
    ll max = -numeric_limits<ll>::infinity();
    ll tp;
    ll topArea;

    stack<int> s;
    
    int i = 0;
    while(i < n){
        if(s.empty() || arr[s.top()] <= arr[i])
            s.push(i++);

        else{
            tp = s.top();
            s.pop();

            topArea = arr[tp]*( s.empty() ? i: i - s.top() - 1);

            if(max < topArea)
                max = topArea;
        }
    }

    while(!s.empty()){
        tp = s.top();
        s.pop();
        
        topArea = arr[tp]*( s.empty() ? i: i - s.top() - 1);

        if(max < topArea)
            max = topArea;
    }

    return max;
}

int main(int argc, char** argv){
    int n;

    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << solve(n, arr) << endl;
    free(arr);
    
    return 0;
}