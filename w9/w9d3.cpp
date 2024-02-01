#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char** argv){
    int q;
    string s = "";
    vector<string> last(2);
    vector<vector<string>> k;

    cin >> q;
    
    while(q--){
        vector<string> qs(2);
        cin >> qs[0]; cin >> qs[1];
        
        k.push_back(qs);
    }

    for(auto t : k){
        switch(t[0][0]){
            case '1':
                last[0] = "1";
                last[1] =  to_string(s.length());
                s += t[1];
                break;

            case '2':
                last[0] = "2";
                last[1] = s.substr((int) t[1][0]);
                s = s.substr(0, s.length() - (int) t[1][0]);
                break;

            case '3':
                cout << s[(int) t[1][0]] << endl;
                break;

            case '4':
                if(last[0][0] == '1')
                    s = s.substr(0, (int) last[1][0]);

                else if(last[0][0] == '2')
                    s += last[1];

                last[0] = "4";
                break;

            default:
                break;
        }
    }

    return 0;
}