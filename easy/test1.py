#!/usr/bin/env python3

"""
Python Coding Interview Questions (1 Hour)
----------------------------------------
A set of coding challenges covering fundamental Python concepts.
Author: [Your Name]
Date: [Current Date]
"""

from typing import List
import time
from collections import Counter

class TreeNode:
    """Binary Tree Node class for Problem 4"""
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Problem 1: String Processing
def first_unique_char(s: str) -> int:
    """
    Find the first non-repeating character in a string and return its index.
    Args:
        s (str): Input string
    Returns:
        int: Index of first unique character, or -1 if none exists
    """
    char_count = Counter(s)
    for idx, char in enumerate(s):
        if char_count[char] == 1:
            return idx
    return -1


# Problem 2: Array Processing
def max_subarray_sum(nums: List[int]) -> int:
    """
    Find the maximum sum of any contiguous subarray within the list.
    Args:
        nums (List[int]): List of integers
    Returns:
        int: Maximum sum of any contiguous subarray
    """
    if not nums:
        return 0
    current_sum = max_sum = nums[0]
    for num in nums[1:]:
        current_sum = max(num, current_sum + num)
        max_sum = max(max_sum, current_sum)
    return max_sum


# Problem 3: Data Structure Implementation
class Queue:
    """
    Queue implementation using two stacks.
    Operations: push(x), pop(), peek(), empty()
    """

    def __init__(self):
        """Initialize your data structure here."""
        self.stack1 = []
        self.stack2 = []

    def push(self, x: int) -> None:
        """Push element x to the back of queue."""
        self.stack1.append(x)

    def pop(self) -> int:
        """Remove and return the element from the front of queue."""
        if not self.stack2:
            while self.stack1:
                self.stack2.append(self.stack1.pop())
        return self.stack2.pop()

    def peek(self) -> int:
        """Get the front element."""
        if not self.stack2:
            while self.stack1:
                self.stack2.append(self.stack1.pop())
        return self.stack2[-1]

    def empty(self) -> bool:
        """Return whether the queue is empty."""
        return len(self.stack1) == 0 and len(self.stack2) == 0


# Problem 4: Binary Search Tree Validation
def is_valid_bst(root: TreeNode) -> bool:
    """
    Determine if a binary tree is a valid binary search tree (BST).
    Args:
        root (TreeNode): Root node of the binary tree
    Returns:
        bool: True if the tree is a valid BST, False otherwise
    """
    def validate(node: TreeNode, min_val: float, max_val: float) -> bool:
        if not node:
            return True
        if node.val <= min_val or node.val >= max_val:
            return False
        return (validate(node.left, min_val, node.val) and
                validate(node.right, node.val, max_val))

    return validate(root, float('-inf'), float('inf'))


def run_tests() -> None:
    """Run test cases for all problems"""

    print("\n=== Running Tests ===\n")
    start_time = time.time()
    
    # Problem 1 Tests
    print("Testing Problem 1: First Unique Character")
    try:
        assert first_unique_char("leetcode") == 0
        assert first_unique_char("loveleetcode") == 2
        assert first_unique_char("aabb") == -1
        print("✓ All tests passed!")
    except AssertionError:
        print("✗ Test failed!")
    
    # Problem 2 Tests
    print("\nTesting Problem 2: Maximum Subarray Sum")
    try:
        assert max_subarray_sum([-2, 1, -3, 4, -1, 2, 1, -5, 4]) == 6
        assert max_subarray_sum([1]) == 1
        assert max_subarray_sum([-1, -2, -3]) == -1
        print("✓ All tests passed!")
    except AssertionError:
        print("✗ Test failed!")
    
    # Problem 3 Tests
    print("\nTesting Problem 3: Queue Implementation")
    try:
        queue = Queue()
        queue.push(1)
        queue.push(2)
        assert queue.peek() == 1
        assert queue.pop() == 1
        assert queue.empty() == False
        print("✓ All tests passed!")
    except AssertionError:
        print("✗ Test failed!")
    
    # Problem 4 Tests
    print("\nTesting Problem 4: Valid BST")
    try:
        # Test Case 1: Valid BST
        #     2
        #    / \
        #   1   3
        node1 = TreeNode(2)
        node1.left = TreeNode(1)
        node1.right = TreeNode(3)
        assert is_valid_bst(node1) == True

        # Test Case 2: Invalid BST
        #     5
        #    / \
        #   1   4
        #      / \
        #     3   6
        node2 = TreeNode(5)
        node2.left = TreeNode(1)
        node2.right = TreeNode(4)
        node2.right.left = TreeNode(3)
        node2.right.right = TreeNode(6)
        assert is_valid_bst(node2) == False
        print("✓ All tests passed!")
    except AssertionError:
        print("✗ Test failed!")
    end_time = time.time()
    print(f"\nAll tests completed in {end_time - start_time:.2f} seconds")


def print_problem_description(problem_num: int, description: str) -> None:
    """Helper function to print problem descriptions nicely"""
    print(f"\nProblem {problem_num}")
    print("=" * 40)
    print(description)
    print("-" * 40)


def main():
    """Main function to run the interview problems"""
    print("\nPython Coding Interview Questions")
    print("================================")
    print("Time allowed: 1 hour")
    print("Instructions:")
    print("- Implement the solution for each problem")
    print("- Use only standard Python libraries")
    print("- Focus on both correctness and code quality")
    print("- Run this script to test your solutions")
    problems = {
        1: "Find the first non-repeating character in a string and return its index.",
        2: "Find the maximum sum of any contiguous subarray within the list.",
        3: "Implement a Queue using two stacks with push, pop, peek, and empty operations.",
        4: "Determine if a binary tree is a valid binary search tree (BST)."
    }
    for num, desc in problems.items():
        print_problem_description(num, desc)
    run_tests()


if __name__ == "__main__":
    main()
