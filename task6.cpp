
Task 6
#include <iostream>
using namespace std;
void findmode(int arr[], int size) {
    if (size <= 0) {
        cout << "Mode: None (Empty array)\n";
        return;
    }
    int maxCount = 0;
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
        }
    }
    cout << "Mode: ";
    for (int i = 0; i < size; i++) {
        bool alreadyPrinted = false;
        for (int k = 0; k < i; k++) {
            if (arr[i] == arr[k]) {
                alreadyPrinted = true;
                break;
            }
        }

        if (!alreadyPrinted) {
            int count = 0;
            for (int j = 0; j < size; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                }
            }
            if (count == maxCount) {
                cout << arr[i] << " ";
            }
        }
    }
    cout << endl;
}
int main() {
    int arr1[] = {1, 3, 3, 3, 2, 4};
    cout << "--- Test 1 ---\n";
    findmode(arr1, 6);
    int arr2[] = {1, 1, 2, 2, 3};
    cout << "\n--- Test 2 (Multiple Modes) ---\n";
    findmode(arr2, 5);
    int arr3[10] = {};
    cout << "\n--- Test 3 (Empty Array) ---\n";
    findmode(arr3, 0);

    return 0;
}
