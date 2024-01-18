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

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    if(!llist)
        return nullptr;
    
    if(!llist->next)
        return llist;

    SinglyLinkedListNode* previous; SinglyLinkedListNode* current;
    previous = llist; current = llist->next;

    SinglyLinkedListNode* ans = reverse(previous, current);

    while(ans->next)
        ans = ans->next;

    ans->next = nullptr;
    return ans;
}

SinglyLinkedListNode* reverse(SinglyLinkedListNode* previous, SinglyLinkedListNode* current) {
    if(!current->next){
        current->next = previous;
        return current;
    }

    SinglyLinkedListNode* head = reverse(current, current->next);
    current->next =  previous;
    return head;
}