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
		}
		void append(int data) {
			if (head == nullptr) {
				this->prepend(data);
				return;
			}
			Node *ptr = head;
			while (ptr->next != nullptr) {
				ptr = ptr->next;
			}
			Node *node = new Node(data);
			ptr->next = node;
		}
		void display() {
			Node *ptr = head;
			while (ptr->next != nullptr) {
				cout << ptr->data << " ";
				ptr = ptr->next;
			}
			cout << ptr->data << "\n";
		}
		void deleteHead() {
			head = head->next;
			return;
		}
		void deleteValue(int data) {
			if (head->data == data) {
				this->deleteHead();
				return;
			}
			Node *ptr = head;
			while (ptr->next != nullptr) {
				if (ptr->next->data == data) {
					ptr->next = ptr->next->next;
					return;
				}
				ptr = ptr->next;
			}
		}
		void pop() {
			Node *ptr = head;
			while (ptr->next->next != nullptr) 
				ptr = ptr->next;
			ptr->next = nullptr;
		}
		void reverse() {
			Node *prev = nullptr, *current = head, *next = nullptr;
			while(current != nullptr) {
				next = current->next;
				current->next = prev;
				prev = current;
				current = next;
			}
			head = prev;
		}
};

int main() {
	List nums;
	nums.append(1);
	nums.append(2);
	nums.append(3);
	nums.append(4);
	nums.append(5);
	nums.deleteValue(1);	
	nums.deleteValue(3);
	nums.pop();
	nums.prepend(0);	
	nums.reverse();
	nums.display();
	return 0;
}
