//Task 4
// #include <iostream>
// using namespace std;
// void findAllIndices(int arr[], int size, int key, int resultIndices[], int& resultCount) {
//     resultCount = 0; 
    
//     for (int i = 0; i < size; i++) {
//         if (arr[i] == key) {
//             resultIndices[resultCount] = i; 
//             resultCount++;
//         }
//     }
// }
// int main() {
//     int resultIndices[100]; 
//     int resultCount = 0;
//     int arr1[] = {10, 20, 30, 20, 40, 20};
//     findAllIndices(arr1, 6, 20, resultIndices, resultCount);
    
//     cout << "Test 1 (Multiple occurrences): ";
//     if (resultCount == 0) {
//         cout << "None";
//     } else {
//         for (int i = 0; i < resultCount; i++) {
//             cout << resultIndices[i] << " ";
//         }
//     }
//     cout << endl;
//     int arr2[] = {5, 10, 15, 20};
//     findAllIndices(arr2, 4, 99, resultIndices, resultCount);
    
//     cout << "Test 2 (Key not present): ";
//     if (resultCount == 0) {
//         cout << "None";
//     } else {
//         for (int i = 0; i < resultCount; i++) {
//             cout << resultIndices[i] << " ";
//         }
//     }
//     cout << endl;
//     int arr3[10] = {};
//     findAllIndices(arr3, 0, 10, resultIndices, resultCount);
    
//     cout << "Test 3 (Empty array): ";
//     if (resultCount == 0) {
//         cout << "None";
//     } else {
//         for (int i = 0; i < resultCount; i++) {
//             cout << resultIndices[i] << " ";
//         }
//     }
//     cout << endl;

//     return 0;
// }   
//Lab 5
// #include <iostream>
// using namespace std;
// void printPascalsTriangle(int n) {
//     if (n <= 0) {
//         cout << "Empty triangle\n";
//         return;
//     }
//     int triangle[20][20]; 

//     for (int i = 0; i < n; i++) {
        
//         triangle[i][0] = 1;
//         triangle[i][i] = 1;
//         for (int j = 1; j < i; j++) {
//             triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
//         }

       
//         cout << "Row " << i + 1 << ": ";
//         for (int j = 0; j <= i; j++) {
//             cout << triangle[i][j] << " ";
//         }
//         cout << endl;
//     }
// }
// int main() {
//     cout << " Test 1: n = 0 ---\n";
//     printPascalsTriangle(0);
//     cout << "Test 2: n = 1 ---\n";
//     printPascalsTriangle(1);
//     cout << " Test 3: n = 5 ---\n";
//     printPascalsTriangle(5);

//     return 0;
// }

//Task 6
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