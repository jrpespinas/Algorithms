class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class SLList:
    def __init__(self):
        self.head = None

    def print_list(self):
        if not self.head:
            return None

        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")
        return

    def prepend(self, node: Node):
        if not self.head:
            self.head = node
            return

        node.next = self.head
        self.head = node
        return

    def append(self, node: Node):
        if not self.head:
            self.prepend(node)
            return

        current = self.head
        while current.next:
            current = current.next
        current.next = node
        return


n1 = Node(1)
n2 = Node(2)
list = SLList()
list.append(n1)
list.prepend(n2)
list.print_list()
