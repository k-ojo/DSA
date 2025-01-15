#!/bin/python3



def findMax(arr):
    """finds the maximum number of a list
    
    Parameters:
    arr (int, float): array of numbers
    
    Returns: int, float: the maximum member of arr
    """
    try:
        cmax = arr[0]
    except:
        return None
    for x in arr:
        if x > cmax:
            cmax = x
    return x


def count_occurences(arr, n):
    count = 0
    """
    Count the number of occurrences of n in the array.

    Parameters:
    arr (list): The array to search in.
    n (any): The element to count.

    Returns:
    int: The number of times n appears in arr.
    """
    for element in arr:
        if element == n:
            count = count + 1
    return count

def aSorted(arr):
    i = 1
    for el in arr:
        try:
            if el <= arr[i]:
                i = i + 1
            else:
                return False
        except IndexError:
            return True

def bSorted(arr):
    i = 1
    for el in arr:
        try:
            if el >= arr[i]:
                i = i + 1
            else:
                return False
        except IndexError:
            return True

def isSorted(arr):
    if aSorted(arr) or bSorted(arr):
        return True
    return False            

    

if __name__ == "__main__":
    var = [1, 4, 6, 8, 9, 7, 9, 0, 4, 7]
    arr = []
    print(isSorted(var))
    var.sort()
    print(var)
    print(findMax(arr))
    print(isSorted(var))
    print(f"Max in var is: {findMax(var)}\n"
    f"Number of Occurences of 7 in var is {count_occurences(var, 7)}"
    )