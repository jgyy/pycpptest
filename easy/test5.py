#!/usr/bin/env python3

"""
60-Minute Python Coding Test (Easy Level)
---------------------------------------
Test your Python programming fundamentals with these coding challenges.
Time Limit: 60 minutes
Author: [Your Name]
Date: [Current Date]

Instructions:
- Implement all functions according to their docstrings
- Use only Python standard library (no external packages)
- Each problem is worth equal points
- Run tests to verify your solutions
"""

from typing import List, Dict, Set, Optional
from collections import defaultdict
import time
import re

# Problem 1: Text Analysis
def word_frequency(text: str, min_length: int = 3) -> Dict[str, int]:
    """
    Count frequency of words in a text, ignoring words shorter than min_length.
    Words should be case-insensitive and punctuation should be removed.
    Example:
    Input: "Hello, hello world! How are you doing today?", min_length=4
    Output: {'hello': 2, 'world': 1, 'doing': 1, 'today': 1}
    Args:
        text: Input text string
        min_length: Minimum word length to include (default: 3)
    Returns:
        Dictionary with words as keys and their frequencies as values
    """
    # TODO: Implement this function
    text = re.sub(r'[^\w\s]', '', text.lower())
    words = [word for word in text.split() if len(word) >= min_length]
    frequencies = defaultdict(int)
    for word in words:
        frequencies[word] += 1
    return dict(frequencies)


# Problem 2: Number Processing
def digital_root(num: int) -> int:
    """
    Calculate the digital root of a number by repeatedly summing its digits
    until a single-digit number is obtained.
    Example:
    Input: 16  -> 1 + 6 = 7
    Input: 942 -> 9 + 4 + 2 = 15 -> 1 + 5 = 6
    Args:
        num: Positive integer
    Returns:
        Single digit result after summing digits repeatedly
    Raises:
        ValueError: If num is negative
    """
    # TODO: Implement this function
    if num < 0:
        raise ValueError('Number must be non-negative')
    if num < 10:
        return num
    digit_sum = sum(int(d) for d in str(num))
    return digital_root(digit_sum)


# Problem 3: List Operations
def running_average(numbers: List[float], window_size: int) -> List[float]:
    """
    Calculate the running average of numbers using the specified window size.
    For elements where the window extends beyond list bounds, use available numbers.
    Round results to 2 decimal places.
    Example:
    Input: [1, 2, 3, 4, 5], window_size=3
    Output: [1.50, 2.00, 3.00, 4.00, 4.50]
    Explanation: 
    - First avg: (1 + 2)/2 = 1.50 (only 2 numbers available)
    - Second avg: (1 + 2 + 3)/3 = 2.00
    - Third avg: (2 + 3 + 4)/3 = 3.00
    - Fourth avg: (3 + 4 + 5)/3 = 4.00
    - Fifth avg: (4 + 5)/2 = 4.50 (only 2 numbers available)
    Args:
        numbers: List of numbers
        window_size: Size of the sliding window
    Returns:
        List of running averages
    """
    # TODO: Implement this function
    result = []
    for i in range(len(numbers)):
        start = max(0, i - window_size + 1)
        end = i + 1
        window = numbers[start:end]
        avg = sum(window) / len(window)
        result.append(round(avg, 2))
    return result


# Problem 4: Date String Manipulation
def format_date(date_str: str) -> str:
    """
    Convert between different date formats.
    Input format: Either "DD-MM-YYYY" or "MM/DD/YYYY"
    Output format: "YYYY-MM-DD"
    Example:
    Input: "23-04-2024" -> Output: "2024-04-23"
    Input: "04/23/2024" -> Output: "2024-04-23"
    Args:
        date_str: Date string in either "DD-MM-YYYY" or "MM/DD/YYYY" format
    Returns:
        Date string in "YYYY-MM-DD" format
    Raises:
        ValueError: If date_str is invalid or in wrong format
    """
    # TODO: Implement this function
    dash_pattern = r'^(\d{2})-(\d{2})-(\d{4})$'
    slash_pattern = r'^(\d{2})/(\d{2})/(\d{4})$'
    if re.match(dash_pattern, date_str):
        day, month, year = re.match(dash_pattern, date_str).groups()
        return f'{year}-{month}-{day}'
    elif re.match(slash_pattern, date_str):
        month, day, year = re.match(slash_pattern, date_str).groups()
        return f'{year}-{month}-{day}'
    else:
        raise ValueError('Invalid date format. Use DD-MM-YYYY or MM/DD/YYYY')


def run_tests() -> None:
    """Run test cases for all problems"""
    start_time = time.time()
    print("\n=== Running Tests ===\n")
    # Problem 1 Tests
    print("Testing Problem 1: Word Frequency")
    test_cases = [
        ("Hello, hello world! How are you doing today?", 4),
        ("Python is awesome! Python is fun. PYTHON IS GREAT!", 3),
        ("A b c d e f g", 2),
    ]
    for text, min_len in test_cases:
        print(f"\nInput text: {text}")
        print(f"Min length: {min_len}")
        print(f"Result: {word_frequency(text, min_len)}")

    # Problem 2 Tests
    print("\nTesting Problem 2: Digital Root")
    numbers = [16, 942, 132189, 493193]
    for num in numbers:
        print(f"Input: {num}")
        print(f"Result: {digital_root(num)}")
    # Problem 3 Tests
    print("\nTesting Problem 3: Running Average")
    test_cases = [
        ([1, 2, 3, 4, 5], 3),
        ([10, 20, 30, 40], 2),
        ([1.5, 2.5, 3.5], 4),
    ]
    for nums, window in test_cases:
        print(f"\nNumbers: {nums}")
        print(f"Window size: {window}")
        print(f"Result: {running_average(nums, window)}")

    # Problem 4 Tests
    print("\nTesting Problem 4: Date Formatting")
    dates = [
        "23-04-2024",
        "04/23/2024",
        "31-12-2023",
        "12/31/2023"
    ]
    for date in dates:
        print(f"Input: {date}")
        print(f"Result: {format_date(date)}")

    end_time = time.time()
    print(f"\nAll tests completed in {end_time - start_time:.2f} seconds")


if __name__ == "__main__":
    print("\n60-Minute Python Coding Test")
    print("===========================")
    print("\nInstructions:")
    print("1. Implement all 4 problems")
    print("2. You have 60 minutes to complete the test")
    print("3. Focus on proper error handling and edge cases")
    print("4. Use only Python standard library")
    print("5. Run tests to verify your solutions")
    print("\nGood luck!\n")
    run_tests()
