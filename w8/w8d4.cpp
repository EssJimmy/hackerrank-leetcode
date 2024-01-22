#include <iostream>
#include <stack>

using namespace std;

class queue{
public:
    stack<int> s;
    int count;

    queue(){
        count = 0;
    }

    void enqueue(int data){
        stack<int> aux;
        
        while(!s.empty()){
            aux.push(s.top());
            s.pop();
        }

        aux.push(data);
        while(!aux.empty()){
            s.push(aux.top());
            aux.pop();
        }

        count++;
    }

    void dequeue(){
        s.pop();
        count--;
    }

    int top(){
        return s.top();
    }
};

int main(int argc, char** argv){
    int t, type, x;
    queue q = queue();
    
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> type;

        switch (type){
            case 1:
                cin >> x;
                q.enqueue(x);
                break;
            
            case 2:
                q.dequeue();
                break;

            case 3:
                cout << q.top() << endl;
            default:
                break;
        }
    }

    return 0;
}