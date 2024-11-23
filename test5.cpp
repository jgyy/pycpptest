/**
 * C++ Coding Interview Questions (60 Minutes)
 * -----------------------------------------
 * Instructions:
 * 1. Implement solutions for all 4 problems
 * 2. Focus on code readability and efficiency
 * 3. Handle edge cases appropriately
 * 4. Run tests to verify your implementations
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <iomanip>
#include <sstream>

using namespace std;
using namespace std::chrono;

// Problem 1: Running Average
/**
 * Implement a class that calculates the running average of the last N numbers.
 * The class should support:
 * - Adding a new number
 * - Getting the current average of the last N numbers
 * - Getting the count of numbers currently stored
 * 
 * Example:
 * RunningAverage avg(3);  // Window size of 3
 * avg.add(5);   // Returns 5.0  (only 5)
 * avg.add(10);  // Returns 7.5  (5, 10)
 * avg.add(8);   // Returns 7.67 (5, 10, 8)
 * avg.add(15);  // Returns 11.0 (10, 8, 15)
 */
class RunningAverage
{
private:
    // Add your member variables here
    deque<int> numbers;
    int windowSize;
    double currentSum;

public:
    RunningAverage(int windowSize) : windowSize(windowSize), currentSum(0.0) {}

    double add(int num)
    {
        // Implement the add operation
        numbers.push_back(num);
        currentSum += num;
        if (numbers.size() > windowSize)
        {
            currentSum -= numbers.front();
            numbers.pop_front();
        }
        return currentSum / numbers.size();
    }

    int count() const
    {
        // Return current count of numbers
        return numbers.size();
    }
};

// Problem 2: String Compression
/**
Given a string word, compress it using the following algorithm:

Begin with an empty string comp. While word is not empty, use the following operation:
Remove a maximum length prefix of word made of a single character c repeating at most 9 times.
Append the length of the prefix followed by c to comp.
Return the string comp.
 */
string compressedString(string word)
{
    if (word.empty()) return "";
    string comp = "";
    int cnt = 1, n = word.size();
    char ch = word[0];
    for(int i=1;i<n;i++)
    {
        if(word[i] == ch && cnt < 9)cnt++;
        else
        {
            comp.push_back(cnt+'0');
            comp.push_back(ch);
            ch = word[i];
            cnt = 1;
        }
    }
    comp.push_back(cnt+'0');
    comp.push_back(ch);
    return comp;
}

// Problem 3: Balanced Binary Tree
/**
 * Given a binary tree, determine if it is height-balanced.
 * A height-balanced binary tree is a binary tree in which 
 * the height of the left and right subtree of any node 
 * differs by no more than 1.
 *
 * Example:
 *     3
 *    / \
 *   9  20
 *      / \
 *     15  7
 * This tree is balanced.
 *
 *     1
 *    / \
 *   2   2
 *  /     \
 * 3       3
 *  \
 *   4
 * This tree is not balanced.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int getHeight(TreeNode *node, bool &isBalanced)
{
    if (node == nullptr) return 0;
    int leftHeight = getHeight(node->left, isBalanced);
    int rightHeight = getHeight(node->right, isBalanced);
    if (abs(leftHeight - rightHeight) > 1)
        isBalanced = false;
    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(TreeNode *root)
{
    // Implement your solution here
    bool isBalanced = true;
    getHeight(root, isBalanced);
    return isBalanced;
}

class NumberConverter
{
private:
    vector<string> ones = {"", "one", "two", "three", "four", "five", "six", "seven",
        "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
        "sixteen", "seventeen", "eighteen", "nineteen"};
    vector<string> tens = {"", "", "twenty", "thirty", "forty", "fifty", "sixty",
        "seventy", "eighty", "ninety"};

    string convertLessThanHundred(int num)
    {
        if (num == 0)
            return "";
        else if (num < 20)
            return ones[num];
        else
        {
            string result = tens[num / 10];
            if (num % 10 > 0)
                result += " " + ones[num % 10];
            return result;
        }
    }

    string convertHundreds(int num)
    {
        string result;

        if (num >= 100)
        {
            result += ones[num / 100] + " hundred";
            num %= 100;
            if (num > 0) result += " ";
        }
        if (num > 0)
            result += convertLessThanHundred(num);
        return result;
    }

public:
    string convert(int num)
    {
        if (num == 0) return "zero";
        string result;
        if (num >= 1000)
        {
            result += convertHundreds(num / 1000) + " thousand";
            num %= 1000;
            if (num > 0)
                result += " ";
        }
        if (num > 0)
            result += convertHundreds(num);
        return result;
    }
};

// Problem 4: Number to Words
/**
 * Convert a positive integer to its English word representation.
 * Handle numbers from 0 to 999,999.
 * 
 * Example:
 * numberToWords(0) -> "zero"
 * numberToWords(15) -> "fifteen"
 * numberToWords(123) -> "one hundred twenty three"
 * numberToWords(12345) -> "twelve thousand three hundred forty five"
 * 
 * @param num Integer to convert (0 ≤ num ≤ 999,999)
 * @return String representation in English words
 */
string numberToWords(int num)
{
    // Implement your solution here
    NumberConverter converter;
    return converter.convert(num);
}

// Helper function to clean up binary tree memory
void cleanupTree(TreeNode* root)
{
    if (root)
    {
        cleanupTree(root->left);
        cleanupTree(root->right);
        delete root;
    }
}

// Test functions
void testRunningAverage() {
    cout << "\nTesting Problem 1: Running Average" << endl;
    cout << string(40, '-') << endl;

    try {
        RunningAverage avg(3);
        assert(abs(avg.add(5) - 5.0) < 0.01);
        assert(abs(avg.add(10) - 7.5) < 0.01);
        assert(abs(avg.add(8) - 7.67) < 0.01);
        assert(abs(avg.add(15) - 11.0) < 0.01);
        cout << "✓ All tests passed!" << endl;
    } catch (const exception& e) {
        cout << "✗ Test failed: " << e.what() << endl;
    }
}

void testStringCompression() {
    cout << "\nTesting Problem 2: String Compression" << endl;
    cout << string(40, '-') << endl;
    try {
        // Test Case 1: Basic compression with different characters
        assert(compressedString("aaa") == "3a");
        assert(compressedString("ab") == "1a1b");
        assert(compressedString("abc") == "1a1b1c");
        // Test Case 2: Multiple consecutive characters
        assert(compressedString("aabbb") == "2a3b");
        assert(compressedString("aaabbc") == "3a2b1c");
        // Test Case 3: Edge case - single character
        assert(compressedString("a") == "1a");
        // Test Case 4: Empty string
        assert(compressedString("") == "");
        // Test Case 5: Maximum repetition (9)
        assert(compressedString("aaaaaaaaa") == "9a");  // 9 a's
        // Test Case 6: Complex pattern with various counts
        assert(compressedString("aaabbcccccccccc") == "3a2b9c1c");
        // Test Case 7: Alternating characters
        assert(compressedString("ababab") == "1a1b1a1b1a1b");
        // Test Case 8: Multiple maximum sequences
        assert(compressedString("aaaaaaaaaaaaaaa") == "9a6a");  // 15 a's
        cout << "✓ All string compression tests passed!" << endl;
    } catch (const exception& e) {
        cout << "✗ Test failed: " << e.what() << endl;
    }
}

void testBalancedTree() {
    cout << "\nTesting Problem 3: Balanced Binary Tree" << endl;
    cout << string(40, '-') << endl;
    try {
        // Test Case 1: Balanced Tree
        TreeNode* root1 = new TreeNode(3);
        root1->left = new TreeNode(9);
        root1->right = new TreeNode(20);
        root1->right->left = new TreeNode(15);
        root1->right->right = new TreeNode(7);
        assert(isBalanced(root1) == true);
        cleanupTree(root1);

        // Test Case 2: Unbalanced Tree
        TreeNode* root2 = new TreeNode(1);
        root2->left = new TreeNode(2);
        root2->right = new TreeNode(2);
        root2->left->left = new TreeNode(3);
        root2->left->left->right = new TreeNode(4);
        assert(isBalanced(root2) == false);
        cleanupTree(root2);
        cout << "✓ All tests passed!" << endl;
    } catch (const exception& e) {
        cout << "✗ Test failed: " << e.what() << endl;
    }
}

void testNumberToWords() {
    cout << "\nTesting Problem 4: Number to Words" << endl;
    cout << string(40, '-') << endl;
    try {
        assert(numberToWords(0) == "zero");
        assert(numberToWords(15) == "fifteen");
        assert(numberToWords(123) == "one hundred twenty three");
        assert(numberToWords(12345) == "twelve thousand three hundred forty five");
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
    testRunningAverage();
    testStringCompression();
    testBalancedTree();
    testNumberToWords();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "\nAll tests completed in " << fixed << setprecision(2) 
         << duration.count() / 1000.0 << " seconds" << endl;
}

int main()
{
    cout << "\nC++ Coding Interview Questions" << endl;
    cout << string(30, '=') << endl;
    cout << "Time allowed: 60 minutes\n" << endl;
    cout << "Instructions:" << endl;
    cout << "- Implement the solution for each problem" << endl;
    cout << "- Use only standard C++ libraries" << endl;
    cout << "- Focus on both correctness and code quality" << endl;
    cout << "- Run this file to test your solutions" << endl;

    vector<pair<int, string>> problems = {
        {1, "Implement a running average calculator for the last N numbers."},
        {2, "Implement a simple string compression algorithm."},
        {3, "Determine if a binary tree is height-balanced."},
        {4, "Convert a number (0-999,999) to its English word representation."}
    };

    for (const auto& [num, desc] : problems) {
        printProblemDescription(num, desc);
    }

    runAllTests();
    return 0;
}
