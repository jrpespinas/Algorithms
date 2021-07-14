#include <bits/stdc++.h>
using namespace std;

class Node {
	public:
		int data;
		Node *next;
		Node(int data) {
			this->data = data;
		}
};

class List {
	Node *head;
	public:
		List() {
			head=NULL;
		}
		void prepend(int data) {
			Node *node = new Node(data);
			node->next = head;
			head = node;
		}
		void append(int data) {
			if (head == NULL) {
				this->prepend(data);
				return;
			}
			Node *node = new Node(data);
			node->next = NULL;
			Node *temp = head;
			while(temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = node;
		}
		void display() {
			Node *temp = head;
			while(temp->next != NULL) {
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << temp->data << "\n";
		}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	List test;	
	test.append(1);	
	test.append(2);
	test.prepend(0);
	test.display();
	return 0;
}
