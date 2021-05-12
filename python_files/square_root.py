"""Finding the square root of an input by approximation"""


def approximate_guess(num: float, guess: float):
    return (guess + (num / guess)) / 2


def approximation(num: float, guess: float):
    return abs(num - (guess * guess))


def approximate_square_root(num: float, guess: float, tolerance: int = 1e-7):

    while approximation(num, guess) > tolerance:
        guess = approximate_guess(num, guess)
        print(guess)

    return guess


def main():
    num = float(input("Find the square root of: "))
    guess = float(input("Guess: "))
    print(approximate_square_root(num, guess))


if __name__ == "__main__":
    main()
