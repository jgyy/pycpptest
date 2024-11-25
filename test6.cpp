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
#include <unordered_map>

// Task 1 (20 points)
// Implement a function that rotates a matrix 90 degrees clockwise
// The matrix is represented as a vector of vectors
// Example: [[1, 2],      [[3, 1],
//          [3, 4]]  ->   [4, 2]]
void rotateMatrix(std::vector<std::vector<int>> &matrix)
{
    // Your code here
    if (matrix.empty()) return;
    int n = matrix.size();
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            std::swap(matrix[i][j], matrix[j][i]);
    for (int i = 0; i < n; i++)
        std::reverse(matrix[i].begin(), matrix[i].end());
}

// Task 2 (25 points)
// Create a class 'WeatherStation' that tracks temperature readings
class WeatherStation
{
private:
    // Define your data members here
    std::deque<double> readings;
    double highest = -1000.0;
    double lowest = 1000.0;

public:
    // Constructor
    WeatherStation() {}

    // Add a temperature reading
    void addReading(double temperature)
    {
        // Your code here
        readings.push_back(temperature);
        highest = std::max(highest, temperature);
        lowest = std::min(lowest, temperature);
    }

    // Get the average of last N readings
    // Return -1 if N is greater than number of readings
    double getAverageOfLastN(int N)
    {
        // Your code here
        if (N > readings.size())
            return -1;
        double sum = 0;
        auto it = readings.rbegin();
        for (int i = 0; i < N; i++)
            sum += *it++;
        return sum / N;
    }

    // Get the highest temperature recorded so far
    double getHighestTemperature()
    {
        // Your code here
        return highest;
    }

    // Get the lowest temperature recorded so far
    double getLowestTemperature()
    {
        // Your code here
        return lowest;
    }

    // Get count of readings within the specified range (inclusive)
    int getReadingsInRange(double minTemp, double maxTemp)
    {
        // Your code here
        return std::count_if(readings.begin(), readings.end(),
            [minTemp, maxTemp](double temp) {
                return temp >= minTemp && temp <= maxTemp;
            });
    }
};

// Task 3 (25 points)
// Implement a function that compresses a string using run-length encoding
// For each sequence of repeated characters, write the character followed by count
// Only encode sequences of 2 or more repeated characters
// Example: "AABBBCCCC" → "A2B3C4"
// Example: "ABCDE" → "ABCDE" (no compression needed)
std::string compressString(const std::string &input)
{
    // Your code here
    if (input.empty())
        return "";
    std::string result;
    char current = input[0];
    int count = 1;
    for (size_t i = 1; i <= input.length(); i++)
    {
        if (i < input.length() && input[i] == current)
            count++;
        else
        {
            if (count > 1)
                result += current + std::to_string(count);
            else
                result += current;
            if (i < input.length())
            {
                current = input[i];
                count = 1;
            }
        }
    }
    return result;
}

// Task 4 (30 points)
// Create a class 'OrderBook' that manages a simple order matching system
class OrderBook
{
public:
    enum OrderType
    {
        BUY,
        SELL
    };

    struct Order
    {
        int orderId;
        OrderType type;
        double price;
        int quantity;
    };

private:
    // Define your data members here
    struct OrderInfo
    {
        OrderType type;
        double price;
        int quantity;
    };
    std::unordered_map<int, OrderInfo> orders;
    std::map<double, int, std::greater<double>> buyOrders;
    std::map<double, int> sellOrders;

public:
    // Constructor
    OrderBook() {}

    // Add a new order to the book
    // Return true if order was added successfully
    // Return false if orderId already exists
    bool addOrder(int orderId, OrderType type, double price, int quantity)
    {
        // Your code here
        if (orders.find(orderId) != orders.end())
            return false;
        orders[orderId] = {type, price, quantity};
        if (type == BUY)
            buyOrders[price] += quantity;
        else
            sellOrders[price] += quantity;
        return true;
    }

    // Cancel an existing order
    // Return true if order was found and cancelled
    // Return false if order doesn't exist
    bool cancelOrder(int orderId)
    {
        // Your code here
        auto it = orders.find(orderId);
        if (it == orders.end())
            return false;
        OrderInfo &info = it->second;
        if (info.type == BUY)
        {
            buyOrders[info.price] -= info.quantity;
            if (buyOrders[info.price] == 0)
                buyOrders.erase(info.price);
        }
        else
        {
            sellOrders[info.price] -= info.quantity;
            if (sellOrders[info.price] == 0)
                sellOrders.erase(info.price);
        }
        orders.erase(it);
        return true;
    }

    // Get the best (highest) buy price currently in the order book
    // Return -1 if no buy orders exist
    double getBestBuyPrice()
    {
        // Your code here
        if (buyOrders.empty())
            return -1;
        return buyOrders.begin()->first;
    }

    // Get the best (lowest) sell price currently in the order book
    // Return -1 if no sell orders exist
    double getBestSellPrice()
    {
        // Your code here
        if (sellOrders.empty())
            return -1;
        return sellOrders.begin()->first;
    }

    // Get total quantity of all orders at a specific price
    int getTotalQuantityAtPrice(double price)
    {
        // Your code here
        int buyQty = buyOrders.count(price) ? buyOrders[price] : 0;
        int sellQty = sellOrders.count(price) ? sellOrders[price] : 0;
        return buyQty + sellQty;
    }
};

// Test cases
int main()
{
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
