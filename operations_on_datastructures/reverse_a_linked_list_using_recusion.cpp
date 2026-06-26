/**
 * @file
 * @brief Implementation of [Reversing a singly linked list using recursion]
 * (https://simple.wikipedia.org/wiki/Linked_list)
 * @details
 * The linked list is a data structure used for holding a sequence of
 * values, which can be added, displayed, and reversed.
 * ### Algorithm
 * Linked List can be reversed recursively. We traverse to the end of the
 * list, then on the way back, we make each node point to its previous node,
 * reversing the links. The head is updated to point to the last node.
 */

#include <cassert>   /// for assert
#include <cstdint>   /// for int32_t
#include <iostream>  /// for I/O operations
#include <new>       /// for managing dynamic storage

/**
 * @namespace data_structures
 * @brief Data Structures algorithms
 */
namespace data_structures {
/**
 * @namespace linked_list
 * @brief Functions for singly linked list using recursion
 */
namespace linked_list {

/**
 * @brief A Node class containing a value and pointer to next node
 */
class Node {
 public:
    int32_t val;  /// value of the current node
    Node* next;   /// pointer to the next node
};

/**
 * @brief A list class containing a sequence of nodes
 */
class list {
 private:
    Node* head = nullptr;

 public:
    bool isEmpty() const;
    void insert(int32_t new_elem);
    void reverseList(Node* curr, Node* prev);
    void reverseAll();
    int32_t top() const;
    int32_t last() const;
    ~list();
};

/**
 * @brief Checks if the list is empty
 * @returns true if empty, false otherwise
 */
bool list::isEmpty() const { return head == nullptr; }

/**
 * @brief Adds a new element at the end of the list
 * @param new_elem element to be added
 */
void list::insert(int32_t n) {
    Node* new_node = new Node();
    new_node->val = n;
    new_node->next = nullptr;
    if (isEmpty()) {
        head = new_node;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

/**
 * @brief Recursively reverses the linked list
 * @param curr pointer to current node
 * @param prev pointer to previous node
 */
void list::reverseList(Node* curr, Node* prev) {
    if (curr->next == nullptr) {
        head = curr;
        curr->next = prev;
        return;
    }
    reverseList(curr->next, curr);
    curr->next = prev;
}

/**
 * @brief Public wrapper to start reversal from head
 */
void list::reverseAll() {
    if (!isEmpty()) {
        reverseList(head, nullptr);
    }
}

/**
 * @brief Returns the top element of the list
 * @returns top element
 */
int32_t list::top() const {
    if (!isEmpty()) {
        return head->val;
    }
    throw std::logic_error("List is empty");
}

/**
 * @brief Returns the last element of the list
 * @returns last element
 */
int32_t list::last() const {
    if (!isEmpty()) {
        Node* t = head;
        while (t->next != nullptr) {
            t = t->next;
        }
        return t->val;
    }
    throw std::logic_error("List is empty");
}

/**
 * @brief Destructor to free all nodes
 */
list::~list() {
    while (head != nullptr) {
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }
}

}  // namespace linked_list
}  // namespace data_structures

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test() {
    data_structures::linked_list::list L;
    L.insert(1);
    L.insert(2);
    L.insert(3);
    L.insert(4);
    L.insert(5);
    L.insert(6);

    assert(L.top() == 1);
    assert(L.last() == 6);

    L.reverseAll();

    assert(L.top() == 6);
    assert(L.last() == 1);

    std::cout << "All tests passed!" << std::endl;
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    test();
    return 0;
}