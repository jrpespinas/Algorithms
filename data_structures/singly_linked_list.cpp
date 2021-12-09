#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(data) {
            this->data = data;
            this->next = nullptr;
        }
}

class List {
    Node *head;
    public:
        List() {
            this->head = nullptr;
        }
        void prepend(data) {
            Node *node = new Node(data);
            node->next = head;
            head = node;
            return;
        }
        void append(data) {
            if (this->head == nullptr) {
                this->prepend(data);
                return;
            }
        }

}

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
