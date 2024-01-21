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

Node* mergeLists(Node* head1, Node* head2) {
    LinkedList ans;
    vector<int> arr;

    while(head1){
        arr.push_back(head1->data);
        head1 = head1->next;
    }

    while(head2){
        arr.push_back(head2->data);
        head2 = head2->next;
    }

    sort(arr.begin(), arr.end());
    for(int& i : arr)
        ans.insert_node(i);
    
    return ans.head;
}

int main(){
    return 0;
}