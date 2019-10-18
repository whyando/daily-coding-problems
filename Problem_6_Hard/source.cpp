#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node* both;
    int value;
    Node(){}
    Node(int v):value(v){}
};

class XOR_linked_list {
    Node *head, *tail;
public:
    XOR_linked_list(){
        head = new Node();
        tail = new Node();
        head->both = tail;
        tail->both = head;
    }

    Node* add(int x) {
        // fill in value to tail Node and add new dummy tail
        Node* new_tail = new Node();

        tail->value = x;

        tail->both     = (Node*)((int64_t)tail->both ^ (int64_t)new_tail);
        new_tail->both = tail;

        tail = new_tail;

        return tail->both;
    }

    Node* get(int index) const {
        Node *prev = nullptr;
        Node *x = head;
        for(int k=1;k<=index;k++){
            Node* next = (Node *)((int64_t)x->both ^ (int64_t)prev);
            prev = x;
            x = next;
        }
        return x;
    }

    // bonus: identical to above except starting node is tail
    Node* get_from_end(int index) const {
        Node *prev = nullptr;
        Node *x = tail;
        for(int k=1;k<=index;k++){
            Node* next = (Node *)((int64_t)x->both ^ (int64_t)prev);
            prev = x;
            x = next;
        }
        return x;
    }
};


int main(){
    XOR_linked_list list;
    list.add(101);
    list.add(202);
    list.add(303);
    list.add(404);

    cout << list.get(1)->value << endl;
    cout << list.get(2)->value << endl;
    cout << list.get(3)->value << endl;
    cout << list.get(4)->value << endl;
    cout << endl;

    cout << list.get_from_end(1)->value << endl;
    cout << list.get_from_end(2)->value << endl;
    cout << list.get_from_end(3)->value << endl;
    cout << list.get_from_end(4)->value << endl;

    return 0;
}

/* outputs:

101
202
303
404

404
303
202
101

*/