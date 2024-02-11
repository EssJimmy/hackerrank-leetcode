#include <bits/stdc++.h>

using namespace std;

long getWays(long amount, vector <long> coins){
	long size = coins.size();
	long noofways[size+1][amount+1];
	
	for(long i = 0 ; i < amount+1; i++){
		noofways[0][i] = 0;
	}

	for(long i = 0; i < size+1; i++)
		noofways[i][0] = 1;
	


	for(long i = 1; i<size+1; i++){
		for(long j = 1; j<amount+1; j++){
			if(coins[i-1] <= j)
				noofways[i][j] = noofways[i-1][j] + noofways[i][j-coins[i-1]];
			
			else
				noofways[i][j] = noofways[i-1][j];
		}
	}
	
	return noofways[size][amount];
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<long> c(m);

	for(int c_i = 0; c_i < m; c_i++){
		cin >> c[c_i];
	}
	
	cout << getWays(n, c) << endl;
	return 0;
}