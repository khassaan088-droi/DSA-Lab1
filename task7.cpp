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