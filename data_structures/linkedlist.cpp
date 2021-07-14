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
			head=nullptr;
		}
		void prepend(int data) {
			Node *node = new Node(data);
			node->next = head;
			head = node;
		}
		void append(int data) {
			if (head==nullptr) {
				this->prepend(data);
				return;
			}
			Node *node = new Node(data);	
			Node *tmp = head;
			while(tmp->next != nullptr) {
				tmp = tmp->next;
			}
			tmp->next = node;
		}
		void display() {
			Node *tmp = head;
			while(tmp->next != nullptr) {
				cout << tmp->data << " ";
				tmp = tmp->next;
			}
			cout << tmp->data << "\n";
		}
		int getHead() {
			return head->data;
		}
};

int main() {
	List test;
	test.append(1);
	test.append(2);
	test.prepend(0);
	cout << test.getHead();
	return 0;
}
