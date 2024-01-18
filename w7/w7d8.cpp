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

void insertNodeAtPosition(SinglyLinkedListNode* previous, SinglyLinkedListNode* current, int data, int position) {
    if(!position){
        SinglyLinkedListNode *n = new SinglyLinkedListNode(data);
        previous->next = n;
        n->next = current;
    }

    insertNodeAtPosition(current, current->next, data, position - 1);
}

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    if(!llist)
        llist = new SinglyLinkedListNode(data);

    if(!llist->next)
        llist->next = new SinglyLinkedListNode(data);

    SinglyLinkedListNode *previous = llist; 
    SinglyLinkedListNode *current = llist->next;

    free(previous); free(current);

    return llist;
}
