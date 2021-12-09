#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
};

class List {
    Node *head;
    public:
        List() {
            this->head = nullptr;
        }
        void prepend(int data) {
            Node *node = new Node(data);
            node->next = head;
            head = node;
            return;
        }
        void append(int data) {
            if (this->head == nullptr) {
                this->prepend(data);
                return;
            } else {
                Node *ptr = head;
                while(ptr->next != nullptr) {
                    ptr = ptr->next;
                }
                Node *node = new Node(data);
                ptr->next = node;
                return;
            }
        }
        void display() {
            Node *ptr = head;
            while (ptr->next != nullptr) {
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
            cout << ptr->data << "\n";
            return;
        }
};

int main() {
    List nums;
    nums.append(1);
    nums.append(2);
    /* nums.deleteVal(1); */
    /* nums.pop(); */
    /* nums.prepend(0); */
    /* nums.reverse(); */
    nums.display();
}
