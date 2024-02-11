#include <bits/stdc++.h>

using namespace std;

stack<int> fillStack(vector<int> h){
    stack<int> st;
    int height = 0;
    for(int i = h.size()-1; i > -1; i--){
        height += h[i];
        st.push(height);
    }

    return st;
}

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3){
    stack<int> st1; stack<int> st2; stack<int> st3;
    
    st1 = fillStack(h1); st2 = fillStack(h2); st3 = fillStack(h3);
    int height = 0;
    bool found = false;
    while(!st1.empty() && !st2.empty() && !st3.empty() && !found){

        int st1H = st1.top(); int st2H = st2.top(); int st3H = st3.top();
        int maxH = max(st1H, max(st2H, st3H));

        if(st1H == st2H && st2H == st3H){
            height = st1H;
            found = true;
        }

        if(maxH == st1H)
            st1.pop();
        else if(maxH == st2H)
            st2.pop();
        else
            st3.pop();
    }

    return height;
}