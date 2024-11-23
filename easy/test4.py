#!/usr/bin/env python3

"""
60-Minute Python Coding Test
---------------------------
Test your Python skills with these fundamental programming challenges.
Instructions:
- Implement all functions according to their docstrings
- Use only Python standard library (no external packages)
- Focus on code clarity, efficiency, and proper error handling
- Run tests to verify your solutions
"""

from typing import List, Dict, Optional
from collections import defaultdict
import time

# Problem 1: Array Operations
def find_peak_elements(nums: List[int]) -> List[int]:
    """
    Find all peak elements in a list. A peak element is greater than its adjacent neighbors.
    Edge elements are peaks if they are greater than their single neighbor.
    Example:
    Input: [1, 3, 2, 4, 1, 5, 2]
    Output: [1, 3, 5] (indices of peaks: 3 > 1,2; 4 > 2,1; 5 > 1,2)
    Args:
        nums: List of integers
    Returns:
        List of indices where peak elements are found
    """
    # TODO: Implement this function
    if not nums:
        return []
    peaks = []
    if len(nums) == 1:
        return [0]
    if nums[0] > nums[1]:
        peaks.append(0)
    for i in range(1, len(nums) - 1):
        if nums[i] > nums[i - 1] and nums[i] > nums[i + 1]:
            peaks.append(i)
    if nums[-1] > nums[-2]:
        peaks.append(len(nums) - 1)
    return peaks


# Problem 2: Dictionary Processing
def most_frequent_k_elements(items: List[str], k: int) -> List[str]:
    """
    Find the k most frequently occurring items in the list.
    If there's a tie, prefer items that appeared earlier in the list.
    Example:
    Input: items=["apple", "banana", "apple", "orange", "banana", "grape"], k=2
    Output: ["apple", "banana"]
    Args:
        items: List of strings
        k: Number of top frequent items to return
    Returns:
        List of k most frequent items
    """
    # TODO: Implement this function
    if not items or k <= 0:
        return []
    freq = {}
    order = []
    for item in items:
        if item not in freq:
            freq[item] = 1
            order.append(item)
        else:
            freq[item] += 1
    sorted_items = sorted(order, key=lambda x: (-freq[x], order.index(x)))
    return sorted_items[:k]


# Problem 3: Class Implementation
class FileSystem:
    """
    Implement a simple in-memory file system with directories and files.
    Support operations:
    - mkdir(path): Create a new directory
    - add_file(path, content): Create or update a file
    - read_file(path): Get file content
    - ls(path): List contents of directory
    - rm(path): Remove file or directory (if empty)
    Example:
    fs = FileSystem()
    fs.mkdir("/home/user")
    fs.add_file("/home/user/doc.txt", "Hello")
    fs.read_file("/home/user/doc.txt")  # Returns: "Hello"
    fs.ls("/home/user")  # Returns: ["doc.txt"]
    """

    def __init__(self):
        """Initialize the file system"""
        # TODO: Initialize your data structures
        self.dirs = {'/': set()}
        self.files = {}

    def _get_parent_dir(self, path: str) -> str:
        return '/'.join(path.split('/')[:-1]) or '/'

    def _path_exists(self, path: str) -> bool:
        return path in self.dirs or path in self.files

    def mkdir(self, path: str) -> bool:
        """
        Create a new directory. Return False if directory exists or parent missing.
        Args:
            path: Absolute path for new directory
        Returns:
            Success status
        """
        # TODO: Implement this method
        if path == '/' or self._path_exists(path):
            return False
        parent = self._get_parent_dir(path)
        if parent not in self.dirs:
            return False
        self.dirs[path] = set()
        self.dirs[parent].add(path.split('/')[-1])
        return True

    def add_file(self, path: str, content: str) -> bool:
        """
        Create or update a file. Return False if parent directory missing.
        Args:
            path: Absolute path for file
            content: File content
        Returns:
            Success status
        """
        # TODO: Implement this method
        if path == '/':
            return False
        parent = self._get_parent_dir(path)
        if parent not in self.dirs:
            return False
        filename = path.split('/')[-1]
        self.files[path] = content
        self.dirs[parent].add(filename)
        return True

    def read_file(self, path: str) -> Optional[str]:
        """
        Read file content. Return None if file doesn't exist.
        Args:
            path: Absolute path to file
        Returns:
            File content or None
        """
        # TODO: Implement this method
        return self.files.get(path)

    def ls(self, path: str) -> List[str]:
        """
        List contents of directory.
        Args:
            path: Absolute path to directory
        Returns:
            List of items in directory (empty if directory doesn't exist)
        """
        # TODO: Implement this method
        if path in self.dirs:
            return sorted(list(self.dirs[path]))
        return []

    def rm(self, path: str) -> bool:
        """
        Remove file or empty directory. Return False if not found or directory not empty.
        Args:
            path: Absolute path to remove
        Returns:
            Success status
        """
        # TODO: Implement this method
        if path == '/':
            return False
        parent = self._get_parent_dir(path)
        name = path.split('/')[-1]
        if path in self.dirs:
            if self.dirs[path]:
                return False
            del self.dirs[path]
            self.dirs[parent].remove(name)
            return True
        if path in self.files:
            del self.files[path]
            self.dirs[parent].remove(name)
            return True
        return False

# Problem 4: String Compression

def compressedString(word: str) -> str:
    """
    Compress a string by counting consecutive characters (up to 9 occurrences).
    Each group is represented by the count followed by the character.
    Args:
        word: Input string to compress
    Returns:
        Compressed string in format: count + character for each group
    Example:
        'aabbbcccc' -> '2a3b4c'
        'wwwwwwwwwww' -> '9w2w' (max 9 characters per group)
    """
    # TODO: Implement this method
    if not word:
        return ""
    comp = []
    i = 0
    while i < len(word):
        count = 1
        while i + 1 < len(word) and word[i] == word[i + 1] and count < 9:
            count += 1
            i += 1
        comp.append(f'{count}{word[i]}')
        i += 1
    return "".join(comp)


def run_tests():
    """Run comprehensive test cases for all problems"""
    test_peak_elements()
    test_frequent_elements()
    test_filesystem()
    test_string_compression()


def test_peak_elements():
    print("\n=== Testing Peak Elements ===")
    test_cases = [
        ([1, 3, 2, 4, 1, 5, 2], [1, 3, 5]),
        ([1, 2, 1, 3, 5, 6, 4], [1, 5]),
        ([1], [0]),
        ([1, 2], [1]),
        ([2, 1], [0]),
        ([1, 2, 1], [1]),
        ([], []),
        ([1, 1, 1], []),
        ([3, 1, 4, 1, 5, 9, 2, 6], [0, 2, 5, 7])
    ]

    for nums, expected in test_cases:
        result = find_peak_elements(nums)
        print(f"Input: {nums}")
        print(f"Expected: {expected}")
        print(f"Got: {result}")
        assert result == expected, f"Test failed: expected {expected}, got {result}"
        print("✓ Test passed\n")

def test_frequent_elements():
    print("\n=== Testing Most Frequent Elements ===")
    test_cases = [
        (["apple", "banana", "apple", "orange", "banana", "grape"], 2, ["apple", "banana"]),
        (["a", "b", "b", "c", "c", "c"], 2, ["c", "b"]),
        ([], 3, []),
        (["x", "y", "z"], 1, ["x"]),
        (["a", "a", "b", "b"], 2, ["a", "b"]),
        (["red", "blue", "red", "green", "blue", "red"], 3, ["red", "blue", "green"]),
        (["x"], 5, ["x"])
    ]
    for items, k, expected in test_cases:
        result = most_frequent_k_elements(items, k)
        print(f"Input: items={items}, k={k}")
        print(f"Expected: {expected}")
        print(f"Got: {result}")
        assert result == expected, f"Test failed: expected {expected}, got {result}"
        print("✓ Test passed\n")


def test_filesystem():
    print("\n=== Testing FileSystem ===")
    fs = FileSystem()

    # Test mkdir
    assert fs.mkdir("/home"), "mkdir /home failed"
    assert fs.mkdir("/home/user"), "mkdir /home/user failed"
    assert not fs.mkdir("/home/user"), "mkdir existing dir should fail"
    assert not fs.mkdir("/nonexistent/dir"), "mkdir with missing parent should fail"

    # Test add_file
    assert fs.add_file("/home/user/doc.txt", "Hello"), "add_file failed"
    assert fs.add_file("/home/user/doc.txt", "Updated"), "update file failed"
    assert not fs.add_file("/nonexistent/file.txt", "content"), "add_file with missing parent should fail"

    # Test read_file
    assert fs.read_file("/home/user/doc.txt") == "Updated", "read_file failed"
    assert fs.read_file("/nonexistent.txt") is None, "read nonexistent file should return None"

    # Test ls
    assert set(fs.ls("/home/user")) == {"doc.txt"}, "ls failed"
    assert fs.ls("/nonexistent") == [], "ls nonexistent dir should return empty list"

    # Test rm
    assert not fs.rm("/home"), "rm non-empty dir should fail"
    assert fs.rm("/home/user/doc.txt"), "rm file failed"
    assert fs.rm("/home/user"), "rm empty dir failed"
    assert not fs.rm("/nonexistent"), "rm nonexistent path should fail"

    print("✓ All FileSystem tests passed\n")


def test_string_compression():
    print("\n=== Testing String Compression ===")
    test_cases = [
        # Basic cases
        ("aabbbcccc", "2a3b4c"),
        ("a", "1a"),
        ("aaa", "3a"),

        # Empty string
        ("", ""),

        # Single character repeated more than 9 times
        ("aaaaaaaaaa", "9a1a"),  # 10 a's
        ("aaaaaaaaaaaa", "9a3a"),  # 12 a's

        # Alternating characters
        ("abababab", "1a1b1a1b1a1b1a1b"),

        # Mixed lengths
        ("aaabbbccccdddddeeeee", "3a3b4c5d5e"),

        # Case sensitivity
        ("AAAaaa", "3A3a"),

        # Complex patterns
        ("aabbccaabbcc", "2a2b2c2a2b2c"),
        ("abcabcabc", "1a1b1c1a1b1c1a1b1c"),

        # Edge cases with max repetition
        ("wwwwwwwwww", "9w1w"),  # 10 w's
        ("zzzzzzzzzzzzzzz", "9z6z")  # 15 z's
    ]

    for input_str, expected in test_cases:
        result = compressedString(input_str)
        print(f"Input: '{input_str}'")
        print(f"Expected: '{expected}'")
        print(f"Got: '{result}'")
        assert result == expected, f"Test failed: expected '{expected}', got '{result}'"
        print("✓ Test passed\n")


if __name__ == "__main__":
    run_tests()
