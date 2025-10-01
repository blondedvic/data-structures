#include <iostream>
using namespace std;

bool isPalindrome(int number) {
    if (number < 0) return false; // negative numbers are not palindromes

    const int original = number;
    int reversed = 0;

    while (number > 0) {
        int digit = number % 10;          // extract last digit
        reversed = reversed * 10 + digit; // append to reversed
        number /= 10;                     // remove last digit
    }

    return original == reversed;
}

int main() {
    int value;
    cout << "Enter an integer: ";
    cin >> value;

    if (isPalindrome(value))
        cout << value << " is a palindrome.\n";
    else
        cout << value << " is not a palindrome.\n";

    return 0;
}