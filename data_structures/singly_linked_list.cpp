#include <iostream>
using namespace std;

class Node {
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
			head = nullptr;
		}
		void prepend(int data) {
			Node *node = new Node(data);
			node->next = head;
			head = node;
			return;
		}
		void append(int data) {
			if (head == nullptr) {
				this->prepend(data);
				return;
			}	
			Node *ptr = head;
			while(ptr->next != nullptr) {
				ptr = ptr->next;
			}
			Node *node = new Node(data);
			ptr->next = node;
			return;
		}
		void display() {
			Node *ptr = head;
			while(ptr != nullptr) {
				cout << ptr->data << " ";
				ptr = ptr->next;
			}
			return;
		}
};

int main() {
	List nums;
	nums.append(1);
	nums.append(2);
	nums.append(3);
	nums.append(4);
	nums.append(5);
	// nums.deleteValue(1);	
	// nums.deleteValue(3);
	// nums.pop();
	nums.prepend(0);	
	// nums.reverse();
	nums.display();
	return 0;
}
