// C++ Coding Test
// Time limit: 60 minutes
// Instructions: Implement all the functions below according to their specifications.
// Make sure all test cases pass. Focus on efficiency and proper memory management.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <memory>
#include <cassert>
#include <string>
#include <queue>

class Solution {
public:
    // Task 1: Implement a thread-safe singleton pattern
    class Logger {
    private:
        static std::shared_ptr<Logger> instance;
        static std::mutex mutex;
        std::vector<std::string> logs;
        
        // Private constructor
        Logger() = default;
        
    public:
        // Delete copy constructor and assignment operator
        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;
        
        static std::shared_ptr<Logger> getInstance() {
            // TODO: Implement thread-safe singleton pattern using double-checked locking
            // Return the singleton instance of the logger
        }
        
        void log(const std::string& message) {
            // TODO: Implement thread-safe logging
            // Add the message to logs vector
        }
        
        std::vector<std::string> getLogs() const {
            // TODO: Implement getter for logs
            // Return the vector of logged messages
        }
    };

    // Task 2: Implement an LRU (Least Recently Used) Cache
    template<typename K, typename V>
    class LRUCache {
    private:
        size_t capacity;
        std::list<std::pair<K, V>> cache;
        std::unordered_map<K, typename std::list<std::pair<K, V>>::iterator> map;
        
    public:
        LRUCache(size_t size) : capacity(size) {}
        
        V get(const K& key) {
            // TODO: Implement get operation
            // Return the value if found, or throw exception if not found
            // Move accessed item to front of cache (most recently used position)
        }
        
        void put(const K& key, const V& value) {
            // TODO: Implement put operation
            // If key exists, update value and move to front
            // If key doesn't exist, add new entry
            // If cache is full, remove least recently used item
        }
        
        size_t size() const {
            // TODO: Return current size of cache
        }
    };

    // Task 3: Implement a binary tree serializer/deserializer
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    class TreeSerializer {
    public:
        std::string serialize(TreeNode* root) {
            // TODO: Implement tree serialization
            // Convert binary tree to a string representation
        }
        
        TreeNode* deserialize(const std::string& data) {
            // TODO: Implement tree deserialization
            // Convert string representation back to binary tree
        }
        
    private:
        TreeNode* deserializeHelper(std::queue<std::string>& nodes) {
            // TODO: Helper method for deserialization
        }
    };

    // Task 4: Implement a parallel merge sort algorithm
    class ParallelMergeSort {
    public:
        void sort(std::vector<int>& arr) {
            // TODO: Implement parallel merge sort
            // Use std::thread for parallelization
        }
        
    private:
        void merge(std::vector<int>& arr, const std::vector<int>& left, const std::vector<int>& right) {
            // TODO: Implement merge operation for sorted arrays
        }
    };
};

// Initialize static members
std::shared_ptr<Solution::Logger> Solution::Logger::instance = nullptr;
std::mutex Solution::Logger::mutex;

// Test cases
void runTests() {
    Solution sol;
    
    // Test Task 1: Logger Singleton
    {
        auto logger1 = Solution::Logger::getInstance();
        auto logger2 = Solution::Logger::getInstance();
        assert(logger1 == logger2);  // Same instance
        
        logger1->log("Test message 1");
        logger2->log("Test message 2");
        auto logs = logger1->getLogs();
        assert(logs.size() == 2);
        assert(logs[0] == "Test message 1");
        assert(logs[1] == "Test message 2");
    }
    
    // Test Task 2: LRU Cache
    {
        Solution::LRUCache<int, std::string> cache(2);
        cache.put(1, "one");
        cache.put(2, "two");
        assert(cache.get(1) == "one");
        cache.put(3, "three");  // Should evict key 2
        try {
            cache.get(2);
            assert(false);  // Should not reach here
        } catch (const std::runtime_error&) {
            // Expected exception
        }
        assert(cache.get(3) == "three");
    }
    
    // Test Task 3: Tree Serialization
    {
        Solution::TreeSerializer serializer;
        auto root = new Solution::TreeNode(1);
        root->left = new Solution::TreeNode(2);
        root->right = new Solution::TreeNode(3);
        root->right->left = new Solution::TreeNode(4);
        
        std::string serialized = serializer.serialize(root);
        auto deserializedRoot = serializer.deserialize(serialized);
        
        assert(deserializedRoot->val == 1);
        assert(deserializedRoot->left->val == 2);
        assert(deserializedRoot->right->val == 3);
        assert(deserializedRoot->right->left->val == 4);
    }
    
    // Test Task 4: Parallel Merge Sort
    {
        std::vector<int> arr = {5, 2, 8, 1, 9, 3, 7, 4, 6};
        Solution::ParallelMergeSort sorter;
        sorter.sort(arr);
        
        for (size_t i = 1; i < arr.size(); i++) {
            assert(arr[i-1] <= arr[i]);
        }
    }
    
    std::cout << "All tests passed!" << std::endl;
}

int main()
{
    runTests();
    return 0;
}
