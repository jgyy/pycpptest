#!/usr/bin/env python3

"""
60-Minute Python Coding Challenge
-------------------------------
Test your Python programming skills with these fundamental challenges.
Time Limit: 60 minutes
Instructions:
- Implement all functions according to their docstrings
- Use only Python standard library
- Focus on both correctness and code quality
- Run the tests to verify your solutions
"""

from typing import List, Set, Dict, Optional
import time
from dataclasses import dataclass
from datetime import datetime
from collections import defaultdict, deque

# Problem 1: Sequence Processing
def find_missing_numbers(nums: List[int]) -> List[int]:
    """
    Given a list of n integers where each number is between 1 and n+2,
    find the two missing numbers in the range.
    Example:
    Input: [1, 4, 3]
    Output: [2, 5] (numbers missing from range 1-5)
    Args:
        nums: List of integers where length n means range is 1 to n+2
    Returns:
        List containing the two missing numbers in ascending order
    """
    # TODO: Implement this function
    n = len(nums)
    full_set = set(range(1, n + 3))
    nums_set = set(nums)
    missing = list(full_set - nums_set)
    return sorted(missing)


# Problem 2: String Manipulation
def longest_palindromic_substring(s: str) -> str:
    """
    Find the longest substring that reads the same forwards and backwards.
    Example:
    Input: "babad"
    Output: "bab" or "aba" (both are valid)
    Args:
        s: Input string
    Returns:
        Longest palindromic substring
    """
    # TODO: Implement this function
    if not s:
        return ""

    def expand_around_center(left: int, right: int) -> tuple[int, int]:
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return left + 1, right - 1

    start = 0
    end = 0
    for i in range(len(s)):
        left1, right1 = expand_around_center(i, i)
        left2, right2 = expand_around_center(i, i + 1)
        if right1 - left1 > end - start:
            start, end = left1, right1
        if right2 - left2 > end - start:
            start, end = left2, right2
    return s[start:end + 1]


# Problem 3: Class Implementation
@dataclass
class Transaction:
    """Represents a financial transaction"""
    date: datetime
    amount: float
    description: str
    category: str


class ExpenseTracker:
    """
    Implement an expense tracking system that can:
    - Add transactions
    - Get total expenses by category
    - Find highest spending day
    - List all transactions within a date range
    """

    def __init__(self):
        """Initialize the expense tracker"""
        # TODO: Initialize necessary data structures
        self.transactions: List[Transaction] = []
        self.category_totals: Dict[str, float] = defaultdict(float)
        self.daily_totals: Dict[datetime.date, float] = defaultdict(float)

    def add_transaction(self, transaction: Transaction) -> None:
        """
        Add a new transaction to the tracker
        Args:
            transaction: Transaction object to add
        """
        # TODO: Implement this method
        self.transactions.append(transaction)
        self.category_totals[transaction.category] += transaction.amount
        self.daily_totals[transaction.date.date()] += transaction.amount

    def get_category_total(self, category: str) -> float:
        """
        Get total expenses for a specific category
        Args:
            category: Category to total
        Returns:
            Total amount spent in the category
        """
        # TODO: Implement this method
        return self.category_totals[category]

    def get_highest_spending_day(self) -> tuple[datetime, float]:
        """
        Find the day with the highest total expenses
        Returns:
            Tuple of (date, total_amount) for highest spending day
        """
        # TODO: Implement this method
        if not self.daily_totals:
            return datetime.now(), 0.0
        max_date = max(self.daily_totals.items(), key=lambda x: x[1])
        return datetime.combine(max_date[0], datetime.min.time()), max_date[1]

    def get_transactions_in_range(self, start_date: datetime, 
                                end_date: datetime) -> List[Transaction]:
        """
        Get all transactions between start_date and end_date (inclusive)
        Args:
            start_date: Start of date range
            end_date: End of date range
        Returns:
            List of transactions within the date range
        """
        # TODO: Implement this method
        return [t for t in self.transactions
                if start_date.date() <= t.date.date() <= end_date.date()]


# Problem 4: Graph Algorithm
def shortest_path_length(grid: List[List[int]]) -> Optional[int]:
    """
    Find the length of shortest path from top-left to bottom-right corner of a grid.
    You can only move right or down, and only through cells with value 0.
    Cells with value 1 are obstacles.
    Example:
    Input: [
        [0, 0, 0, 1],
        [1, 1, 0, 0],
        [0, 0, 0, 1],
        [0, 1, 0, 0]
    ]
    Output: 8 (path length including start and end cells)
    Return None if no path exists.

    Args:
        grid: 2D list representing the maze (0=path, 1=obstacle)
    Returns:
        Length of shortest path or None if no path exists
    """
    # TODO: Implement this function
    if not grid or not grid[0] or grid[0][0] == 1:
        return None
    rows, cols = len(grid), len(grid[0])
    target = (rows - 1, cols - 1)
    if grid[target[0]][target[1]] == 1:
        return None
    queue = deque([(0, 0, 1)])
    visited = {(0, 0)}
    directions = [(0, 1), (1, 0)]
    while queue:
        row, col, length = queue.popleft()
        if (row, col) == target:
            return length
        for dx, dy in directions:
            new_row, new_col = row + dx, col + dy
            if (0 <= new_row < rows and
                0 <= new_col < cols and
                grid[new_row][new_col] == 0 and
                (new_row, new_col) not in visited):
                visited.add((new_row, new_col))
                queue.append((new_row, new_col, length + 1))
    return None


def run_tests() -> None:
    """Run test cases for all problems"""
    print("\n=== Running Tests ===\n")
    start_time = time.time()
    # Problem 1 Tests
    print("Testing Problem 1: Find Missing Numbers")
    test_cases = [
        ([1, 4, 3], [2, 5]),
        ([1, 2], [3, 4]),
        ([3, 1, 4], [2, 5])
    ]
    for nums, expected in test_cases:
        result = find_missing_numbers(nums)
        print(f"Input: {nums}")
        print(f"Expected: {expected}")
        print(f"Output: {result}")
        print(f"{'✓ Passed' if result == expected else '✗ Failed'}\n")

    # Problem 2 Tests
    print("\nTesting Problem 2: Longest Palindromic Substring")
    test_cases = [
        "babad",
        "cbbd",
        "racecar",
        "python"
    ]
    for s in test_cases:
        result = longest_palindromic_substring(s)
        print(f"Input: {s}")
        print(f"Output: {result}")
        print(f"Is palindrome: {result == result[::-1]}\n")

    # Problem 3 Tests
    print("\nTesting Problem 3: Expense Tracker")
    tracker = ExpenseTracker()
    transactions = [
        Transaction(datetime(2024, 1, 1), 100.0, "Groceries", "Food"),
        Transaction(datetime(2024, 1, 1), 50.0, "Gas", "Transport"),
        Transaction(datetime(2024, 1, 2), 75.0, "Restaurant", "Food"),
        Transaction(datetime(2024, 1, 3), 200.0, "Electronics", "Shopping")
    ]
    for t in transactions:
        tracker.add_transaction(t)

    print("Category totals:")
    categories = ["Food", "Transport", "Shopping"]
    for cat in categories:
        total = tracker.get_category_total(cat)
        print(f"{cat}: ${total:.2f}")
    date, amount = tracker.get_highest_spending_day()
    print(f"\nHighest spending day: {date.date()} (${amount:.2f})")
    date_range = tracker.get_transactions_in_range(
        datetime(2024, 1, 1),
        datetime(2024, 1, 2)
    )
    print(f"\nTransactions in range: {len(date_range)}")

    # Problem 4 Tests
    print("\nTesting Problem 4: Shortest Path Length")
    test_grid = [
        [0, 0, 0, 1],
        [1, 1, 0, 0],
        [0, 0, 0, 1],
        [0, 1, 0, 0]
    ]
    result = shortest_path_length(test_grid)
    print("Test grid:")
    for row in test_grid:
        print(row)
    print(f"Shortest path length: {result}")
    end_time = time.time()
    print(f"\nAll tests completed in {end_time - start_time:.2f} seconds")


if __name__ == "__main__":
    print("\n60-Minute Python Coding Challenge")
    print("================================")
    print("\nInstructions:")
    print("1. Implement solutions for all 4 problems")
    print("2. Use only Python standard library")
    print("3. Focus on both correctness and efficiency")
    print("4. Run tests to verify your solutions")
    print("5. Time limit: 60 minutes\n")
    run_tests()
