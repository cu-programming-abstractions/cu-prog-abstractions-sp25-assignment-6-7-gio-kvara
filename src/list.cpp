#include "list.h"
#include <stdexcept>
#include <utility>  // for std::swap

LinkedList::LinkedList() = default;

// Copy constructor: deep copy using deepCopy helper
LinkedList::LinkedList(const LinkedList& other) {
    head = deepCopy(other.head);
}

// Assignment operator using copy-and-swap idiom
LinkedList& LinkedList::operator=(LinkedList rhs) {
    std::swap(head, rhs.head);
    return *this;
}

// Destructor frees all nodes
LinkedList::~LinkedList() {
    freeChain(head);
}

void LinkedList::prepend(int value) {
    head = new Node{value, head};
}

void LinkedList::append(int value) {
    Node* newNode = new Node{value, nullptr};
    if (isEmpty()) {
        head = newNode;
    } else {
        Node* cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
    }
}

int LinkedList::removeFront() {
    if (isEmpty()) throw std::runtime_error("removeFront on empty list");
    Node* oldHead = head;
    int value = oldHead->data;
    head = head->next;
    delete oldHead;
    return value;
}

bool LinkedList::isEmpty() const {
    return head == nullptr;
}

void LinkedList::print(ostream& out) const {
    out << '[';
    Node* cur = head;
    while (cur) {
        out << cur->data;
        if (cur->next) out << " → ";
        cur = cur->next;
    }
    out << ']';
}

// Private helper: deep copy a chain recursively
LinkedList::Node* LinkedList::deepCopy(Node* src) {
    if (src == nullptr) return nullptr;
    Node* newNode = new Node{src->data, nullptr};
    newNode->next = deepCopy(src->next);
    return newNode;
}

// Private helper: free chain nodes iteratively
void LinkedList::freeChain(Node* n) {
    while (n) {
        Node* next = n->next;
        delete n;
        n = next;
    }
}
