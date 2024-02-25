#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n, arr[100005];
	int res = 0;

	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	for(int i = n-1; i >= 0; i--){
		int x = res + arr[i];
		res = x/2 + x%2;
	}

	cout << res << endl;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}