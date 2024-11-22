/**
 * C++ Coding Interview Questions (60 Minutes)
 * ----------------------------------------
 * A set of fundamental coding challenges to test C++ proficiency.
 * Instructions:
 * - Implement solutions for all 4 problems
 * - Focus on code clarity and efficiency
 * - All required headers are already included
 * - Run the tests to verify your solutions
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

// Problem 1: Missing Numbers
/**
 * Given a sorted array of unique integers from 1 to n where some 
 * numbers are missing, find all missing numbers.
 * Example: 
 * Input: [1, 2, 4, 7, 8, 9]
 * Output: [3, 5, 6]
 * 
 * @param nums Sorted array of unique integers
 * @return Vector containing all missing numbers
 */
vector<int> findMissingNumbers(const vector<int> &nums)
{
    // Implement your solution here
    vector<int> missing;
    if (nums.empty()) return missing;
    int expected = 1;
    for (int num : nums)
    {
        while (expected < num)
        {
            missing.push_back(expected);
            ++expected;
        }
        expected = num + 1;
    }
    return missing;
}

// Problem 2: Anagram Groups
/**
 * Given an array of strings, group anagrams together.
 * Two strings are anagrams if they have the same characters in different orders.
 * Example:
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"]
 * Output: [["eat","tea","ate"], ["tan","nat"], ["bat"]]
 * 
 * @param words Array of strings
 * @return Vector of vectors containing grouped anagrams
 */
vector<vector<string>> groupAnagrams(const vector<string> &words)
{
    // Implement your solution here
    unordered_map<string, vector<string>> groups;
    for (const string &word : words)
    {
        string sorted = word;
        sort(sorted.begin(), sorted.end());
        groups[sorted].push_back(word);
    }
    vector<vector<string>> result;
    for (const auto &pair : groups)
        result.push_back(pair.second);
    return result;
}

// Problem 3: Circular Buffer
/**
 * Implement a circular buffer with the following operations:
 * - write(int): writes a value to the buffer, overwrites oldest value if full
 * - read(): reads and removes the oldest value from the buffer
 * - isFull(): returns true if buffer is full
 * - isEmpty(): returns true if buffer is empty
 */
class CircularBuffer
{
private:
    // Add your member variables here
    vector<int> buffer;
    size_t head;
    size_t tail;
    bool full;
    const size_t capacity;

public:
    CircularBuffer(int size) :
        buffer(size),
        head(0),
        tail(0),
        full(false),
        capacity(size) {}

    bool write(int value)
    {
        // Implement write operation
        if (isFull())
        {
            buffer[tail] = value;
            head = (head + 1) % capacity;
            tail = (tail + 1) % capacity;
            return true;
        }
        buffer[tail] = value;
        tail = (tail + 1) % capacity;
        full = (head == tail);
        return true;
    }

    int read()
    {
        // Implement read operation
        if (isEmpty())
            throw runtime_error("Buffer is empty");
        int value = buffer[head];
        head = (head + 1) % capacity;
        full = false;
        return value;
    }

    bool isFull() const
    {
        // Return whether buffer is full
        return full;
    }

    bool isEmpty() const
    {
        // Return whether buffer is empty
        return (!full && (head == tail));
    }
};

// Problem 4: Path Sum Counter
/**
 * Given a binary tree and a target sum, count the number of paths 
 * (going downwards only) where node values sum to the target.
 * A path can start and end at any node.
 * Example:
 *       10
 *      /  \
 *     5    -3
 *    / \     \
 *   3   2     11
 *  / \   \
 * 3  -2   1
 * 
 * Target = 8
 * Output: 3 (Paths: 5->3, 5->2->1, -3->11)
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int countPathsWithSumHelper(TreeNode *node, int targetSum, int currentSum)
{
    if (!node) return 0;

    currentSum += node->val;
    int paths = (currentSum == targetSum) ? 1 : 0;
    paths += countPathsWithSumHelper(node->left, targetSum, currentSum);
    paths += countPathsWithSumHelper(node->right, targetSum, currentSum);
    return paths;
}

int countPathsWithSum(TreeNode *root, int targetSum)
{
    // Implement your solution here
    if (!root) return 0;
    int pathsFromRoot = countPathsWithSumHelper(root, targetSum, 0);
    int pathsFromLeft = countPathsWithSum(root->left, targetSum);
    int pathsFromRight = countPathsWithSum(root->right, targetSum);
    return pathsFromRoot + pathsFromLeft + pathsFromRight;
}

// Helper function to clean up binary tree memory
void cleanupTree(TreeNode *root)
{
    if (root)
    {
        cleanupTree(root->left);
        cleanupTree(root->right);
        delete root;
    }
}

// Test functions
void testProblem1() {
    cout << "\nTesting Problem 1: Missing Numbers" << endl;
    cout << string(40, '-') << endl;

    vector<vector<int>> testCases = {
        {1, 2, 4, 7, 8, 9},
        {1, 3, 4, 5, 6, 8, 9, 10},
        {1, 2, 3, 4, 5}
    };

    vector<vector<int>> expected = {
        {3, 5, 6},
        {2, 7},
        {}
    };

    try {
        for (size_t i = 0; i < testCases.size(); i++) {
            auto result = findMissingNumbers(testCases[i]);
            assert(result == expected[i]);
        }
        cout << "✓ All tests passed!" << endl;
    } catch (const exception& e) {
        cout << "✗ Test failed: " << e.what() << endl;
    }
}

void testProblem2() {
    cout << "\nTesting Problem 2: Anagram Groups" << endl;
    cout << string(40, '-') << endl;

    try {
        vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
        auto result = groupAnagrams(input);
        
        // Sort each group and the final result for comparison
        for (auto& group : result) {
            sort(group.begin(), group.end());
        }
        sort(result.begin(), result.end());

        vector<vector<string>> expected = {
            {"ate", "eat", "tea"},
            {"bat"},
            {"nat", "tan"}
        };
        assert(result == expected);
        cout << "✓ All tests passed!" << endl;
    } catch (const exception& e) {
        cout << "✗ Test failed: " << e.what() << endl;
    }
}

void testProblem3() {
    cout << "\nTesting Problem 3: Circular Buffer" << endl;
    cout << string(40, '-') << endl;

    try {
        CircularBuffer buffer(3);
        assert(buffer.isEmpty() == true);
        assert(buffer.isFull() == false);
        
        buffer.write(1);
        buffer.write(2);
        buffer.write(3);
        assert(buffer.isFull() == true);
        
        assert(buffer.read() == 1);
        buffer.write(4);
        assert(buffer.read() == 2);
        
        cout << "✓ All tests passed!" << endl;
    } catch (const exception& e) {
        cout << "✗ Test failed: " << e.what() << endl;
    }
}

void testProblem4() {
    cout << "\nTesting Problem 4: Path Sum Counter" << endl;
    cout << string(40, '-') << endl;

    try {
        TreeNode* root = new TreeNode(10);
        root->left = new TreeNode(5);
        root->right = new TreeNode(-3);
        root->left->left = new TreeNode(3);
        root->left->right = new TreeNode(2);
        root->right->right = new TreeNode(11);
        root->left->left->left = new TreeNode(3);
        root->left->left->right = new TreeNode(-2);
        root->left->right->right = new TreeNode(1);

        assert(countPathsWithSum(root, 8) == 3);
        cleanupTree(root);
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
    cout << "Time allowed: 60 minutes\n" << endl;
    cout << "Instructions:" << endl;
    cout << "- Implement the solution for each problem" << endl;
    cout << "- Use only standard C++ libraries" << endl;
    cout << "- Focus on both correctness and code quality" << endl;
    cout << "- Run this file to test your solutions" << endl;

    vector<pair<int, string>> problems = {
        {1, "Find all missing numbers in a sorted array of integers."},
        {2, "Group anagrams from an array of strings."},
        {3, "Implement a circular buffer with basic operations."},
        {4, "Count paths in a binary tree that sum to a target value."}
    };

    for (const auto& [num, desc] : problems) {
        printProblemDescription(num, desc);
    }

    runAllTests();
    return 0;
}
