#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int pairs(int k, vector<int> arr) {
    unordered_set<long long> set;
    long long count = 0;
    
    for(int i : arr)
        set.insert(i - k);
        
    for(int i : arr){
        if(set.find(i) != set.end())
            count++;
    }
    
    return count;
}