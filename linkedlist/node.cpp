
#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node *next;

    Node() {
        val = 0;
        next = nullptr;
    }

    Node(int value) {
        val = value;
        next = nullptr;
    }

    Node(int value, Node *nextNode) {
        val = value;
        next = nextNode;
    }
};

class LinkedList {
private:
    Node *head = nullptr;

public:

    void append(int value) {
        Node *newNode = new Node(value);
        if (head == nullptr)
            head = newNode;
        else {
            Node *current = head;
            while (current->next != nullptr)
                current = current->next;
            current->next = newNode;
        }
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void deleteList() {
        Node *current = head;
        while (current != nullptr) {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }

    void printNode(Node *node) {
        if (node == nullptr) return;
        else {
            cout << node << " " << node->val << " " << node->next << endl;
        }

    }

    void printList() {
        Node *current = head;
        while (current != nullptr) {
            cout << current << " " << current->val << " " << current->next << endl;
            current = current->next;
        }
        cout << "-------------------------------------" << endl;
    }

    Node *findNode(int value) {
        Node *current = head;
        while (current != nullptr) {
            if (current->val == value)
                return current;
            current = current->next;
        }
        return nullptr;
    }

    Node *findPrev(Node *ptr) {
        Node *current = head;
        while (current != nullptr && current->next != ptr)
            current = current->next;
        return current;
    }

    Node *findNext(Node *ptr) {
        if (ptr != nullptr)
            return ptr->next;
        else
            return nullptr;
    }

    void insertNext(Node *ptr, int value) {
        if (ptr == nullptr)
            throw -1;

        Node *newNode = new Node(value);
        newNode->next = ptr->next;
        ptr->next = newNode;
    }

    void insertPrev(Node *ptr, int value) {
        if (ptr == nullptr)
            throw -1;

        Node *prevNode = findPrev(ptr);
        if (prevNode == nullptr) {
            Node *newNode = new Node(value);
            newNode->next = head;
            head = newNode;
        } else {
            Node *newNode = new Node(value);
            newNode->next = ptr;
            prevNode->next = newNode;
        }
    }

    void deleteNode(Node *ptr) {
        if (ptr == nullptr || head == nullptr)
            throw -1;

        if (ptr == head) {
            head = ptr->next;
            delete ptr;
        } else {
            Node *prevNode = findPrev(ptr);
            if (prevNode != nullptr) {
                prevNode->next = ptr->next;
                delete ptr;
            }
        }
    }

    void swapNodewithprevious(Node *ptr) {
        if (ptr == nullptr)
            return;

        Node *prevNode = findPrev(ptr);
        Node *prevPrevNode = findPrev(prevNode);

        if (prevPrevNode == nullptr) {
            head = ptr;
        } else {
            prevPrevNode->next = ptr;
        }

        prevNode->next = ptr->next;
        ptr->next = prevNode;

    }

    void swapNodewithnext(Node *ptr) {
        if (ptr == nullptr)
            return;


        Node *nextNode = ptr->next;
        ptr->next = nextNode->next;
        nextNode->next = ptr;

        Node *prevNode = findPrev(ptr);
        if (prevNode == nullptr)
            head = nextNode;
        else
            prevNode->next = nextNode;

    }

    void insertAtBeginning(int value) {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }


};


int main() {
    LinkedList list;
    for (int i = 1; i < 7; i++)
        list.append(i);

    list.printList();
    cout << "Node with value 3: ";
    list.printNode(list.findNode(3));
    cout << "---------------" << '\n';

    list.append(6);
    list.printList();

    list.insertNext(list.findNode(3), 3);
    list.printList();

    list.insertPrev(list.findNode(5), 4);
    list.printList();

    list.deleteNode(list.findNode(2));
    list.printList();

    list.insertAtBeginning(312);
    list.swapNodewithprevious(list.findNode(5));
    list.printList();


    return 0;
}