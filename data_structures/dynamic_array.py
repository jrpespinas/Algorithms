import ctypes


class Array:
    __length: int
    __capacity: int
    __array: ctypes.py_object

    def __init__(self, capacity: int = 1):
        self.__length = 0
        self.__capacity = capacity
        self.__array = self.make_array(capacity)

    def __len__(self):
        return self.__length

    def __getitem__(self, index: int):
        if not 0 <= index < self.__length:
            return IndexError("Out of bounds")
        return self.__array[index]

    def is_empty(self):
        return self.__len__() == 0

    def make_array(self, capacity: int):
        return (capacity * ctypes.py_object)()
