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

class List{
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
				prepend(data);
				return;
			}
			Node *ptr = head;
			while(ptr->next != nullptr) {
				ptr = ptr->next;
			}
			Node *node = new Node(data);
			ptr->next = node;
		}
		void display() {
			Node *ptr = head;
			while(ptr->next != nullptr) {
				cout << ptr->data << " ";
				ptr = ptr->next;
			}
			cout  << ptr->data << "\n";
		}
		void popFirst(int data) {
			head = head->next;
			return;
		}
		void deleteValue(int data) {
			if (head == nullptr) return;
			if (head->data == data) {
				popFirst(data);
				return;
			}
			Node *ptr = head;
			while(ptr->next != nullptr) {
				if (ptr->next->data == data) {
					ptr->next = ptr->next->next;
					return;
				}
				ptr = ptr->next;
			}
		}
		void pop() {
			Node *ptr = head;
			while(ptr->next != nullptr) {
				if (ptr->next->next == nullptr) {
					ptr->next = nullptr;
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
	nums.prepend(0);
	nums.display();
	nums.deleteValue(1);
	nums.pop();
	nums.display();
	return 0;
}
