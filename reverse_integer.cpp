#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            // Check overflow
            if (rev > INT_MAX / 10 || rev < INT_MIN / 10) return 0;

            rev = rev * 10 + digit;
        }
        return rev;
    }
};
int main() {
    Solution solver;
    int num;
    cout << "Enter an integer: ";
    cin >> num;
    cout << "Reversed number: " << solver.reverse(num) << endl;
    return 0;
}