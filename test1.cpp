/**
 * C++ Coding Interview Questions (1 Hour)
 * -------------------------------------
 * A set of coding challenges covering fundamental C++ concepts.
 * Author: [Your Name]
 * Date: [Current Date]
 */

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <chrono>
#include <stack>
#include <unordered_map>
#include <limits>
#include <iomanip>

using namespace std;
using namespace std::chrono;

// Problem 1: String Processing
/**
 * Find the first non-repeating character in a string and return its index.
 * @param s Input string
 * @return Index of first unique character, or -1 if none exists
 */
int firstUniqueChar(const string& s) {
    // Implement your solution here
    return -1;
}

// Problem 2: Array Processing
/**
 * Find the maximum sum of any contiguous subarray within the vector.
 * @param nums Vector of integers
 * @return Maximum sum of any contiguous subarray
 */
int maxSubarraySum(const vector<int>& nums) {
    // Implement your solution here
    return 0;
}

// Problem 3: Data Structure Implementation
/**
 * Queue implementation using two stacks.
 * Operations: push(x), pop(), peek(), empty()
 */
class Queue {
private:
    // Add your member variables here

public:
    Queue() {
        // Initialize your data structure here
    }
    
    void push(int x) {
        // Push element x to the back of queue
    }
    
    int pop() {
        // Remove and return the element from front of queue
        return 0;
    }
    
    int peek() {
        // Get the front element
        return 0;
    }
    
    bool empty() {
        // Return whether the queue is empty
        return true;
    }
};

// Problem 4: Binary Search Tree Validation
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * Determine if a binary tree is a valid binary search tree (BST).
 * @param root Root node of the binary tree
 * @return true if the tree is a valid BST, false otherwise
 */
bool isValidBST(TreeNode* root) {
    // Implement your solution here
    return false;
}

// Helper function to clean up binary tree memory
void cleanupTree(TreeNode* root) {
    if (root) {
        cleanupTree(root->left);
        cleanupTree(root->right);
        delete root;
    }
}

// Test functions
void testProblem1() {
    cout << "\nTesting Problem 1: First Unique Character" << endl;
    cout << string(40, '-') << endl;
    
    try {
        assert(firstUniqueChar("leetcode") == 0);
        assert(firstUniqueChar("loveleetcode") == 2);
        assert(firstUniqueChar("aabb") == -1);
        cout << "✓ All tests passed!" << endl;
    } catch (const exception& e) {
        cout << "✗ Test failed: " << e.what() << endl;
    }
}

void testProblem2() {
    cout << "\nTesting Problem 2: Maximum Subarray Sum" << endl;
    cout << string(40, '-') << endl;
    
    try {
        assert(maxSubarraySum({-2, 1, -3, 4, -1, 2, 1, -5, 4}) == 6);
        assert(maxSubarraySum({1}) == 1);
        assert(maxSubarraySum({-1, -2, -3}) == -1);
        cout << "✓ All tests passed!" << endl;
    } catch (const exception& e) {
        cout << "✗ Test failed: " << e.what() << endl;
    }
}

void testProblem3() {
    cout << "\nTesting Problem 3: Queue Implementation" << endl;
    cout << string(40, '-') << endl;
    
    try {
        Queue queue;
        queue.push(1);
        queue.push(2);
        assert(queue.peek() == 1);
        assert(queue.pop() == 1);
        assert(queue.empty() == false);
        cout << "✓ All tests passed!" << endl;
    } catch (const exception& e) {
        cout << "✗ Test failed: " << e.what() << endl;
    }
}

void testProblem4() {
    cout << "\nTesting Problem 4: Valid BST" << endl;
    cout << string(40, '-') << endl;
    
    try {
        // Test Case 1: Valid BST
        //     2
        //    / \
        //   1   3
        TreeNode* node1 = new TreeNode(2);
        node1->left = new TreeNode(1);
        node1->right = new TreeNode(3);
        assert(isValidBST(node1) == true);
        cleanupTree(node1);

        // Test Case 2: Invalid BST
        //     5
        //    / \
        //   1   4
        //      / \
        //     3   6
        TreeNode* node2 = new TreeNode(5);
        node2->left = new TreeNode(1);
        node2->right = new TreeNode(4);
        node2->right->left = new TreeNode(3);
        node2->right->right = new TreeNode(6);
        assert(isValidBST(node2) == false);
        cleanupTree(node2);
        cout << "✓ All tests passed!" << endl;
    } catch (const exception& e) {
        cout << "✗ Test failed: " << e.what() << endl;
    }
}

void printProblemDescription(int problemNum, const string& description) {
    cout << "\nProblem " << problemNum << endl;
    cout << string(40, '=') << endl;
    cout << description << endl;
    cout << string(40, '-') << endl;
}

void runAllTests() {
    cout << "\n=== Running Tests ===" << endl;
    auto start = high_resolution_clock::now();
    testProblem1();
    testProblem2();
    testProblem3();
    testProblem4();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "\nAll tests completed in " << fixed << setprecision(2) 
         << duration.count() / 1000.0 << " seconds" << endl;
}

int main() {
    cout << "\nC++ Coding Interview Questions" << endl;
    cout << string(30, '=') << endl;
    cout << "Time allowed: 1 hour\n" << endl;
    cout << "Instructions:" << endl;
    cout << "- Implement the solution for each problem" << endl;
    cout << "- Use only standard C++ libraries" << endl;
    cout << "- Focus on both correctness and code quality" << endl;
    cout << "- Compile and run this file to test your solutions" << endl;
    vector<pair<int, string>> problems = {
        {1, "Find the first non-repeating character in a string and return its index."},
        {2, "Find the maximum sum of any contiguous subarray within the vector."},
        {3, "Implement a Queue using two stacks with push, pop, peek, and empty operations."},
        {4, "Determine if a binary tree is a valid binary search tree (BST)."}
    };
    for (const auto& [num, desc] : problems) {
        printProblemDescription(num, desc);
    }
    runAllTests();
    return 0;
}
