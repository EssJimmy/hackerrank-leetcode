#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

SinglyLinkedListNode* reverse(SinglyLinkedListNode* previous, SinglyLinkedListNode* current) {
    if(!current->next){
        current->next = previous;
        return current;
    }

    SinglyLinkedListNode* head = reverse(current, current->next);
    current->next =  previous;
    return head;
}

SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    if(!llist)
        return nullptr;
    
    if(!llist->next)
        return llist;

    SinglyLinkedListNode* previous; SinglyLinkedListNode* current;
    previous = llist; current = llist->next;

    SinglyLinkedListNode* ans = reverse(previous, current);
    llist->next = nullptr;

    return ans;
}
