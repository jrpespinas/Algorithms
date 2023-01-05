def search(array, item):
    """a function which divides the input per iteration
    until the guess is equal to the item being search"""
    low = 0
    high = len(array) - 1

    while low <= high:
        mid = (low + high) // 2
        guess = array[mid]

        if guess < item:
            low = mid + 1
        elif guess > item:
            high = mid - 1
        else:
            return mid

    return None
