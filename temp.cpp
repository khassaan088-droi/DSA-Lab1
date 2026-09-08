//Task 3
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

//Task 4

// #include <iostream>
// using namespace std;

// int naiveSearch(const char text[], const char pattern[]) {
//     if (pattern[0] == '\0') return 0;
//     for (int i = 0; text[i] != '\0'; i++) {
//         int j = 0;
//         while (text[i + j] == pattern[j] && pattern[j] != '\0') {
//             j++;
//         }
//         if (pattern[j] == '\0') return i;
//     }

//     return -1; 
// }

// int main() {
//     cout << "Test 1 (Beginning): " << naiveSearch("hello world", "hello") << endl;
//     cout << "Test 2 (End): " << naiveSearch("hello world", "world") << endl;       
//     cout << "Test 3 (Not Present): " << naiveSearch("hello world", "cpp") << endl; 
//     cout << "Test 4 (Empty Pattern): " << naiveSearch("hello world", "") << endl;  

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
// #include <iostream>
// using namespace std;
// void findmode(int arr[], int size) {
//     if (size <= 0) {
//         cout << "Mode: None (Empty array)\n";
//         return;
//     }
//     int maxCount = 0;
//     for (int i = 0; i < size; i++) {
//         int count = 0;
//         for (int j = 0; j < size; j++) {
//             if (arr[i] == arr[j]) {
//                 count++;
//             }
//         }
//         if (count > maxCount) {
//             maxCount = count;
//         }
//     }
//     cout << "Mode: ";
//     for (int i = 0; i < size; i++) {
//         bool alreadyPrinted = false;
//         for (int k = 0; k < i; k++) {
//             if (arr[i] == arr[k]) {
//                 alreadyPrinted = true;
//                 break;
//             }
//         }

//         if (!alreadyPrinted) {
//             int count = 0;
//             for (int j = 0; j < size; j++) {
//                 if (arr[i] == arr[j]) {
//                     count++;
//                 }
//             }
//             if (count == maxCount) {
//                 cout << arr[i] << " ";
//             }
//         }
//     }
//     cout << endl;
// }
// int main() {
//     int arr1[] = {1, 3, 3, 3, 2, 4};
//     cout << "--- Test 1 ---\n";
//     findmode(arr1, 6);
//     int arr2[] = {1, 1, 2, 2, 3};
//     cout << "\n--- Test 2 (Multiple Modes) ---\n";
//     findmode(arr2, 5);
//     int arr3[10] = {};
//     cout << "\n--- Test 3 (Empty Array) ---\n";
//     findmode(arr3, 0);

//     return 0;
// }

//Task 7
#include <iostream>
using namespace std;

// Standard Naive Matrix Multiplication
void standardmultiply(int A[4][4], int B[4][4], int C[4][4], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = 0;
            for (int k = 0; k < size; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Strassen's Algorithm for 2x2 matrices
void strassen2x2(int A[4][4], int B[4][4], int C[4][4], int rA, int cA, int rB, int cB, int rC, int cC) {
    int M1 = (A[rA][cA] + A[rA+1][cA+1]) * (B[rB][cB] + B[rB+1][cB+1]);
    int M2 = (A[rA+1][cA] + A[rA+1][cA+1]) * B[rB][cB];
    int M3 = A[rA][cA] * (B[rB][cB+1] - B[rB+1][cB+1]);
    int M4 = A[rA+1][cA+1] * (B[rB+1][cB] - B[rB][cB]);
    int M5 = (A[rA][cA] + A[rA][cA+1]) * B[rB+1][cB+1];
    int M6 = (A[rA+1][cA] - A[rA][cA]) * (B[rB][cB] + B[rB][cB+1]);
    int M7 = (A[rA][cA+1] - A[rA+1][cA+1]) * (B[rB+1][cB] + B[rB+1][cB+1]);

    C[rC][cC]     = M1 + M4 - M5 + M7;
    C[rC][cC+1]   = M3 + M5;
    C[rC+1][cC]   = M2 + M4;
    C[rC+1][cC+1] = M1 - M2 + M3 + M6;
}


void strassen4x4(int a[4][4], int b[4][4], int c[4][4]) {
    int t[4][4] = {0}, tt[4][4] = {0};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            c[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
void printmatrix(int m[4][4], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    //T1
    int aa[4][4] = {{1, 2}, {3, 4}};
    int bb[4][4] = {{5, 6}, {7, 8}};
    int Strassen[4][4] = {0};
    
    strassen2x2(aa, bb,Strassen, 0, 0, 0, 0, 0, 0);

    cout << "---Test 1---";
    printmatrix(Strassen, 2);

//T2
    int A4[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 1, 2, 3},
        {4, 5, 6, 7}
    };
    int B4[4][4] = {
        {8, 7, 6, 5},
        {4, 3, 2, 1},
        {1, 2, 3, 4},
        {5, 6, 7, 8}
    };
    int C4_Standard[4][4] = {0};
    int C4_Strassen[4][4] = {0};

    standardmultiply(A4, B4, C4_Standard, 4);
    strassen4x4(A4, B4, C4_Strassen);

    cout << "---Test 2---\n";
    printmatrix(C4_Standard, 4);

    cout << "\n--- test 3 ---\n";
    printmatrix(C4_Strassen, 4);

    return 0;
}