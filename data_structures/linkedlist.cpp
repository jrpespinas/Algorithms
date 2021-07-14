#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *next;
		Node(int data){
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
			if (head==nullptr) {
				this->prepend(data);
				return;
			}
			Node *ptr = head;
			Node *node = new Node(data);
			while(ptr->next != nullptr) {
				ptr = ptr->next;
			}
			ptr->next = node;
		}
		void display() {
			Node *ptr = head;
			while(ptr->next != nullptr) {
				cout << ptr->data << " ";
				ptr = ptr->next;
			}
			cout << ptr->data << "\n";
		}
		int getHead() {
			return head->data;
		}
		void deleteHead() {
			head = head->next; 
			return;
		}
		void deleteValue(int val) {
			if (head == nullptr) return;
			if (head->data == val) this->deleteHead();	
			Node *ptr = head;
			while(ptr->next != nullptr) {
				if (ptr->next->data == val) {
					ptr->next = ptr->next->next;
					return;
				}
				ptr = ptr->next;
			}
		}
};

int main() {
	List nums;
	nums.append(1);
	nums.append(2);
	nums.display();
	nums.prepend(0);
	nums.prepend(-1);
	nums.deleteValue(-1);
	nums.display();
	cout << nums.getHead();
	return 0;
}
