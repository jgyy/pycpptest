#!/usr/bin/env python3

"""
60-Minute Python Coding Test
--------------------------
Test your Python skills with these fundamental programming challenges.
Focus on clean code and efficient solutions.
"""

from typing import List, Dict
import time
from collections import defaultdict

# Problem 1: List Processing
def merge_sorted_lists(list1: List[int], list2: List[int]) -> List[int]:
    """
    Merge two sorted lists into a single sorted list.
    Args:
        list1: First sorted list of integers
        list2: Second sorted list of integers
    Returns:
        Merged sorted list
    """
    # TODO: Implement this function
    pass

# Problem 2: Dictionary Manipulation
def group_anagrams(words: List[str]) -> Dict[str, List[str]]:
    """
    Group words that are anagrams of each other.
    Args:
        words: List of strings to group
    Returns:
        Dictionary with sorted characters as keys and lists of anagrams as values
    """
    # TODO: Implement this function
    pass

# Problem 3: String Manipulation
def compress_string(s: str) -> str:
    """
    Perform basic string compression using counts of repeated characters.
    Example: 'aabbbcccc' becomes 'a2b3c4'
    Args:
        s: Input string
    Returns:
        Compressed string if shorter than original, otherwise original string
    """
    # TODO: Implement this function
    pass

# Problem 4: Matrix Operations
def rotate_matrix(matrix: List[List[int]]) -> None:
    """
    Rotate a square matrix 90 degrees clockwise in-place.
    Args:
        matrix: Square matrix to rotate
    """
    # TODO: Implement this function
    pass

def run_tests():
    """Run test cases for all problems"""
    start_time = time.time()
    
    print("\nTesting Problem 1: Merge Sorted Lists")
    test_cases = [
        ([1,3,5], [2,4,6], [1,2,3,4,5,6]),
        ([1,2,3], [], [1,2,3]),
        ([], [1,2,3], [1,2,3]),
        ([1,1,1], [2,2,2], [1,1,1,2,2,2])
    ]
    for list1, list2, expected in test_cases:
        result = merge_sorted_lists(list1, list2)
        print(f"Input: {list1}, {list2}")
        print(f"Output: {result}")
        print(f"Expected: {expected}")
        print(f"{'✓ Passed' if result == expected else '✗ Failed'}\n")

    print("\nTesting Problem 2: Group Anagrams")
    words = ["eat", "tea", "tan", "ate", "nat", "bat"]
    result = group_anagrams(words)
    print(f"Input: {words}")
    print(f"Output: {result}")

    print("\nTesting Problem 3: String Compression")
    test_strings = [
        "aabbbcccc",
        "abcdef",
        "aabbaabb"
    ]
    for s in test_strings:
        result = compress_string(s)
        print(f"Input: {s}")
        print(f"Output: {result}\n")

    print("\nTesting Problem 4: Matrix Rotation")
    matrix = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]
    print("Original matrix:")
    for row in matrix:
        print(row)
    rotate_matrix(matrix)
    print("\nRotated matrix:")
    for row in matrix:
        print(row)

    end_time = time.time()
    print(f"\nAll tests completed in {end_time - start_time:.2f} seconds")

if __name__ == "__main__":
    print("\n60-Minute Python Coding Test")
    print("==========================")
    print("Instructions:")
    print("1. Implement solutions for all 4 problems")
    print("2. Focus on code clarity and efficiency")
    print("3. Run tests to verify your solutions")
    print("4. Time limit: 60 minutes")
    run_tests()
