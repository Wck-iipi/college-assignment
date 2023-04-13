#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
public:
    CircularLinkedList() : head(nullptr) {}

    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void display() {
        if (!head) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* temp = head;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    }

    ~CircularLinkedList() {
        if (!head) {
            return;
        }

        Node* current = head;
        Node* nextNode = head->next;
        while (nextNode != head) {
            delete current;
            current = nextNode;
            nextNode = nextNode->next;
        }
        delete current;
    }

private:
    Node* head;
};

int main() {
    CircularLinkedList circularList;
    circularList.append(5);
    circularList.append(10);
    circularList.append(15);
    circularList.append(20);

    std::cout << "Circular Linked List is as follows: ";
    circularList.display();
    return 0;
}
