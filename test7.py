#!/usr/bin/env python3

"""
60-Minute Python Coding Test (Beginner Level)
-------------------------------------------
Test your Python programming fundamentals with these beginner-friendly challenges.
Author: [Your Name]
Date: [Current Date]

Instructions:
- Implement all functions according to their docstrings
- Use only Python standard library (no external packages)
- Each problem is worth 25 points
- Focus on code clarity and proper error handling
- Run tests to verify your solutions
"""

from typing import List, Dict, Optional, Set
from collections import defaultdict
import time

# Problem 1: Shopping Cart Calculator
def calculate_total(items: List[str], prices: Dict[str, float], discount_code: Optional[str] = None) -> float:
    """
    Calculate the total price of items in a shopping cart with optional discount.
    Discount codes:
    - 'SAVE10' gives 10% off
    - 'BUY2GET1' makes every third item free (applies to lowest priced eligible item)
    - 'BULK25' gives 25% off when cart has more than 5 items
    
    Args:
        items: List of item names
        prices: Dictionary mapping item names to their prices
        discount_code: Optional discount code to apply
    
    Returns:
        Total price after any applicable discount
    
    Raises:
        ValueError: If an item is not found in prices dictionary
    """
    pass  # TODO: Implement this function


# Problem 2: Password Validator
def validate_password(password: str) -> Dict[str, bool]:
    """
    Validate a password against security criteria and return detailed results.
    
    Criteria:
    1. Length between 8-20 characters
    2. Contains at least one uppercase letter
    3. Contains at least one lowercase letter
    4. Contains at least one digit
    5. Contains at least one special character (!@#$%^&*)
    6. No more than 2 repeated characters in a row
    7. No whitespace allowed
    
    Args:
        password: String to validate
    
    Returns:
        Dictionary with each criterion as key and bool as value
        Example: {
            'valid_length': True,
            'has_uppercase': True,
            'has_lowercase': False,
            ...
        }
    """
    pass  # TODO: Implement this function


# Problem 3: Calendar Event Manager
class Event:
    """
    Represents a calendar event with a name, start time (hours 0-23), duration (minutes),
    and list of attendees.
    """
    def __init__(self, name: str, start_hour: int, duration_mins: int, attendees: List[str]):
        """Initialize the event"""
        pass  # TODO: Implement initialization

    def overlaps_with(self, other: 'Event') -> bool:
        """Check if this event overlaps in time with another event"""
        pass  # TODO: Implement this method

    def add_attendee(self, attendee: str) -> bool:
        """Add an attendee if not already in the event. Return True if added successfully."""
        pass  # TODO: Implement this method

    def remove_attendee(self, attendee: str) -> bool:
        """Remove an attendee if present. Return True if removed successfully."""
        pass  # TODO: Implement this method

    def get_end_time(self) -> int:
        """Get the ending hour of the event (rounded up to nearest hour)"""
        pass  # TODO: Implement this method

    def get_attendee_count(self) -> int:
        """Get the number of attendees"""
        pass  # TODO: Implement this method


# Problem 4: Word Chain Validator
def is_valid_word_chain(words: List[str]) -> Dict[str, bool]:
    """
    Validate if a list of words forms a valid word chain where each word starts with
    the last letter of the previous word. Also check additional criteria.
    
    Example: ["apple", "elephant", "tiger", "rat"] is valid because:
    - e(apple) -> e(elephant)
    - t(elephant) -> t(tiger)
    - r(tiger) -> r(rat)
    Criteria to check:
    1. Each word starts with last letter of previous word
    2. All words are at least 2 letters long
    3. No word is used more than once
    4. At least 2 words in the chain
    Args:
        words: List of words to validate
    Returns:
        Dictionary with results for each criterion:
        {
            'valid_chain': bool,  # True if all criteria met
            'valid_connections': bool,  # Words connect properly
            'valid_lengths': bool,  # All words >= 2 letters
            'no_duplicates': bool,  # No repeated words
            'valid_count': bool  # At least 2 words
        }
    """
    # TODO: Implement this function
    pass


def run_tests() -> None:
    """Run test cases for all problems"""
    start_time = time.time()
    print("\n=== Running Tests ===\n")

    # Problem 1: Shopping Cart Tests
    print("Testing Shopping Cart Calculator...")
    prices = {
        "apple": 0.50,
        "banana": 0.30,
        "orange": 0.60,
        "mango": 1.50,
        "pineapple": 2.50,
        "grape": 0.90
    }

    cart_tests = [
        # Format: (items, discount_code, expected_total)
        (
            ["apple", "apple", "orange"],
            "SAVE10",
            1.44,  # (0.50 + 0.50 + 0.60) * 0.9
            "Basic cart with SAVE10 discount"
        ),
        (
            ["mango", "apple", "orange", "apple", "banana", "grape"],
            "BULK25",
            3.975,  # (1.50 + 0.50 + 0.60 + 0.50 + 0.30 + 0.90) * 0.75
            "Bulk discount with more than 5 items"
        ),
        (
            ["pineapple", "mango", "grape"],
            "BUY2GET1",
            4.00,  # 2.50 + 1.50 + 0 (grape is free as lowest price)
            "Buy 2 Get 1 Free discount"
        ),
        (
            ["apple", "banana"],
            None,
            0.80,  # No discount applied
            "Cart without discount"
        ),
        (
            ["apple", "invalid_item"],
            None,
            None,  # Should raise ValueError
            "Cart with invalid item"
        )
    ]

    for items, code, expected, description in cart_tests:
        print(f"\nTest: {description}")
        print(f"Items: {items}")
        print(f"Discount: {code}")
        try:
            result = calculate_total(items, prices, code)
            if expected is None:
                print("✗ Failed: Should have raised ValueError")
            else:
                print(f"Expected: {expected:.2f}")
                print(f"Got: {result:.2f}")
                print(f"{'✓ Passed' if abs(result - expected) < 0.01 else '✗ Failed'}")
        except ValueError as e:
            if expected is None:
                print("✓ Passed: Correctly raised ValueError")
            else:
                print(f"✗ Failed: Unexpected ValueError: {e}")

    # Problem 2: Password Validator Tests
    print("\nTesting Password Validator...")
    password_tests = [
        (
            "Abc123!@#",
            {
                'valid_length': True,
                'has_uppercase': True,
                'has_lowercase': True,
                'has_digit': True,
                'has_special': True,
                'no_repeats': True,
                'no_whitespace': True
            },
            "Valid password with all criteria met"
        ),
        (
            "abc",
            {
                'valid_length': False,
                'has_uppercase': False,
                'has_lowercase': True,
                'has_digit': False,
                'has_special': False,
                'no_repeats': True,
                'no_whitespace': True
            },
            "Too short password"
        ),
        (
            "AAAbbb123",
            {
                'valid_length': True,
                'has_uppercase': True,
                'has_lowercase': True,
                'has_digit': True,
                'has_special': False,
                'no_repeats': False,
                'no_whitespace': True
            },
            "Password with repeated characters"
        ),
        (
            "Pass word123!",
            {
                'valid_length': True,
                'has_uppercase': True,
                'has_lowercase': True,
                'has_digit': True,
                'has_special': True,
                'no_repeats': True,
                'no_whitespace': False
            },
            "Password with whitespace"
        ),
        (
            "abcdefghijklmnopqrstuvwxyz",
            {
                'valid_length': False,
                'has_uppercase': False,
                'has_lowercase': True,
                'has_digit': False,
                'has_special': False,
                'no_repeats': True,
                'no_whitespace': True
            },
            "Password too long"
        )
    ]

    for password, expected, description in password_tests:
        print(f"\nTest: {description}")
        print(f"Password: {password}")
        result = validate_password(password)
        print(f"Expected: {expected}")
        print(f"Got: {result}")
        print(f"{'✓ Passed' if result == expected else '✗ Failed'}")

    # Problem 3: Calendar Event Tests
    print("\nTesting Calendar Event Manager...")

    # Test Event Creation and Basic Methods
    try:
        event1 = Event("Team Meeting", 9, 60, ["Alice", "Bob"])
        event2 = Event("Lunch", 12, 30, ["Alice", "Charlie"])
        event3 = Event("Workshop", 11, 120, ["Bob", "Charlie"])

        # Test get_end_time
        assert event1.get_end_time() == 10, "Event 1 should end at 10"
        assert event2.get_end_time() == 13, "Event 2 should end at 13"
        assert event3.get_end_time() == 13, "Event 3 should end at 13"
        print("✓ Passed: End time calculations")

        # Test attendee methods
        assert event1.get_attendee_count() == 2, "Event 1 should have 2 attendees"
        assert event1.add_attendee("Dave"), "Should add new attendee"
        assert not event1.add_attendee("Alice"), "Should not add duplicate attendee"
        assert event1.remove_attendee("Bob"), "Should remove existing attendee"
        assert not event1.remove_attendee("Eve"), "Should not remove non-existent attendee"
        print("✓ Passed: Attendee management")

        # Test overlap detection
        assert event2.overlaps_with(event3), "Events 2 and 3 should overlap"
        assert not event1.overlaps_with(event2), "Events 1 and 2 should not overlap"
        print("✓ Passed: Overlap detection")

    except AssertionError as e:
        print(f"✗ Failed: {str(e)}")

    # Test Invalid Event Creation
    invalid_event_tests = [
        (
            "Invalid Hour",
            {"name": "Test", "start_hour": 24, "duration_mins": 60, "attendees": ["Alice"]},
            "Should reject invalid hour"
        ),
        (
            "Invalid Duration",
            {"name": "Test", "start_hour": 9, "duration_mins": -30, "attendees": ["Alice"]},
            "Should reject negative duration"
        ),
        (
            "Empty Name",
            {"name": "", "start_hour": 9, "duration_mins": 60, "attendees": ["Alice"]},
            "Should reject empty name"
        )
    ]

    for test_name, params, description in invalid_event_tests:
        print(f"\nTesting {test_name}")
        try:
            Event(**params)
            print(f"✗ Failed: {description}")
        except ValueError:
            print(f"✓ Passed: {description}")

    # Problem 4: Word Chain Tests
    print("\nTesting Word Chain Validator...")
    chain_tests = [
        (
            ["apple", "elephant", "tiger", "rat"],
            {
                'valid_chain': True,
                'valid_connections': True,
                'valid_lengths': True,
                'no_duplicates': True,
                'valid_count': True
            },
            "Valid word chain"
        ),
        (
            ["cat", "tree", "elephant", "elephant"],
            {
                'valid_chain': False,
                'valid_connections': True,
                'valid_lengths': True,
                'no_duplicates': False,
                'valid_count': True
            },
            "Chain with duplicate word"
        ),
        (
            ["dog", "cat"],
            {
                'valid_chain': False,
                'valid_connections': False,
                'valid_lengths': True,
                'no_duplicates': True,
                'valid_count': True
            },
            "Invalid connections"
        ),
        (
            ["a", "bat", "tiger"],
            {
                'valid_chain': False,
                'valid_connections': False,
                'valid_lengths': False,
                'no_duplicates': True,
                'valid_count': True
            },
            "Chain with short word"
        ),
        (
            ["snake"],
            {
                'valid_chain': False,
                'valid_connections': True,
                'valid_lengths': True,
                'no_duplicates': True,
                'valid_count': False
            },
            "Chain too short"
        ),
        (
            [],
            {
                'valid_chain': False,
                'valid_connections': True,
                'valid_lengths': True,
                'no_duplicates': True,
                'valid_count': False
            },
            "Empty chain"
        )
    ]

    for words, expected, description in chain_tests:
        print(f"\nTest: {description}")
        print(f"Words: {words}")
        result = is_valid_word_chain(words)
        print(f"Expected: {expected}")
        print(f"Got: {result}")
        print(f"{'✓ Passed' if result == expected else '✗ Failed'}")

    end_time = time.time()
    print(f"\nAll tests completed in {end_time - start_time:.2f} seconds")


if __name__ == "__main__":
    print("\n60-Minute Python Coding Test (Beginner Level)")
    print("==========================================")
    print("\nInstructions:")
    print("1. Implement all 4 problems")
    print("2. You have 60 minutes to complete the test")
    print("3. Focus on code clarity and error handling")
    print("4. Use only Python standard library")
    print("5. Run tests to verify your solutions")
    print("\nGood luck!\n")
    run_tests()
