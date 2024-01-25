#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool isPrime(int n){
    if(n <= 2)
        return false;

    if(n == 2 || n == 3)
        return true;

    if(n % 2 == 0 || n % 3 == 0)
        return false;

    for(int i = 5; i < sqrt(n); i++){
        if(n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

vector<int> waiter(vector<int> number, int q){
    vector<int> primes(q);

    int j = 0;
    for(int i = 0; i < number[number.size() - 1]; i++){
        if(isPrime(i)){
            primes[j] = i;
            j++;
        }
    }

    stack<int> plates;
    stack<int> rest;
    j = 0;
    while(q--){
        for(int i = 0; i < (int) number.size(); i++){
            if(number[i] % primes[j] == 0)
                plates.push(number[i]);
            
            else
                rest.push(number[i]);
             
        }
        j++;
    }

    vector<int> ans;
    while(!plates.empty()){
        ans.push_back(plates.top());
        plates.pop();
    }

}