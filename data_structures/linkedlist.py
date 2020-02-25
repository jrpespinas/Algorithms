"""
    Data Structures and algorithms: Linked-list implementation using Python
"""
from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

__version__: '1.0.0'
__author__: 'Jan Rodolf Espinas'

class Node:
    def __init__(self, data, next = None):
        self.data = data 
        self.next = next

def main():
    A = Node("Head")    
    print(A.data)

if __name__ == "__main__":
    main()