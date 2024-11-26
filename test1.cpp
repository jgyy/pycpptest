// C++ Beginner Coding Test (15 minutes)
// Write your solutions in the marked spaces below each question

/*
Question 1: Student Grade (5 minutes)
Create a class called Student that stores a student's name and their grades.
Implement the required methods to add grades and calculate average.
*/
#include <iostream>
#include <vector>

class Student
{
private:
    std::string name;
    std::vector<int> grades;

public:
    // TODO: Write a constructor that takes the student's name
    Student(std::string name) : name(name) {}

    // TODO: Write a method called addGrade that takes an integer grade
    //       and adds it to the grades vector
    void addGrade(int grade)
    {
        grades.push_back(grade);
    }

    // TODO: Write a method called getAverage that returns the average 
    //       of all grades as a float
    float getAverage()
    {
        float average = 0.0f;
        float total = 0.0f;
        if (grades.empty())
            return 0.0;
        for (int i = 0; i < static_cast<int>(grades.size()); i++)
            total += static_cast<float>(grades[i]);
        average = total / grades.size();
        return average;
    }

    // TODO: Write a method called getName that returns the student's name
    std::string getName()
    {
        return name;
    }
};

/*
Question 2: Shopping Cart (5 minutes)
Complete the ShoppingCart class that stores items and their quantities.
*/

class ShoppingCart
{
private:
    // TODO: Create a vector to store item names
    // TODO: Create a vector to store quantities
    std::vector<std::pair<std::string, int>> carts;

public:
    ShoppingCart() {}

    // TODO: Add an item with its quantity to the cart
    void addItem(std::string item, int quantity)
    {
        // Your code here
        carts.push_back({item, quantity});
    }

    // TODO: Return the total number of items in the cart
    int getTotalItems()
    {
        // Your code here
        int total = 0;
        if (carts.empty())
            return 0;
        for (auto item : carts)
            total += item.second;
        return total;
    }

    // TODO: Check if an item exists in the cart (return true/false)
    bool hasItem(std::string item)
    {
        // Your code here
        if (carts.empty())
            return false;
        for (auto items : carts)
            if (items.first == item)
                return true;
        return false;
    }
};

/*
Question 3: Number Array Processing (5 minutes)
Complete the following functions to process arrays of numbers
*/

// TODO: Write a function that takes a vector of integers
// and returns a new vector with only the even numbers
std::vector<int> getEvenNumbers(const std::vector<int>& numbers)
{
    // Your code here
    std::vector<int> even;
    for (int i : numbers)
        if (i % 2 == 0)
            even.push_back(i);
    return even;
}

// TODO: Write a function that takes a vector of integers
// and returns the largest number
int findLargest(const std::vector<int>& numbers)
{
    // Your code here
    int largest = 0;
    for (int i : numbers)
        if (i > largest)
            largest = i;
    return largest;
}

int main()
{
    // Test Student class
    Student student("John");
    student.addGrade(85);
    student.addGrade(90);
    student.addGrade(88);
    std::cout << "Average grade: " << student.getAverage() << std::endl;

    // Test ShoppingCart class
    ShoppingCart cart;
    cart.addItem("Apple", 3);
    cart.addItem("Banana", 2);
    std::cout << "Total items: " << cart.getTotalItems() << std::endl;
    std::cout << "Has apples: " << cart.hasItem("Apple") << std::endl;

    // Test number processing
    std::vector<int> numbersMain = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> evenNums = getEvenNumbers(numbersMain);
    std::cout << "Largest: " << findLargest(numbersMain) << std::endl;

    return 0;
}
