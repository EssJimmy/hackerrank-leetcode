#include <bits/stdc++.h>

using namespace std;

class DoubleNode{
public:
    int element;
    DoubleNode *next;
    DoubleNode *prev;

    DoubleNode(int element){
        this->element = element;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList{
public:
    DoubleNode *head;
    DoubleNode *tail;
    int count;

    LinkedList(){
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    void insert(int element){
        DoubleNode* n = new DoubleNode(element);

        if(!this->head)
            this->head = n;
        else{
                this->tail->next = n;
                n->prev = this->tail;
        }

        this->tail = n;
        this->count++;
    }
};

DoubleNode* reverse(DoubleNode* previous, DoubleNode* current, DoubleNode* next){
    if(!next){
        current->next = previous;
        current->next = nullptr;

        return current;
    }

    DoubleNode *head = reverse(current, next, next->next);
    current->prev = next;
    current->next = previous;
    
    return head;
}

DoubleNode* reverse(DoubleNode* lList){
    if(!lList)
        return nullptr;

    if(!lList->next)
        return lList;

    DoubleNode* previous = nullptr;
    DoubleNode* current = lList;
    DoubleNode* next = lList->next;

    DoubleNode* ans = reverse(previous, current, next);
    free(previous); free(current); free(next);
    lList->next = nullptr;

    return ans;
}