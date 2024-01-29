#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long stockmax(vector<int> prices){
    long ans = 0;
    long stock = 0;
    
    for(int i = 0; i < (int) prices.size() - 1; i++){
        stock++;
        ans -= prices[i];
    }

    return ans;
}