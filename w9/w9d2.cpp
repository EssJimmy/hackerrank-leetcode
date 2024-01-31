#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        long long n, i, idx;
        long long sum = 0;
        vector<long long> a(50005);
        vector<long long> b(50005);

        cin >> n;
        for(i = 1; i <= n; i++)
            cin >> a[i];

        idx = n;
        b[n] = n;
        for(i = n - 1; i > 0; i--){
            if(a[idx] < a[i])
                idx = i;
            
            b[i] = idx;
        }

        for(i = 1; i <= n; i++){
            if((a[b[i]] - a[i]) >= 0)
                sum += a[b[i]] - a[i];
        }

        cout << sum << endl;
    }
}