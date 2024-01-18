#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    int element;
    Node *next;

    Node(int element){
        this->element = element;
        next = nullptr;
    }
};

class LinkedList{
public:
    Node *head;
    Node *tail;
    int count;

    LinkedList(){
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    void insert(int element){
        Node* n = new Node(element);

        if(!this->head)
            this->head = n;
        else
            this->tail->next = n;

        this->tail = n;
        this->count++;
    }
};

Node* reverse(Node* previous, Node* current){
    if(!current->next){
        current->next = previous;
        return current;
    }

    Node *head = reverse(current, current->next);
    current->next = previous;

    return head;
}

Node* reverse(Node* lList){
    if(!lList)
        return nullptr;

    if(!lList->next)
        return lList;

    Node* previous = lList;
    Node* current = lList->next;

    Node* ans = reverse(previous, current);

    free(previous); free(current);
    lList->next = nullptr;

    return ans;
}