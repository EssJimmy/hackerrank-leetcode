#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class LinkedList {
    public:
        Node *head;
        Node *tail;

        LinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            Node* node = new Node(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};


Node* insertNodeAtPosition(Node* llist, int data, int position) {
    if(!llist)
        llist = new Node(data);

    if(!llist->next)
        llist->next = new Node(data);

    Node *previous = llist; 
    Node *current = llist->next;
    Node *n = new Node(data);
    
    while(position > 1){
        previous = current; 
        current = current->next;
        position--;
    }

    previous->next = n;
    n->next = current;
    return llist;
}
