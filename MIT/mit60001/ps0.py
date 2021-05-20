"""
MIT 6.0001 - Introduction to Computer Science and Programming in Python
Problem Set 0
-------------

1. Ask the user to enter a number `x`
2. Ask the user to enter a number `y`
3. Prints out number `x`, raised to the power of `y`
4. Prints out the log (base 2) of `x`
"""
import numpy as np


def raised_to_y(x: int, y: int):
    return x ** y


def main():
    x = int(input("X: "))
    y = int(input("y: "))
    print(raised_to_y(x, y))
    print(np.log2(x))


if __name__ == "__main__":
    main()
