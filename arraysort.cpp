#include <iostream>
#include <vector>
using namespace std;

// Partition function
int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[high]; // choose last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (nums[j] <= pivot) {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[high]);
    return i + 1;
}

// QuickSort function
void quickSort(vector<int>& nums, int low, int high) {
    if (low < high) {
        int par = partition(nums, low, high);

        quickSort(nums, low, par - 1);  // sort left side
        quickSort(nums, par + 1, high); // sort right side
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    quickSort(nums, 0, n - 1);

    cout << "Sorted array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}