#include <bits/stdc++.h>

using namespace std;

const int N = 1300;
const int M = 11000;

int ans[M], stk[M], tmpstk[M], prim[N];
int atop, top, ttop, n, q, num;

void init(){
    num = 0;

    for(int i = 2; i < M; ++i){
        bool found = false;

        for(int j = 2; j <= sqrt(i); ++j){
            if(i % j == 0){
                found = true;
                break;
            }
        }

        if(!found)
            prim[num++] = i;

        if(num >= 1200)
            return;
    }
}

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    init();
    atop = top = 0;

    for(int i = 0; i < n; ++i)
        cin >> stk[top++];

    for(int i = 0; i < q; ++i){
        ttop = 0;
        while(top){
            int v = stk[top-1];
            --top;
            if(v % prim[i] == 0)
                ans[atop++] = v;
            
            else
                tmpstk[ttop++] = v;
        }

        while(atop){
            cout << ans[atop-1] << endl;
            --atop;   
        }
        
        for(int j = 0; j < ttop; ++j)
            stk[j] = tmpstk[j];

        top = ttop;
        if(!top)
            break;
    }

    while(top){
        cout << stk[top-1] << endl;
        --top;   
    }

    return 0;
}