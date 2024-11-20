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
            std::lock_guard<std::mutex> lock(mutex);
            if (instance == nullptr) {
                instance = std::shared_ptr<Logger>(new Logger());
            }
            return instance;
        }
        
        void log(const std::string& message) {
            std::lock_guard<std::mutex> lock(mutex);
            logs.push_back(message);
        }
        
        std::vector<std::string> getLogs() const {
            return logs;
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
            auto it = map.find(key);
            if (it == map.end()) {
                throw std::runtime_error("Key not found");
            }
            
            cache.splice(cache.begin(), cache, it->second);
            return it->second->second;
        }
        
        void put(const K& key, const V& value) {
            // TODO: Implement put operation
            // If key exists, update value and move to front
            // If key doesn't exist, add new entry
            // If cache is full, remove least recently used item
            auto it = map.find(key);
            if (it != map.end()) {
                it->second->second = value;
                cache.splice(cache.begin(), cache, it->second);
                return;
            }
            
            if (cache.size() >= capacity) {
                auto last = cache.back();
                map.erase(last.first);
                cache.pop_back();
            }
            
            cache.push_front({key, value});
            map[key] = cache.begin();
        }
        
        size_t size() const {
            return cache.size();
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
            if (!root) return "null";
            
            std::string result = std::to_string(root->val);
            result += "," + serialize(root->left);
            result += "," + serialize(root->right);
            
            return result;
        }
        
        TreeNode* deserialize(const std::string& data) {
            // TODO: Implement tree deserialization
            // Convert string representation back to binary tree
            std::queue<std::string> nodes;
            std::string current;
            for (char c : data) {
                if (c == ',') {
                    nodes.push(current);
                    current.clear();
                } else {
                    current += c;
                }
            }
            if (!current.empty()) {
                nodes.push(current);
            }
            
            return deserializeHelper(nodes);
        }
        
    private:
        TreeNode* deserializeHelper(std::queue<std::string>& nodes) {
            if (nodes.empty()) return nullptr;
            
            std::string val = nodes.front();
            nodes.pop();
            
            if (val == "null") return nullptr;
            
            TreeNode* node = new TreeNode(std::stoi(val));
            node->left = deserializeHelper(nodes);
            node->right = deserializeHelper(nodes);
            
            return node;
        }
    };

    // Task 4: Implement a parallel merge sort algorithm
    class ParallelMergeSort {
    public:
        void sort(std::vector<int>& arr) {
            // TODO: Implement parallel merge sort
            // Use std::thread for parallelization
            if (arr.size() <= 1) return;
            
            size_t mid = arr.size() / 2;
            std::vector<int> left(arr.begin(), arr.begin() + mid);
            std::vector<int> right(arr.begin() + mid, arr.end());
            
            // Create threads for sorting both halves
            std::thread leftThread([&]() { sort(left); });
            std::thread rightThread([&]() { sort(right); });
            
            leftThread.join();
            rightThread.join();
            
            // Merge the sorted halves
            merge(arr, left, right);
        }
        
    private:
        void merge(std::vector<int>& arr, const std::vector<int>& left, const std::vector<int>& right) {
            size_t i = 0, j = 0, k = 0;
            
            while (i < left.size() && j < right.size()) {
                if (left[i] <= right[j]) {
                    arr[k++] = left[i++];
                } else {
                    arr[k++] = right[j++];
                }
            }
            
            while (i < left.size()) {
                arr[k++] = left[i++];
            }
            
            while (j < right.size()) {
                arr[k++] = right[j++];
            }
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

int main() {
    runTests();
    return 0;
}
