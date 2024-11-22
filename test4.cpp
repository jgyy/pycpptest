/**
 * C++ Coding Test (60 Minutes)
 * ---------------------------
 * Instructions:
 * 1. Implement solutions for all problems
 * 2. Each implementation should handle edge cases
 * 3. Focus on code readability and efficiency
 * 4. All required headers are included
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cassert>

using namespace std;

// Problem 1: Palindrome Pairs
/**
 * Given a vector of unique strings, find all pairs of distinct indices (i, j) 
 * where the concatenation of strings[i] + strings[j] forms a palindrome.
 * 
 * Example:
 * Input: ["bat", "tab", "cat"]
 * Output: [[0,1], [1,0]] // "battab" and "tabbat" are palindromes
 * 
 * @param strings Vector of strings to check
 * @return Vector of index pairs that form palindromes when concatenated
 */
vector<vector<int>> findPalindromePairs(const vector<string>& strings) {
    // TODO: Implement your solution here
}

// Problem 2: Min Stack with GetMin and GetMax
/**
 * Implement a stack that supports push, pop, top, getMin, and getMax operations,
 * all in O(1) time complexity.
 * 
 * Example:
 * MinMaxStack stack;
 * stack.push(3);  // stack: [3]
 * stack.push(1);  // stack: [3,1]
 * stack.getMin(); // returns 1
 * stack.getMax(); // returns 3
 * stack.pop();    // stack: [3]
 */
class MinMaxStack {
private:
    // TODO: Add your member variables here

public:
    MinMaxStack() {
        // TODO: Initialize your data structure
    }
    
    void push(int val) {
        // TODO: Implement push operation
    }
    
    void pop() {
        // TODO: Implement pop operation
    }
    
    int top() {
        // TODO: Implement top operation
    }
    
    int getMin() {
        // TODO: Implement getMin operation
    }
    
    int getMax() {
        // TODO: Implement getMax operation
    }
};

// Problem 3: Interval Merge
/**
 * Given a collection of intervals, merge all overlapping intervals.
 * Each interval is represented as a pair of integers [start, end].
 * 
 * Example:
 * Input: [[1,3], [2,6], [8,10], [15,18]]
 * Output: [[1,6], [8,10], [15,18]]
 * 
 * @param intervals Vector of interval pairs to merge
 * @return Vector of merged intervals
 */
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    // TODO: Implement your solution here
}

// Problem 4: Word Pattern
/**
 * Given a pattern and a string, determine if the string follows the same pattern.
 * Each letter in the pattern maps to a word in the string.
 * 
 * Example:
 * pattern = "abba", str = "dog cat cat dog" -> true
 * pattern = "abba", str = "dog cat cat fish" -> false
 * pattern = "abc", str = "dog cat dog" -> false
 * 
 * @param pattern Pattern string containing only lowercase letters
 * @param str Space-separated string of words
 * @return true if str follows pattern, false otherwise
 */
bool followsPattern(string pattern, string str) {
    // TODO: Implement your solution here
}

// Test functions
void testProblem1() {
    cout << "\nTesting Problem 1: Palindrome Pairs" << endl;
    cout << string(40, '-') << endl;
    
    // Test case 1: Basic palindrome pairs
    vector<string> input1 = {"bat", "tab", "cat"};
    vector<vector<int>> expected1 = {{0,1}, {1,0}};
    
    // Test case 2: Empty string cases
    vector<string> input2 = {"", "ab", "ba", ""};
    vector<vector<int>> expected2 = {{0,1}, {1,0}, {2,3}, {3,2}};
    
    // Test case 3: Single character cases
    vector<string> input3 = {"a", ""};
    vector<vector<int>> expected3 = {{0,1}, {1,0}};
}

void testProblem2() {
    cout << "\nTesting Problem 2: MinMaxStack" << endl;
    cout << string(40, '-') << endl;
    
    MinMaxStack stack;
    // Test pushing elements
    stack.push(3);
    stack.push(1);
    stack.push(5);
    
    // Test min/max operations
    assert(stack.getMin() == 1);
    assert(stack.getMax() == 5);
    
    // Test pop operations
    stack.pop();
    assert(stack.getMax() == 3);
    assert(stack.getMin() == 1);
}

void testProblem3() {
    cout << "\nTesting Problem 3: Interval Merge" << endl;
    cout << string(40, '-') << endl;
    
    // Test case 1: Basic overlapping intervals
    vector<vector<int>> input1 = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>> expected1 = {{1,6}, {8,10}, {15,18}};
    
    // Test case 2: No overlapping intervals
    vector<vector<int>> input2 = {{1,2}, {3,4}, {5,6}};
    vector<vector<int>> expected2 = {{1,2}, {3,4}, {5,6}};
    
    // Test case 3: Complete overlap
    vector<vector<int>> input3 = {{1,4}, {2,3}};
    vector<vector<int>> expected3 = {{1,4}};
}

void testProblem4() {
    cout << "\nTesting Problem 4: Word Pattern" << endl;
    cout << string(40, '-') << endl;
    
    // Test case 1: Valid patterns
    assert(followsPattern("abba", "dog cat cat dog") == true);
    
    // Test case 2: Invalid patterns
    assert(followsPattern("abba", "dog cat cat fish") == false);
    
    // Test case 3: Length mismatch
    assert(followsPattern("abc", "dog cat dog") == false);
    
    // Test case 4: Bijection violation
    assert(followsPattern("abba", "dog dog dog dog") == false);
}

int main() {
    cout << "Running test cases..." << endl;
    
    testProblem1();
    testProblem2();
    testProblem3();
    testProblem4();
    
    cout << "\nAll test cases completed!" << endl;
    return 0;
}
