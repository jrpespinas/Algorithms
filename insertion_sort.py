"""
    Introduction to Algorithms: Insertion Sort using Python
"""
from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

__version__: '1.0.0'
__author__: 'Jan Rodolf Espinas'

def insertion_sort(A):
    """
        Takes an (un)sorted `list` and returns the list after 
        using Insertion Sort.

        Parameters
        ----------
        A: list
            list of (un)sorted numbers
        
        Returns
        -------
        A: list
            sorted list
    """
    print(A)
    # [j = 5, key(1) = 2, 4, 6, 1, 3]

    for i in range(1, len(A)):
        key = A[i]
        j = i - 1
        while key < A[j] and j >= 0:
            A[j+1] = A[j]
            j -= 1
        A[j + 1] = key
    return A

def main():
    print("Insertion Sort")
    A = [5,2,4,6,1,3]
    A = InsertionSort(A)
    print(A)

if __name__ == '__main__':
    main()