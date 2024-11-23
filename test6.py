#!/usr/bin/env python3

"""
60-Minute Python Coding Test (Easy Level)
---------------------------------------
Test your Python programming fundamentals with these beginner-friendly challenges.
Time Limit: 60 minutes

Instructions:
- Implement all functions according to their docstrings
- Use only Python standard library (no external packages)
- Each problem is worth 25 points
- Run tests to verify your solutions
"""

from typing import List, Dict, Set, Tuple
from collections import deque
import time

# Problem 1: Sequence Pattern
def generate_sequence(start: int, length: int) -> List[int]:
    """
    Generate a sequence where each number is the sum of the previous two digits of 
    the previous number. Start with a given number.
    
    Example:
    start=5, length=4 should return [5, 5, 10, 1]
    Explanation:
    - First number is 5
    - 5 has one digit, so next is 5
    - 5 has one digit, so next is 5+5=10
    - 10 has two digits (1,0), so next is 1+0=1
    
    Args:
        start: Starting number (positive integer)
        length: Length of sequence to generate
    
    Returns:
        List containing the generated sequence
    
    Raises:
        ValueError: If start is negative or length is less than 1
    """
    # TODO: Implement this function
    pass


# Problem 2: Card Game Simulator
def calculate_score(cards: List[str]) -> int:
    """
    Calculate score for a hand of cards where:
    - Number cards (2-10) are worth their face value
    - Face cards (J, Q, K) are worth 10 points
    - Aces (A) are worth 11 points unless total would exceed 21, then worth 1
    - Pairs of same value (e.g. two 5s) get 2x points
    - Three of a kind gets 3x points
    
    Example:
    ["A", "A", "K"] -> (11 + 11 + 10) * 2 = 64 (pair of Aces doubles score)
    ["5", "5", "5"] -> (5 + 5 + 5) * 3 = 45 (three of a kind triples score)
    ["2", "K", "A"] -> 2 + 10 + 11 = 23 (no multiplier)
    
    Args:
        cards: List of card values (2-10, J, Q, K, A)
        
    Returns:
        Total score for the hand
        
    Raises:
        ValueError: If invalid card value provided
    """
    # TODO: Implement this function
    pass


# Problem 3: Text Processing
def format_paragraphs(text: str, width: int) -> List[str]:
    """
    Format text into paragraphs with specified maximum width.
    - Break text at word boundaries (don't split words)
    - Remove extra whitespace between words
    - Preserve paragraph breaks (empty lines)
    - Right-justify the last word if line has one word
    - Left-justify all other lines
    
    Example:
    text = "The quick brown fox jumps over the lazy dog.
    
    The five boxing wizards jump quickly."
    width = 20
    
    Returns:
    [
        "The quick brown fox",
        "jumps over the lazy",
        "dog.",
        "",
        "The five boxing",
        "wizards jump",
        "quickly."
    ]
    
    Args:
        text: Input text containing paragraphs
        width: Maximum width for each line
        
    Returns:
        List of formatted lines
        
    Raises:
        ValueError: If width is less than 1
    """
    # TODO: Implement this function
    pass


# Problem 4: Game Inventory
class Inventory:
    """
    Implement a simple game inventory system with the following features:
    - Add/remove items with quantities
    - Check if an item exists
    - Get quantity of an item
    - List all items
    - Combine two inventories
    - Items have a maximum stack size (default 64)
    
    Example:
    inv = Inventory()
    inv.add_item("sword", 1)
    inv.add_item("apple", 5)
    inv.remove_item("apple", 2)  # 3 apples remain
    print(inv.get_quantity("apple"))  # prints: 3
    
    other_inv = Inventory()
    other_inv.add_item("apple", 2)
    inv.combine(other_inv)  # Now has 5 apples
    
    Methods to implement:
    - add_item(item: str, quantity: int) -> bool
    - remove_item(item: str, quantity: int) -> bool
    - has_item(item: str) -> bool
    - get_quantity(item: str) -> int
    - get_items() -> Dict[str, int]
    - combine(other: 'Inventory') -> None
    """
    
    def __init__(self, max_stack: int = 64):
        """Initialize empty inventory with max stack size"""
        # TODO: Implement initialization
        pass
    
    def add_item(self, item: str, quantity: int) -> bool:
        """Add quantity of item to inventory, respecting max stack size"""
        # TODO: Implement this method
        pass
    
    def remove_item(self, item: str, quantity: int) -> bool:
        """Remove quantity of item from inventory if possible"""
        # TODO: Implement this method
        pass
    
    def has_item(self, item: str) -> bool:
        """Check if item exists in inventory"""
        # TODO: Implement this method
        pass
    
    def get_quantity(self, item: str) -> int:
        """Get quantity of item in inventory (0 if doesn't exist)"""
        # TODO: Implement this method
        pass
    
    def get_items(self) -> Dict[str, int]:
        """Get dictionary of all items and their quantities"""
        # TODO: Implement this method
        pass
    
    def combine(self, other: 'Inventory') -> None:
        """Combine other inventory into this one"""
        # TODO: Implement this method
        pass


def run_tests() -> None:
    """Run test cases for all problems"""
    start_time = time.time()
    
    print("\n=== Testing Problem 1: Sequence Pattern ===")
    sequence_tests = [
        # Format: (start, length, expected_result)
        (5, 4, [5, 5, 10, 1]),
        (12, 4, [12, 3, 3, 3]),
        (999, 5, [999, 27, 9, 9, 18]),
        (1, 3, [1, 1, 2]),
        (0, 4, [0, 0, 0, 0])
    ]
    
    for start, length, expected in sequence_tests:
        try:
            result = generate_sequence(start, length)
            print(f"\nInput: start={start}, length={length}")
            print(f"Expected: {expected}")
            print(f"Got: {result}")
            print(f"{'✓ Passed' if result == expected else '✗ Failed'}")
        except ValueError as e:
            print(f"Raised ValueError: {e}")
    
    # Test invalid inputs
    try:
        generate_sequence(-1, 5)
        print("✗ Failed: Should raise ValueError for negative start")
    except ValueError:
        print("✓ Passed: Correctly handled negative start")
    
    try:
        generate_sequence(5, 0)
        print("✗ Failed: Should raise ValueError for zero length")
    except ValueError:
        print("✓ Passed: Correctly handled zero length")
    
    print("\n=== Testing Problem 2: Card Game Score ===")
    card_tests = [
        # Format: (cards, expected_score)
        (["A", "A", "K"], 64),  # Pair of Aces (22 + 10) * 2
        (["5", "5", "5"], 45),  # Three of a kind (5 + 5 + 5) * 3
        (["2", "K", "A"], 23),  # No multiplier
        (["A", "A", "A"], 33),  # Three Aces (1 + 1 + 1) * 3 to avoid bust
        (["Q", "Q", "K"], 60),  # Pair of Queens (10 + 10 + 10) * 2
        (["10", "J", "A"], 31), # No multiplier
        (["2", "2", "2"], 12),  # Three of a kind (2 + 2 + 2) * 3
        (["K", "A", "8"], 29)   # No multiplier
    ]
    
    for cards, expected in card_tests:
        try:
            result = calculate_score(cards)
            print(f"\nInput: {cards}")
            print(f"Expected: {expected}")
            print(f"Got: {result}")
            print(f"{'✓ Passed' if result == expected else '✗ Failed'}")
        except ValueError as e:
            print(f"Raised ValueError: {e}")
    
    # Test invalid inputs
    try:
        calculate_score(["A", "B", "C"])
        print("✗ Failed: Should raise ValueError for invalid card")
    except ValueError:
        print("✓ Passed: Correctly handled invalid card")
    
    print("\n=== Testing Problem 3: Text Formatting ===")
    text_tests = [
        # Single paragraph
        (
            "The quick brown fox jumps over the lazy dog.",
            20,
            [
                "The quick brown fox",
                "jumps over the lazy",
                "dog."
            ]
        ),
        # Multiple paragraphs
        (
            "The quick brown fox.\n\nJumps over dog.",
            15,
            [
                "The quick brown",
                "fox.",
                "",
                "Jumps over dog."
            ]
        ),
        # Single long word
        (
            "Supercalifragilisticexpialidocious",
            10,
            [
                "Supercalif",
                "ragilistic",
                "expialidoc",
                "ious"
            ]
        ),
        # Empty input
        (
            "",
            10,
            []
        ),
        # Multiple spaces and newlines
        (
            "One   two     three.\n\n\nFour    five.",
            10,
            [
                "One two",
                "three.",
                "",
                "Four five."
            ]
        )
    ]
    
    for text, width, expected in text_tests:
        try:
            result = format_paragraphs(text, width)
            print(f"\nInput text: {repr(text)}")
            print(f"Width: {width}")
            print(f"Expected: {expected}")
            print(f"Got: {result}")
            print(f"{'✓ Passed' if result == expected else '✗ Failed'}")
        except ValueError as e:
            print(f"Raised ValueError: {e}")
    
    # Test invalid input
    try:
        format_paragraphs("Hello", 0)
        print("✗ Failed: Should raise ValueError for zero width")
    except ValueError:
        print("✓ Passed: Correctly handled zero width")
    
    print("\n=== Testing Problem 4: Game Inventory ===")
    # Test basic functionality
    inv = Inventory()
    
    # Test adding items
    print("\nTesting add_item:")
    tests = [
        ("sword", 1, True),
        ("apple", 5, True),
        ("stone", 65, False),  # Exceeds max stack
        ("apple", 60, False)   # Would exceed max stack
    ]
    
    for item, qty, expected in tests:
        result = inv.add_item(item, qty)
        print(f"Adding {qty} {item}(s): {'✓ Passed' if result == expected else '✗ Failed'}")
    
    # Test quantities
    print("\nTesting get_quantity:")
    tests = [
        ("apple", 5),
        ("sword", 1),
        ("stone", 0),
        ("nonexistent", 0)
    ]
    
    for item, expected in tests:
        result = inv.get_quantity(item)
        print(f"Quantity of {item}: {'✓ Passed' if result == expected else '✗ Failed'}")
    
    # Test removing items
    print("\nTesting remove_item:")
    tests = [
        ("apple", 2, True),    # Should work
        ("apple", 4, False),   # Too many
        ("sword", 1, True),    # Remove last one
        ("sword", 1, False)    # Already removed
    ]
    
    for item, qty, expected in tests:
        result = inv.remove_item(item, qty)
        print(f"Removing {qty} {item}(s): {'✓ Passed' if result == expected else '✗ Failed'}")
    # Test combining inventories
    print("\nTesting combine:")
    inv1 = Inventory()
    inv2 = Inventory()
    inv1.add_item("apple", 30)
    inv1.add_item("sword", 1)
    inv2.add_item("apple", 20)
    inv2.add_item("potion", 5)
    inv1.combine(inv2)
    expected = {
        "apple": 50,
        "sword": 1,
        "potion": 5
    }
    result = inv1.get_items()
    print(f"Combined inventory: {'✓ Passed' if result == expected else '✗ Failed'}")
    print(f"Got: {result}")
    print(f"Expected: {expected}")
    end_time = time.time()
    print(f"\nAll tests completed in {end_time - start_time:.2f} seconds")


if __name__ == "__main__":
    print("\n60-Minute Python Coding Test (Easy Level)")
    print("======================================")
    print("\nInstructions:")
    print("1. Implement all 4 problems")
    print("2. You have 60 minutes to complete the test")
    print("3. Focus on handling edge cases and invalid inputs")
    print("4. Use only Python standard library")
    print("5. Run tests to verify your solutions")
    print("\nGood luck!\n")
    run_tests()
