// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function to display a matrix
void displayMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// PART A: Transpose a matrix
void transposeMatrix(int matrix[10][10], int rows, int cols)
{
    int transpose[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "Transposed Matrix:" << endl;
    displayMatrix(transpose, cols, rows);
}

// PART B: Add two matrices
void addMatrices(int matrixA[10][10], int matrixB[10][10],
                 int rows, int cols)
{
    int sum[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    cout << "Sum of Matrices:" << endl;
    displayMatrix(sum, rows, cols);
}

// PART C: Multiply two matrices
void multiplyMatrices(int matrixA[10][10], int matrixB[10][10],
                      int rowsA, int colsA, int colsB)
{
    int product[10][10];

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            product[i][j] = 0;

            for (int k = 0; k < colsA; k++)
            {
                product[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    cout << "Product of Matrices:" << endl;
    displayMatrix(product, rowsA, colsB);
}

int main()
{
    // ============================================================
    // PART A: TRANSPOSE
    // ============================================================

    int matrix[10][10];
    int rows, cols;

    cout << "PART A - Matrix Transpose" << endl;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    if (rows <= 0 || rows > 10 || cols <= 0 || cols > 10)
    {
        cout << "Error: Matrix size must be between 1 and 10." << endl;
        return 0;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    cout << endl;
    cout << "Original Matrix:" << endl;
    displayMatrix(matrix, rows, cols);

    cout << endl;
    transposeMatrix(matrix, rows, cols);

    // ============================================================
    // PART B: ADD TWO MATRICES
    // ============================================================

    int matrixA[10][10];
    int matrixB[10][10];

    int rowsB, colsB;

    cout << endl;
    cout << "PART B - Matrix Addition" << endl;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    if (rows <= 0 || rows > 10 || cols <= 0 || cols > 10)
    {
        cout << "Error: Matrix size must be between 1 and 10." << endl;
        return 0;
    }

    cout << endl;
    cout << "Enter elements of Matrix A:" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrixA[i][j];
        }
    }

    cout << endl;
    cout << "Enter elements of Matrix B:" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrixB[i][j];
        }
    }

    cout << endl;
    addMatrices(matrixA, matrixB, rows, cols);

    // ============================================================
    // PART C: MATRIX MULTIPLICATION
    // ============================================================

    int matrixC[10][10];
    int matrixD[10][10];

    int rowsC, colsC, rowsD, colsD;

    cout << endl;
    cout << "PART C - Matrix Multiplication" << endl;

    cout << "Enter rows for Matrix A: ";
    cin >> rowsC;

    cout << "Enter columns for Matrix A: ";
    cin >> colsC;

    cout << "Enter rows for Matrix B: ";
    cin >> rowsD;

    cout << "Enter columns for Matrix B: ";
    cin >> colsD;

    if (rowsC <= 0 || rowsC > 10 ||
        colsC <= 0 || colsC > 10 ||
        rowsD <= 0 || rowsD > 10 ||
        colsD <= 0 || colsD > 10)
    {
        cout << "Error: Matrix size must be between 1 and 10." << endl;
        return 0;
    }

    // Check multiplication condition
    if (colsC != rowsD)
    {
        cout << "Error: Number of columns in Matrix A must equal "
             << "number of rows in Matrix B." << endl;
        return 0;
    }

    cout << endl;
    cout << "Enter elements of Matrix A:" << endl;

    for (int i = 0; i < rowsC; i++)
    {
        for (int j = 0; j < colsC; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrixC[i][j];
        }
    }

    cout << endl;
    cout << "Enter elements of Matrix B:" << endl;

    for (int i = 0; i < rowsD; i++)
    {
        for (int j = 0; j < colsD; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrixD[i][j];
        }
    }

    cout << endl;
    multiplyMatrices(matrixC, matrixD, rowsC, colsC, colsD);

    return 0;
}
