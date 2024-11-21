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
#include <mutex>
#include <sstream>
#include <thread>
#include <cmath>
#include <algorithm>

class Solution
{
public:
    // Task 1: Implement a thread-safe singleton pattern
    class Logger
    {
    private:
        static std::shared_ptr<Logger> instance;
        static std::mutex mutex;
        std::vector<std::string> logs;

        // Private constructor
        Logger() = default;

    public:
        // Delete copy constructor and assignment operator
        Logger(const Logger&) = delete;
        Logger &operator=(const Logger&) = delete;

        // TODO: Implement thread-safe singleton pattern using double-checked locking
        static std::shared_ptr<Logger> getInstance()
        {
            if (!instance)
            {
                std::lock_guard<std::mutex> lock(mutex);
                if (!instance)
                    instance = std::shared_ptr<Logger>(new Logger());
            }
            return instance;
        }

        void log(const std::string& message)
        {
            // TODO: Implement thread-safe logging
            std::lock_guard<std::mutex> lock(mutex);
            logs.push_back(message);
        }

        std::vector<std::string> getLogs() const
        {
            // TODO: Implement getter for logs
            std::lock_guard<std::mutex> lock(mutex);
            return logs;
        }
    };

    // Task 2: Implement an LRU (Least Recently Used) Cache
    template<typename K, typename V>
    class LRUCache
    {
    private:
        size_t capacity;
        std::list<std::pair<K, V>> cache;
        std::unordered_map<K, typename std::list<std::pair<K, V>>::iterator> map;

    public:
        LRUCache(size_t size) : capacity(size) {}

        V get(const K& key)
        {
            // TODO: Implement get operation
            auto it = map.find(key);
            if (it == map.end())
                throw std::runtime_error("Key not found");
            cache.splice(cache.begin(), cache, it->second);
            return it->second->second;
        }

        void put(const K& key, const V& value)
        {
            // TODO: Implement put operation
            auto it = map.find(key);
            if (it != map.end())
            {
                it->second->second = value;
                cache.splice(cache.begin(), cache, it->second);
            }
            else
            {
                if (cache.size() >= capacity)
                {
                    auto last = cache.back();
                    map.erase(last.first);
                    cache.pop_back();
                }
                cache.push_front({key, value});
                map[key] = cache.begin();
            }
        }

        size_t size() const
        {
            // TODO: Return current size of cache
            return cache.size();
        }
    };

    // Task 3: Implement a binary tree serializer/deserializer
    struct TreeNode
    {
        int val;
        std::unique_ptr<TreeNode> left;
        std::unique_ptr<TreeNode> right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    class TreeSerializer
    {
    public:
        std::string serialize(TreeNode* root)
        {
            // TODO: Implement tree serialization
            if (!root) return "null";
            std::string result;
            std::queue<TreeNode *> q;
            q.push(root);
            while (!q.empty())
            {
                TreeNode *current = q.front();
                q.pop();
                if (current == nullptr)
                {
                    result += "null ";
                    continue;
                }
                result += std::to_string(current->val) + " ";
                q.push(current->left.get());
                q.push(current->right.get());
            }
            return result;
        }

        std::unique_ptr<TreeNode> deserialize(const std::string &data)
        {
            // TODO: Implement tree deserialization
            if (data == "null") return nullptr;
            std::istringstream iss(data);
            std::string val;
            iss >> val;
            if (val == "null") return nullptr;
            auto root = std::make_unique<TreeNode>(std::stoi(val));
            std::queue<TreeNode *> q;
            q.push(root.get());
            while (!q.empty() && iss >> val)
            {
                TreeNode *current = q.front();
                q.pop();
                if (val != "null")
                {
                    current->left = std::make_unique<TreeNode>(std::stoi(val));
                    q.push(current->left.get());
                }
                if (iss >> val)
                {
                    if (val != "null")
                    {
                        current->right = std::make_unique<TreeNode>(std::stoi(val));
                        q.push(current->right.get());
                    }
                }
            }
            return root;
        }

    private:
    };

    // Task 4: Implement a parallel merge sort algorithm
    class ParallelMergeSort
    {
    public:
        void sort(std::vector<int>& arr)
        {
            // TODO: Implement parallel merge sort
            if (arr.size() <= 1) return;
            int max_depth = static_cast<int>(std::log2(std::thread::hardware_concurrency()));
            parallel_sort_internal(arr, 0, arr.size(), max_depth);
        }

    private:
        static const size_t SEQUENTIAL_THRESHOLD = 1000;

        void sequential_sort(std::vector<int> &arr, size_t begin, size_t end)
        {
            std::sort(arr.begin() + begin, arr.begin() + end);
        }

        void merge(std::vector<int> &arr, size_t begin, size_t mid, size_t end)
        {
            // TODO: Implement merge operation for sorted arrays
            std::vector<int> temp(end - begin);
            size_t i = begin, j = mid, k = 0;
            while (i < mid && j < end)
            {
                if (arr[i] <= arr[j])
                    temp[k++] = arr[i++];
                else
                    temp[k++] = arr[j++];
            }
            while (i < mid) temp[k++] = arr[i++];
            while (j < end) temp[k++] = arr[j++];
            std::copy(temp.begin(), temp.end(), arr.begin() + begin);
        }

        void parallel_sort_internal(std::vector<int> &arr, size_t begin, size_t end, int depth)
        {
            if (end - begin <= SEQUENTIAL_THRESHOLD || depth <= 0)
            {
                sequential_sort(arr, begin, end);
                return;
            }
            size_t mid = begin + (end - begin) / 2;
            std::thread left_thread([&]() {
                parallel_sort_internal(arr, begin, mid, depth - 1);
            });
            parallel_sort_internal(arr, mid, end, depth - 1);
            left_thread.join();
            merge(arr, begin, mid, end);
        }
    };
};

// Initialize static members
std::shared_ptr<Solution::Logger> Solution::Logger::instance = nullptr;
std::mutex Solution::Logger::mutex;

void runTreeTests() {
    Solution::TreeSerializer serializer;

    // Test empty tree
    auto emptyTree = serializer.deserialize("null");
    assert(emptyTree == nullptr);

    // Test single node tree
    auto singleNode = std::make_unique<Solution::TreeNode>(1);
    std::string serialized = serializer.serialize(singleNode.get());
    auto deserialized = serializer.deserialize(serialized);
    assert(deserialized->val == 1);
    assert(deserialized->left == nullptr);
    assert(deserialized->right == nullptr);

    // Test complete binary tree
    auto root = std::make_unique<Solution::TreeNode>(1);
    root->left = std::make_unique<Solution::TreeNode>(2);
    root->right = std::make_unique<Solution::TreeNode>(3);
    root->left->left = std::make_unique<Solution::TreeNode>(4);
    root->left->right = std::make_unique<Solution::TreeNode>(5);
    root->right->left = std::make_unique<Solution::TreeNode>(6);
    root->right->right = std::make_unique<Solution::TreeNode>(7);

    serialized = serializer.serialize(root.get());
    auto deserializedRoot = serializer.deserialize(serialized);

    assert(deserializedRoot->val == 1 && "Root value should match");
    assert(deserializedRoot->left->val == 2 && "Left child should match");
    assert(deserializedRoot->right->val == 3 && "Right child should match");
    assert(deserializedRoot->left->left->val == 4 && "Left-left child should match");
    assert(deserializedRoot->left->right->val == 5 && "Left-right child should match");
    assert(deserializedRoot->right->left->val == 6 && "Right-left child should match");
    assert(deserializedRoot->right->right->val == 7 && "Right-right child should match");
}

void testParallelSort() {
    Solution::ParallelMergeSort sorter;

    // Test empty vector
    std::vector<int> empty;
    sorter.sort(empty);
    assert(empty.empty());

    // Test single element
    std::vector<int> single = {1};
    sorter.sort(single);
    assert(single.size() == 1 && single[0] == 1);

    // Test small array
    std::vector<int> small = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    std::vector<int> small_sorted = small;
    std::sort(small_sorted.begin(), small_sorted.end());
    sorter.sort(small);
    assert(small == small_sorted);

    // Test medium array
    std::vector<int> medium(1000);
    std::generate(medium.begin(), medium.end(), std::rand);
    std::vector<int> medium_sorted = medium;
    std::sort(medium_sorted.begin(), medium_sorted.end());
    sorter.sort(medium);
    assert(medium == medium_sorted);

    // Test large array
    std::vector<int> large(100000);
    std::generate(large.begin(), large.end(), std::rand);
    std::vector<int> large_sorted = large;
    std::sort(large_sorted.begin(), large_sorted.end());
    sorter.sort(large);
    assert(large == large_sorted);

    // Test already sorted array
    std::vector<int> sorted = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    sorter.sort(sorted);
    for (size_t i = 1; i < sorted.size(); i++) {
        assert(sorted[i-1] <= sorted[i]);
    }

    // Test reverse sorted array
    std::vector<int> reverse = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    sorter.sort(reverse);
    for (size_t i = 1; i < reverse.size(); i++) {
        assert(reverse[i-1] <= reverse[i]);
    }
}

// Test cases
void runTests() {
    Solution sol;
    bool allTestsPassed = true;

    try {
        std::cout << "Running Logger Singleton tests..." << std::endl;
        {
            auto logger1 = Solution::Logger::getInstance();
            auto logger2 = Solution::Logger::getInstance();
            assert(logger1 == logger2 && "Logger instances should be the same");

            logger1->log("Test message 1");
            logger2->log("Test message 2");
            auto logs = logger1->getLogs();
            assert(logs.size() == 2 && "Logger should have 2 messages");
            assert(logs[0] == "Test message 1" && "First message should match");
            assert(logs[1] == "Test message 2" && "Second message should match");

            // Test concurrent logging
            std::vector<std::thread> threads;
            for (int i = 0; i < 10; i++) {
                threads.emplace_back([logger1, i]() {
                    logger1->log("Thread message " + std::to_string(i));
                });
            }
            for (auto& thread : threads) {
                thread.join();
            }
            
            logs = logger1->getLogs();
            assert(logs.size() == 12 && "Logger should have 12 messages after concurrent logging");
        }
        std::cout << "Logger Singleton tests passed!" << std::endl;

        std::cout << "Running LRU Cache tests..." << std::endl;
        {
            Solution::LRUCache<int, std::string> cache(2);
            
            // Basic operations
            cache.put(1, "one");
            assert(cache.size() == 1 && "Cache size should be 1");
            
            cache.put(2, "two");
            assert(cache.size() == 2 && "Cache size should be 2");
            
            assert(cache.get(1) == "one" && "Should retrieve correct value");
            
            // Test eviction
            cache.put(3, "three");
            assert(cache.size() == 2 && "Cache size should remain 2");
            
            try {
                cache.get(2);
                assert(false && "Should throw exception for evicted key");
            } catch (const std::runtime_error&) {
                // Expected
            }
            
            // Test update of existing key
            cache.put(1, "ONE");
            assert(cache.get(1) == "ONE" && "Should update existing key");
            assert(cache.size() == 2 && "Size should remain unchanged after update");
        }
        std::cout << "LRU Cache tests passed!" << std::endl;

        std::cout << "Running Tree Serialization tests..." << std::endl;
        runTreeTests();
        std::cout << "Tree Serialization tests passed!" << std::endl;

        std::cout << "Running Parallel Merge Sort tests..." << std::endl;
        testParallelSort();
        std::cout << "Parallel Merge Sort tests passed!" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Test failed with exception: " << e.what() << std::endl;
        allTestsPassed = false;
    }

    if (allTestsPassed) {
        std::cout << "All tests passed successfully!" << std::endl;
    } else {
        std::cout << "Some tests failed!" << std::endl;
        exit(1);
    }
}

int main()
{
    runTests();
    return 0;
}
