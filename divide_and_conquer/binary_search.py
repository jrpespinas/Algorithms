def search_iterative(array, item):
    """a function which divides the input per iteration
    until the guess is equal to the item being searched"""
    low = 0
    high = len(array) - 1

    while low <= high:
        mid = (low + high) // 2
        guess = array[mid]

        if guess == item:
            return mid
        elif guess < item:
            low = mid + 1
        else:
            high = mid - 1

    return None

def search_recursive(array, item, high, low):
    """a recursive function which divides the input per Step
    until the guess is equal to the item being searched
    """
    if low <= high:
        mid = (high + low) // 2
        guess = array[mid]

        if guess == item:
            return mid
        elif guess < item:
            return search_recursive(array, item, high, mid + 1)
        else:
            return search_recursive(array, item, mid - 1, low)
    else:
        return None


