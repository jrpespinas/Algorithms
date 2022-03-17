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
  int length;
  Node *head;

public:
  List() {
    this->length = 0;
    this->head = nullptr;
  }

  // CREATE METHODS
  void Prepend(int data) {
    Node *node = new Node(data);
    node->next = this->head;
    this->head = node;
    this->length++;
    return;
  }
  void Append(int data) {
    if (this->head == nullptr) {
      this->Prepend(data);
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
  void InsertAt(int index, int data) {
    if (this->head == nullptr || index == 0) {
      this->Prepend(data);
      return;
    } else if (index == this->length) {
      this->Append(data);
      return;
    } else if (index > this->length || index < 0) {
      cout << "Index out of bonds\n";
      return;
    } else {
      Node *ptr = this->head;
      for (int i = 1; i != index; i++) {
        ptr = ptr->next;
      }
      Node *node = new Node(data);
      node->next = ptr->next;
      ptr->next = node;
      this->length++;
      return;
    }
  }

  // READ METHODS
  void Display() {
    Node *ptr = this->head;

    if (this->length == 0) {
      cout << "Linked list is empty\n";
      return;
    }

    while (ptr->next != nullptr) {
      cout << ptr->data << " ";
      ptr = ptr->next;
    }
    cout << ptr->data << "\n";
    return;
  }

  // DELETE METHODS
  void PopHead() {
    this->head = this->head->next;
    this->length--;
    return;
  }
  void DeleteVal(int data) {
    if (this->head->data == data) {
      this->PopHead();
      return;
    } else {
      Node *ptr = this->head;
      while (ptr->next != nullptr) {
        if (ptr->next->data == data) {
          ptr->next = ptr->next->next;
        }
        ptr = ptr->next;
      }
      this->length--;
      return;
    }
  }
  void Pop() {
    Node *ptr = this->head;

    if (ptr->next == nullptr) {
      this->PopHead();
      return;
    }

    while (ptr->next->next != nullptr) {
      ptr = ptr->next;
    }
    ptr->next = nullptr;
    this->length--;
    return;
  }

  // UTILS
  int Length() { return this->length; }

  void Reverse() {
    if (this->head->next == nullptr) {
      return;
    } else {
      Node *prev = nullptr;
      Node *curr = this->head;
      Node *next = nullptr;

      while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
      }
      this->head = prev;
    }
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  List nums;
  nums.Append(1);
  nums.Append(2);
  nums.Append(3);
  nums.Append(4);
  nums.InsertAt(5, 5);
  nums.Display();
  return 0;
}