#include <iostream>
#include <vector>

using namespace std;
// Function to find the first occurrence of a target element
int findFirstPosition(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            right = mid - 1;  // Continue searching on the left side
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

// Function to find the last occurrence of a target element
int findLastPosition(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            left = mid + 1;  // Continue searching on the right side
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    vector<int> arr = {1, 2, 2, 2,2,3, 4, 4, 4, 5, 6};
    int target = 2;

    int firstPos = findFirstPosition(arr, target);
    int lastPos = findLastPosition(arr, target);

    if (firstPos != -1) {
        cout << "First occurrence of " << target << " is at index " << firstPos << endl;
        cout << "Last occurrence of " << target << " is at index " << lastPos << endl;
    } else {
        cout << target << " is not found in the array." << endl;
    }

    return 0;
}

