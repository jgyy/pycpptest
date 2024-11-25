/*
60-Minute C++ Beginner Coding Test

Instructions:
1. Implement all the required functions and the class according to the specifications
2. Make sure your code compiles and passes all test cases
3. Pay attention to edge cases
4. You have 60 minutes to complete all tasks
5. Each task has points assigned to it, totaling 100 points

Good luck!
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cassert>

// Task 1 (20 points)
// Implement a function that takes an array of integers and its size as parameters
// Return the second largest element in the array
// If array has less than 2 elements, return -1
// Example: [1, 5, 2, 9, 3] → 5
int findSecondLargest(int arr[], int size)
{
    // Your code here
    if (size < 2)
        return -1;
    int largest = arr[0];
    int secondLargest = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > largest)
            largest = arr[i];
    secondLargest = arr[0] == largest ? arr[1] : arr[0];
    for (int i = 0; i < size; i++)
        if (arr[i] != largest && arr[i] > secondLargest)
            secondLargest = arr[i];
    return secondLargest;
}

// Task 2 (25 points)
// Implement a function that checks if a string is a valid password
// Password rules:
// - At least 8 characters long
// - Contains at least one uppercase letter
// - Contains at least one lowercase letter
// - Contains at least one number
// Return true if password is valid, false otherwise
bool isValidPassword(std::string password)
{
    // Your code here
    if (password.length() < 8)
        return false;
    bool hasUpper = false;
    bool hasLower = false;
    bool hasNumber = false;
    for (char c : password)
    {
        if (isupper(c)) hasUpper = true;
        if (islower(c)) hasLower = true;
        if (isdigit(c)) hasNumber = true;
    }
    return hasUpper && hasLower && hasNumber;
}

// Task 3 (25 points)
// Create a class called 'BankAccount' with the following specifications:
class BankAccount
{
private:
    std::string accountHolder;
    double balance;

public:
    // Constructor to initialize account with holder name and initial balance
    // If initial balance is negative, set it to 0
    BankAccount(std::string holder, double initialBalance)
    {
        // Your code here
        accountHolder = holder;
        balance = (initialBalance < 0) ? 0 : initialBalance;
    }

    // Method to deposit money
    // Return true if deposit is positive, false otherwise
    bool deposit(double amount)
    {
        // Your code here
        if (amount > 0)
        {
            balance += amount;
            return true;
        }
        return false;
    }

    // Method to withdraw money
    // Return true if withdrawal is possible and balance would stay >= 0
    // Return false otherwise
    bool withdraw(double amount)
    {
        // Your code here
        if (amount > 0 && (balance - amount) >= 0)
        {
            balance -= amount;
            return true;
        }
        return false;
    }

    // Method to get current balance
    double getBalance()
    {
        // Your code here
        return balance;
    }

    // Method to get account holder name
    std::string getAccountHolder()
    {
        // Your code here
        return accountHolder;
    }
};

// Task 4 (30 points)
// Implement a function that takes a string and returns true if it's a palindrome
// Ignore spaces, punctuation, and letter case
// Example: "A man, a plan, a canal: Panama" → true
bool isPalindrome(std::string text)
{
    // Your code here
    std::string cleaned;
    for (char c : text)
        if (isalnum(c))
            cleaned += tolower(c);
    std::string reversed = cleaned;
    reverse(reversed.begin(), reversed.end());
    return cleaned == reversed;
}

// Test cases
int main()
{
    // Test Task 1: findSecondLargest
    std::cout << "\nTesting Task 1:\n";
    int arr1[] = {1, 5, 2, 9, 3};
    int arr2[] = {1};
    int arr3[] = {4, 4, 4, 4};

    assert(findSecondLargest(arr1, 5) == 5);
    assert(findSecondLargest(arr2, 1) == -1);
    assert(findSecondLargest(arr3, 4) == 4);
    std::cout << "Task 1 tests passed!\n";

    // Test Task 2: isValidPassword
    std::cout << "\nTesting Task 2:\n";
    assert(isValidPassword("Pass123word") == true);
    assert(isValidPassword("password") == false);  // No uppercase or number
    assert(isValidPassword("12345") == false);     // Too short
    assert(isValidPassword("UPPERCASE123") == false); // No lowercase
    std::cout << "Task 2 tests passed!\n";

    // Test Task 3: BankAccount
    std::cout << "\nTesting Task 3:\n";
    BankAccount account("John Doe", 1000);
    assert(account.getAccountHolder() == "John Doe");
    assert(account.getBalance() == 1000);
    assert(account.deposit(500) == true);
    assert(account.getBalance() == 1500);
    assert(account.deposit(-100) == false);
    assert(account.withdraw(2000) == false);
    assert(account.withdraw(500) == true);
    assert(account.getBalance() == 1000);

    BankAccount account2("Jane Doe", -100);  // Should set balance to 0
    assert(account2.getBalance() == 0);
    std::cout << "Task 3 tests passed!\n";

    // Test Task 4: isPalindrome
    std::cout << "\nTesting Task 4:\n";
    assert(isPalindrome("A man, a plan, a canal: Panama") == true);
    assert(isPalindrome("race a car") == false);
    assert(isPalindrome("Was it a car or a cat I saw?") == true);
    assert(isPalindrome("") == true);
    assert(isPalindrome("a") == true);
    std::cout << "Task 4 tests passed!\n";

    std::cout << "\nAll tests passed! Great job!\n";
    return 0;
}
