#include <iostream>

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


SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    if(!llist)
        llist = new SinglyLinkedListNode(data);

    if(!llist->next)
        llist->next = new SinglyLinkedListNode(data);

    SinglyLinkedListNode *previous = llist; 
    SinglyLinkedListNode *current = llist->next;
    SinglyLinkedListNode *node = new SinglyLinkedListNode(data);
    
    while(position-- && current->next){
        previous = current; 
        current = current->next;
    }

    previous->next = node;
    node->next = current;
    return llist;
}
