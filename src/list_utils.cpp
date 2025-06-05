
#include "list_utils.h"
#include "list.h"
#include <stdexcept>

int length(const LinkedList& list) {
    int count = 0;
    LinkedList::Node* curr = list.getHead();
    while (curr) {
        ++count;
        curr = curr->next;
    }
    return count;
}

int sum(const LinkedList& list) {
    int total = 0;
    LinkedList::Node* curr = list.getHead();
    while (curr) {
        total += curr->data;
        curr = curr->next;
    }
    return total;
}

bool contains(const LinkedList& list, int k) {
    LinkedList::Node* curr = list.getHead();
    while (curr) {
        if (curr->data == k) return true;
        curr = curr->next;
    }
    return false;
}

void reverse(LinkedList& list) {
    LinkedList::Node* prev = nullptr;
    LinkedList::Node* curr = list.getHead();

    while (curr) {
        LinkedList::Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    list.setHead(prev);
}

int nthFromEnd(const LinkedList& list, int n) {
    if (n < 0) throw std::out_of_range("n must be non-negative");

    // First compute length
    int len = length(list);
    if (n >= len) throw std::out_of_range("n is out of range");

    int targetIndex = len - n - 1;  // convert nth from end to index from front

    LinkedList::Node* cur = list.getHead();
    int index = 0;
    while (cur) {
        if (index == targetIndex) {
            return cur->data;
        }
        cur = cur->next;
        index++;
    }

    // Should not reach here if inputs are valid
    throw std::runtime_error("Unexpected error in nthFromEnd");
}
