#include <bits/stdc++.h>

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

bool has_cycle(Node* head) {
    unordered_map<Node*, bool> visited;

    while(head && !visited[head]){
        visited[head] = true;
        head = head->next;
    }

    if(head)
        return 1;
    else
        return 0;
}
