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
