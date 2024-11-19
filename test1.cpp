// C++ Coding Test
// Time limit: 60 minutes
// Instructions: Complete all the functions below according to their specifications.
// Each function has its own test cases that must pass.

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <stack>

class Solution {
public:
    // Task 1: Implement a custom string class with basic operations
    class MyString {
    private:
        char* data;
        size_t length;
        
    public:
        // Constructor
        MyString(const char* str = "") {
            // TODO: Implement constructor that copies the input string
        }
        
        // Destructor
        ~MyString() {
            // TODO: Implement destructor to free memory
        }
        
        // Copy constructor
        MyString(const MyString& other) {
            // TODO: Implement deep copy constructor
        }
        
        // Assignment operator
        MyString& operator=(const MyString& other) {
            // TODO: Implement deep copy assignment operator
            return *this;
        }
        
        // Get string length
        size_t size() const {
            // TODO: Return string length
            return 0;
        }
        
        // Convert to C-style string
        const char* c_str() const {
            // TODO: Return pointer to internal string
            return nullptr;
        }
    };

    // Task 2: Find the longest palindromic substring
    std::string longestPalindrome(std::string s) {
        /*
        * Find the longest palindromic substring in the given string
        * 
        * Example:
        * Input: "babad"
        * Output: "bab" or "aba"
        */
        return "";
    }

    // Task 3: Implement a queue using two stacks
    class MyQueue {
    private:
        std::stack<int> stack1;
        std::stack<int> stack2;
        
    public:
        MyQueue() {
            
        }
        
        void push(int x) {
            // TODO: Implement push operation
        }
        
        int pop() {
            // TODO: Implement pop operation
            return 0;
        }
        
        int peek() {
            // TODO: Implement peek operation
            return 0;
        }
        
        bool empty() {
            // TODO: Implement empty check
            return true;
        }
    };

    // Task 4: Find the kth largest element in an array
    int findKthLargest(std::vector<int>& nums, int k) {
        /*
        * Find the kth largest element in an unsorted array
        * 
        * Example:
        * Input: nums = [3,2,1,5,6,4], k = 2
        * Output: 5
        */
        return 0;
    }
};

// Test cases
void runTests() {
    Solution sol;
    
    // Test Task 1
    {
        Solution::MyString str1("Hello");
        assert(str1.size() == 5);
        assert(strcmp(str1.c_str(), "Hello") == 0);
        
        Solution::MyString str2 = str1;  // Test copy constructor
        assert(strcmp(str2.c_str(), "Hello") == 0);
        
        Solution::MyString str3;
        str3 = str1;  // Test assignment operator
        assert(strcmp(str3.c_str(), "Hello") == 0);
    }
    
    // Test Task 2
    {
        assert(sol.longestPalindrome("babad") == "bab" || 
               sol.longestPalindrome("babad") == "aba");
        assert(sol.longestPalindrome("cbbd") == "bb");
        assert(sol.longestPalindrome("a") == "a");
    }
    
    // Test Task 3
    {
        Solution::MyQueue queue;
        queue.push(1);
        queue.push(2);
        assert(queue.peek() == 1);
        assert(queue.pop() == 1);
        assert(!queue.empty());
        assert(queue.pop() == 2);
        assert(queue.empty());
    }
    
    // Test Task 4
    {
        std::vector<int> nums1 = {3,2,1,5,6,4};
        assert(sol.findKthLargest(nums1, 2) == 5);
        
        std::vector<int> nums2 = {3,2,3,1,2,4,5,5,6};
        assert(sol.findKthLargest(nums2, 4) == 4);
    }
    
    std::cout << "All tests passed!" << std::endl;
}

int main() {
    runTests();
    return 0;
}
