# Python Coding Test
# Time limit: 60 minutes
# Instructions: Complete all the functions below according to their specifications.
# Each function has its own test cases that must pass.

def reverse_string(s: str) -> str:
    """
    Task 1: Reverse a string without using built-in reverse functions.
    Args:
        s (str): Input string
    Returns:
        str: Reversed string
    Example:
        >>> reverse_string("hello")
        "olleh"
    """
    # TODO: Implement this function
    result = ""
    for i in range(len(s) - 1, -1, -1):
        result += s[i]
    return result


def find_missing_number(nums: list) -> int:
    """
    Task 2: Find the missing number in a sequence from 0 to n.
    Given an array containing n distinct numbers in the range [0, n],
    return the only number in the range that is missing from the array.
    Args:
        nums (List[int]): List of numbers from 0 to n with one number missing
    Returns:
        int: The missing number
    Example:
        >>> find_missing_number([3,0,1])
        2
    """
    # TODO: Implement this function
    n = len(nums)
    expected_sum = (n * (n + 1)) / 2
    actual_sum = sum(nums)
    return expected_sum - actual_sum


def is_balanced_parentheses(s: str) -> bool:
    """
    Task 3: Check if a string of parentheses is balanced.
    Args:
        s (str): String containing only parentheses '(' and ')'
    Returns:
        bool: True if parentheses are balanced, False otherwise
    Example:
        >>> is_balanced_parentheses("((()))")
        True
        >>> is_balanced_parentheses("(()")
        False
    """
    # TODO: Implement this function
    count = 0
    for char in s:
        if char == '(':
            count += 1
        elif char == ')':
            count -= 1
        if count < 0:
            return False
    return count == 0


def merge_sorted_lists(list1: list, list2: list) -> list:
    """
    Task 4: Merge two sorted lists into a single sorted list.
    Args:
        list1 (List[int]): First sorted list
        list2 (List[int]): Second sorted list
    Returns:
        List[int]: Merged sorted list
    Example:
        >>> merge_sorted_lists([1,3,5], [2,4,6])
        [1,2,3,4,5,6]
    """
    # TODO: Implement this function
    result = []
    i = j = 0
    while i < len(list1) and len(list2):
        if list1[i] <= list2[j]:
            result.append(list1[i])
            i += 1
        else:
            result.append(list2[j])
            j += 1
    while i < len(list1):
        result.append(list1[i])
        i += 1
    while j < len(list2):
        result.append(list2[j])
        j += 1
    return result


# Test cases
def run_tests():
    # Test Task 1
    assert reverse_string("hello") == "olleh"
    assert reverse_string("python") == "nohtyp"
    assert reverse_string("") == ""
    # Test Task 2
    assert find_missing_number([3,0,1]) == 2
    assert find_missing_number([0,1,3,4]) == 2
    assert find_missing_number([9,6,4,2,3,5,7,0,1]) == 8
    # Test Task 3
    assert is_balanced_parentheses("((()))") == True
    assert is_balanced_parentheses("(()") == False
    assert is_balanced_parentheses(")(") == False
    assert is_balanced_parentheses("") == True
    # Test Task 4
    assert merge_sorted_lists([1,3,5], [2,4,6]) == [1,2,3,4,5,6]
    assert merge_sorted_lists([1], []) == [1]
    assert merge_sorted_lists([], [1]) == [1]
    assert merge_sorted_lists([1,2,3], [1,2,3]) == [1,1,2,2,3,3]
    print("All tests passed!")

if __name__ == "__main__":
    run_tests()
