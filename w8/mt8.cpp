#include <iostream>
#include <unordered_set>

using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = nullptr;
    }
};

class LinkedList{
public:
    int count;
    Node *head;
    Node *tail;

    LinkedList(){
        count = 0;
        head = nullptr;
        tail = nullptr;
    }

    void insert(int data){
        Node *n = new Node(data);
        if(!this->head)
            head = n;
        
        else
            this->tail->next = n;

        this->tail = n;
        count++;
    }
};

Node* removeDuplicates(Node* llist) {
    unordered_set<int> visited;
    LinkedList list = LinkedList();
    
    while(llist){
        if(visited.find(llist->data) == visited.end()){
            list.insert(llist->data);
            visited.insert(llist->data);
        }
        
        llist = llist->next;
    }
    
    return list.head;
}


int main(){
    return 0;
}