#include <iostream>
#include <cmath>

using namespace std;
#define MOD 1000000007

long long fastExp(long long base, int exp){
    long long res = 1;

    while(exp > 0){
        if(exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }

    return (res % MOD);
}

int main(int argc, char** argv){
    int t, n, m;

    cin >> t;
    while(t--){
        cin >> n >> m;
        long long* total = new long long[m+1];

        for(int i = 0; i < m + 1; i++){
            if (i == 0) total[0] = 1;
			if (i == 1) total[1] = 1;
			if (i == 2) total[2] = 2;
			if (i == 3) total[3] = 4;
			if (i > 3) total[i] = (total[i-1] + total[i-2] + total[i-3] + total[i-4]) % MOD;
        }

        long long* ways = new long long[m + 1];
        long long countWays;
        ways[0] = 0; ways[1] = 1;

        for(int j = 2; j < m + 1; j++){
            countWays = 0;
            for(int i = 1; i < j; i++)
                countWays = (countWays + (ways[i] * fastExp(total[j-i], n)) % MOD) % MOD;
                
            ways[j] =(fastExp(total[j], n) - countWays) % MOD;
            if(ways[j] < 0) ways[j] = MOD + ways[j];
        }

        free(total);
        cout << ways[m] << endl;
        free(ways);
    }

    return 0;
}