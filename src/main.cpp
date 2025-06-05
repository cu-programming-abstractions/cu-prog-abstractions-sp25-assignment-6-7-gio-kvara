
#include "list.h"
#include "list_utils.h"
#include <iostream>
#include <cassert>
#include <stdexcept>

using namespace std;

// Helper function to print test results
void printTestResult(const string& testName, bool passed) {
    cout << (passed ? "V " : "x ") << testName << endl;
}

// Test basic list operations
void testBasicOperations() {
    cout << "\n=== Testing Basic Operations ===" << endl;

    LinkedList list;
    bool passed = true;

    // Test empty list
    passed &= list.isEmpty();
    printTestResult("Empty list is empty", passed);

    // Test prepend
    list.prepend(1);
    passed = !list.isEmpty();
    printTestResult("List not empty after prepend", passed);

    // Test append
    list.append(2);
    list.append(3);
    cout << "List after append: ";
    list.print(cout);
    cout << endl;

    // Test removeFront
    int val = list.removeFront();
    passed = (val == 1);
    printTestResult("removeFront returns correct value", passed);
}

// Test copy operations
void testCopyOperations() {
    cout << "\n=== Testing Copy Operations ===" << endl;
    bool passed = true;

    // Create original list
    LinkedList original;
    original.append(1);
    original.append(2);
    original.append(3);

    // Test copy constructor
    LinkedList copy1(original);
    passed = (length(copy1) == length(original));
    printTestResult("Copy constructor creates correct length", passed);

    // Test assignment operator
    LinkedList copy2;
    copy2 = original;
    passed = (length(copy2) == length(original));
    printTestResult("Assignment operator creates correct length", passed);

    // Test deep copy
    original.append(4);
    passed = (length(copy1) == 3 && length(copy2) == 3);
    printTestResult("Copies are independent", passed);
}

// Test utility functions
void testUtilityFunctions() {
    cout << "\n=== Testing Utility Functions ===" << endl;
    bool passed = true;

    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);

    // Test length
    passed = (length(list) == 3);
    printTestResult("length returns correct value", passed);

    // Test sum
    passed = (sum(list) == 6);
    printTestResult("sum returns correct value", passed);

    // Test contains
    passed = contains(list, 2) && !contains(list, 4);
    printTestResult("contains works correctly", passed);

    // Test reverse
    reverse(list);
    passed = (list.removeFront() == 3);
    printTestResult("reverse works correctly", passed);

    // Test nthFromEnd
    list.append(4);
    list.append(5);
    passed = (nthFromEnd(list, 0) == 5 && nthFromEnd(list, 3) == 2);
    printTestResult("nthFromEnd works correctly", passed);
}

// Test edge cases
void testEdgeCases() {
    cout << "\n=== Testing Edge Cases ===" << endl;
    bool passed = true;

    // Test empty list operations
    LinkedList empty;
    try {
        empty.removeFront();
        passed = false;
    } catch (const runtime_error&) {
        passed = true;
    }
    printTestResult("removeFront throws on empty list", passed);

    // Test nthFromEnd with invalid index
    try {
        nthFromEnd(empty, 0);
        passed = false;
    } catch (const runtime_error&) {
        passed = true;
    }
    printTestResult("nthFromEnd throws on invalid index", passed);

    // Test self-assignment
    LinkedList list;
    list.append(1);
    list = list;  // Self-assignment
    passed = (length(list) == 1);
    printTestResult("Self-assignment works correctly", passed);
}

// Test memory management
void testMemoryManagement() {
    cout << "\n=== Testing Memory Management ===" << endl;
    bool passed = true;

    // Test large list creation and destruction
    LinkedList list;
    for (int i = 0; i < 1000; i++) {
        list.append(i);
    }
    passed = (length(list) == 1000);
    printTestResult("Large list creation works", passed);

    // List will be automatically destroyed here
    // If there are memory leaks, they will be detected by memory checking tools
}

int main() {
    cout << "Starting Linked List Tests\n" << endl;

    try {
        testBasicOperations();
        testCopyOperations();
        testUtilityFunctions();
        testEdgeCases();
        testMemoryManagement();

        cout << "\nAll tests completed!" << endl;
    } catch (const exception& e) {
        cout << "\nTest failed with exception: " << e.what() << endl;
        return 1;
    }

    return 0;
}
