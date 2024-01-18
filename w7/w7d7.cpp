#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        DoublyLinkedListNode *head;
        DoublyLinkedListNode *tail;

        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
            }

            this->tail = node;
        }
};

DoublyLinkedListNode* reverse(DoublyLinkedListNode* previous, DoublyLinkedListNode* current, DoublyLinkedListNode* next){
    if(!next){
        current->prev = nullptr;
        current->next = previous;

        return current;
    }

    DoublyLinkedListNode *head = reverse(current, next, next->next);

    current->prev = next;
    current->next = previous;
    return head;
}

DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    if(!llist)
        return nullptr;

    if(!llist->next)
        return llist;

    DoublyLinkedListNode *previous = nullptr;
    DoublyLinkedListNode *current = llist;
    DoublyLinkedListNode *next = llist->next;

    DoublyLinkedListNode *ans = reverse(previous, current, next);
    llist->next = nullptr;

    return ans;
}
