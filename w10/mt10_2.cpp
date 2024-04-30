#include <bits/stdc++.h>

using namespace std;

void almostSorted(int k, vector<int> arr){
    vector<int> aux = arr;
    sort(aux.begin(), aux.end());
    
    int start = -1, end, n = (int) arr.size(), count = 0;
    for(int i = 0; i < n; i++){
        if(aux[i] != arr[i]){
            if(start == -1) start = i;
            else end = i;

            count++;
        }
    }

    if(count == 2){
        bool condt = (start == 0 && end - start == 1) ||
            (end == n - 1 && end - start == 1) ||
            (start > 0 && end == n - 1 && arr[end] > arr[start - 1]) ||
            (arr[start] < arr[end + 1] && arr[end] > arr[start - 1]);

        if(condt){
            cout << "yes" << endl;
            cout << "swap " + to_string(start + 1) + " " + to_string(end + 1) << endl;
            return;
        }

        cout << "no" << endl;
        return;
    }
    
    for(int i = start; i < end; i++){
        if(arr[i] < arr[i+1]){
            cout << "no" << endl;
            return;
        }
    }

    bool condt = (start == 0 && end == n - 1) ||
        ((start == 0 && end + 1 < n) && arr[start] < arr[end + 1]) ||
        ((end == n - 1 && arr[end] > arr[start - 1])) ||
        (arr[end] > arr[start - 1] && arr[start] < arr[end + 1]);

    if(condt){
        cout << "yes" << endl;
        cout << "reverse " + to_string(start + 1) + " " + to_string(end + 1) << endl;
        return;
    }

    cout << "no" << endl;
}