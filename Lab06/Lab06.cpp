#include <iostream>
#include <fstream>
#include <iomanip>

const int MAX_SIZE = 100;

using namespace std;

// Function prototypes
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int& size, const char* filename);
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size);
void addMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void multiplyMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void subtractMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);

int main() {
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int size;

    // Read matrices from the file
    readMatrix(matrixA, size, "matrix_input.txt");
    readMatrix(matrixB, size, "matrix_input.txt");

    // Display matrices
    cout << "Lab #6: Matrix manipulation\n\n";

    cout << "Matrix A:\n";
    printMatrix(matrixA, size);

    cout << "\nMatrix B:\n";
    printMatrix(matrixB, size);

    // Add matrices and display the result
    addMatrices(matrixA, matrixB, result, size);
    cout << "\nMatrix Sum (A + B):\n";
    printMatrix(result, size);

    // Multiply matrices and display the result
    multiplyMatrices(matrixA, matrixB, result, size);
    cout << "\nMatrix Product (A * B):\n";
    printMatrix(result, size);

    // Subtract matrices and display the result
    subtractMatrices(matrixA, matrixB, result, size);
    cout << "\nMatrix Difference (A - B):\n";
    printMatrix(result, size);

    return 0;
}

// Function to read matrix data from a file and store it in a 2D array
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int& size, const char* filename) {
    ifstream file(filename);
    if (file.is_open()) {
        file >> size;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                file >> matrix[i][j];
            }
        }
        file.close();
    } else {
        cerr << "Error: Unable to open file " << filename << endl;
        exit(1);
    }
}

// Function to display a matrix in a user-friendly format
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to add two matrices and store the result in a third matrix
void addMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Function for matrix multiplication
void multiplyMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

// Function to subtract one matrix from another and store the result in a third matrix
void subtractMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}
