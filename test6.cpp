/*
60-Minute C++ Beginner Coding Test: Algorithm Design and Problem Solving

Instructions:
1. Implement all the required functions according to the specifications
2. Make sure your code compiles and passes all test cases
3. Pay attention to edge cases and code efficiency
4. You have 60 minutes to complete all tasks
5. Each task has points assigned to it, totaling 100 points

Good luck!
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cassert>
#include <algorithm>

// Task 1 (20 points)
// Implement a function that rotates a matrix 90 degrees clockwise
// The matrix is represented as a vector of vectors
// Example: [[1, 2],      [[3, 1],
//          [3, 4]]  ->   [4, 2]]
void rotateMatrix(std::vector<std::vector<int>>& matrix) {
    // Your code here
}

// Task 2 (25 points)
// Create a class 'WeatherStation' that tracks temperature readings
class WeatherStation {
private:
    // Define your data members here

public:
    // Constructor
    WeatherStation() {
        // Your initialization code here
    }

    // Add a temperature reading
    void addReading(double temperature) {
        // Your code here
    }

    // Get the average of last N readings
    // Return -1 if N is greater than number of readings
    double getAverageOfLastN(int N) {
        // Your code here
        return 0.0;
    }

    // Get the highest temperature recorded so far
    double getHighestTemperature() {
        // Your code here
        return 0.0;
    }

    // Get the lowest temperature recorded so far
    double getLowestTemperature() {
        // Your code here
        return 0.0;
    }

    // Get count of readings within the specified range (inclusive)
    int getReadingsInRange(double minTemp, double maxTemp) {
        // Your code here
        return 0;
    }
};

// Task 3 (25 points)
// Implement a function that compresses a string using run-length encoding
// For each sequence of repeated characters, write the character followed by count
// Only encode sequences of 2 or more repeated characters
// Example: "AABBBCCCC" → "A2B3C4"
// Example: "ABCDE" → "ABCDE" (no compression needed)
std::string compressString(const std::string& input) {
    // Your code here
    return "";
}

// Task 4 (30 points)
// Create a class 'OrderBook' that manages a simple order matching system
class OrderBook {
private:
    // Define your data members here

public:
    enum OrderType {
        BUY,
        SELL
    };

    struct Order {
        int orderId;
        OrderType type;
        double price;
        int quantity;
    };

    // Constructor
    OrderBook() {
        // Your initialization code here
    }

    // Add a new order to the book
    // Return true if order was added successfully
    // Return false if orderId already exists
    bool addOrder(int orderId, OrderType type, double price, int quantity) {
        // Your code here
        return false;
    }

    // Cancel an existing order
    // Return true if order was found and cancelled
    // Return false if order doesn't exist
    bool cancelOrder(int orderId) {
        // Your code here
        return false;
    }

    // Get the best (highest) buy price currently in the order book
    // Return -1 if no buy orders exist
    double getBestBuyPrice() {
        // Your code here
        return 0.0;
    }

    // Get the best (lowest) sell price currently in the order book
    // Return -1 if no sell orders exist
    double getBestSellPrice() {
        // Your code here
        return 0.0;
    }

    // Get total quantity of all orders at a specific price
    int getTotalQuantityAtPrice(double price) {
        // Your code here
        return 0;
    }
};

// Test cases
int main() {
    // Test Task 1: Matrix Rotation
    {
        std::vector<std::vector<int>> matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        std::vector<std::vector<int>> expected = {
            {7, 4, 1},
            {8, 5, 2},
            {9, 6, 3}
        };
        rotateMatrix(matrix);
        assert(matrix == expected);

        // Test empty matrix
        std::vector<std::vector<int>> empty;
        rotateMatrix(empty);
        assert(empty.empty());

        // Test 1x1 matrix
        std::vector<std::vector<int>> single = {{1}};
        rotateMatrix(single);
        assert(single == std::vector<std::vector<int>>{{1}});
    }

    // Test Task 2: Weather Station
    {
        WeatherStation station;
        station.addReading(23.5);
        station.addReading(22.0);
        station.addReading(24.5);
        station.addReading(23.0);

        assert(station.getAverageOfLastN(2) == 23.75);
        assert(station.getHighestTemperature() == 24.5);
        assert(station.getLowestTemperature() == 22.0);
        assert(station.getReadingsInRange(23.0, 24.0) == 2);
        assert(station.getAverageOfLastN(5) == -1);  // Not enough readings
    }

    // Test Task 3: String Compression
    {
        assert(compressString("AABBBCCCC") == "A2B3C4");
        assert(compressString("ABCDE") == "ABCDE");
        assert(compressString("") == "");
        assert(compressString("AAA") == "A3");
        assert(compressString("AAABBAAA") == "A3B2A3");
    }

    // Test Task 4: Order Book
    {
        OrderBook book;
        assert(book.addOrder(1, OrderBook::BUY, 100.0, 10));
        assert(!book.addOrder(1, OrderBook::BUY, 101.0, 5));  // Duplicate ID
        assert(book.addOrder(2, OrderBook::SELL, 102.0, 15));

        assert(book.getBestBuyPrice() == 100.0);
        assert(book.getBestSellPrice() == 102.0);
        assert(book.getTotalQuantityAtPrice(100.0) == 10);

        assert(book.cancelOrder(1));
        assert(!book.cancelOrder(999));  // Non-existent order
        assert(book.getBestBuyPrice() == -1);  // No buy orders left
    }

    std::cout << "All tests passed!\n";
    return 0;
}
