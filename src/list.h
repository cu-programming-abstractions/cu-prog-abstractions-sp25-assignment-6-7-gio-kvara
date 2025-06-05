#pragma once
#include <iostream>

using namespace std;

class LinkedList {
public:
    struct Node {
        int data;
        Node* next;
    };

    LinkedList();
    LinkedList(const LinkedList& other);
    LinkedList& operator=(LinkedList rhs);
    ~LinkedList();

    void prepend(int value);
    void append(int value);
    int  removeFront();
    bool isEmpty() const;
    Node* getHead() const { return head; }
    void setHead(Node* newHead) { head = newHead; }

    void print(ostream& out = cout) const;

private:
    Node* head = nullptr;

    /* utility to deep-copy a chain, returns new head */
    static Node* deepCopy(Node* src);
    /* utility to free chain starting at given node */
    static void freeChain(Node* n);
};
