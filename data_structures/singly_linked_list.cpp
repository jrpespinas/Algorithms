#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node (int data) {
            this->data = data;
            this->next = nullptr;
        }
};

class List {
    int length;
    Node *head;
    public:
        List() {
            this->length = 0;
            this->head = nullptr;
        }

        // CREATE METHODS
        void prepend(int data) {
            Node *node = new Node(data);
            node->next = this->head;
            this->head = node;
            this->length++;
            return;
        }
        void append(int data) {
            if (this->head == nullptr) {
                this->prepend(data);
                return;
            } else {
                Node *ptr = this->head;
                while (ptr->next != nullptr) {
                    ptr = ptr->next;
                }
                Node *node = new Node(data);
                ptr->next = node;
                this->length++;
                return;
            }
        }

        // READ METHODS
        void display() {
            Node *ptr = this->head;
            while(ptr->next != nullptr) {
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
            cout << ptr->data << "\n";
            return;
        }
        int length() {
           return this->length;
        }

        // DELETE METHODS
        void popHead() {
            this->head = this->head->next;
            this->length--;
            return;
        }
        void deleteVal(int data) {
            if (this->head == data) {
                this->popHead();
                return;
            } else {
                Node *ptr = this->head;
                while (ptr->next != nullptr) {
                    if (ptr->next->data != data) {
                        ptr->next = ptr->next->next;
                    }
                    ptr = ptr->next;
                }
                this->length--;
                return;
            }
        }
        void pop() {
            Node *ptr = this->head;
            while(ptr->next->next != nullptr) {
                ptr = ptr->next;
            }
            ptr->next = nullptr;
            this->length--;
            return;
        }
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    List nums;
    nums.pop();
    return 0;
}