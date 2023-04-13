#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedListStack {
public:
    LinkedListStack() : topNode(nullptr) {}

    ~LinkedListStack() {
        while (topNode) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (topNode) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        } else {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
        }
    }

    int top() {
        if (topNode) {
            return topNode->data;
        } else {
            std::cout << "Stack is empty." << std::endl;
            return -1;
        }
    }

    bool isEmpty() {
        return topNode == nullptr;
    }

private:
    Node* topNode;
};

int main() {
    LinkedListStack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.top() << std::endl;

    stack.pop();

    std::cout << "Top element after pop: " << stack.top() << std::endl;

    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
