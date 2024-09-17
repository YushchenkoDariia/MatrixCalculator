#include <iostream>
#include <vector>
using namespace std;

// Function to input a matrix
vector<vector<int>> inputMatrix(int rows, int cols) {
    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter the elements of the matrix (" << rows << "x" << cols << "): \n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

// Function to display a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    cout << "Matrix:\n";
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Adding two matrices
vector<vector<int>> addMatrices(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    int rows = mat1.size();
    int cols = mat1[0].size();
    vector<vector<int>> result(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return result;
}

// Subtracting two matrices
vector<vector<int>> subtractMatrices(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    int rows = mat1.size();
    int cols = mat1[0].size();
    vector<vector<int>> result(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    return result;
}

// Multiplying two matrices
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    int rows1 = mat1.size();
    int cols1 = mat1[0].size();
    int rows2 = mat2.size();
    int cols2 = mat2[0].size();

    if (cols1 != rows2) {
        cout << "Matrix multiplication is not possible.\n";
        exit(1);
    }

    vector<vector<int>> result(rows1, vector<int>(cols2, 0));
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;
}

// Transposing a matrix
vector<vector<int>> transposeMatrix(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> result(cols, vector<int>(rows));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}

// Main function
int main() {
    int choice, rows, cols;

    cout << "Matrix Calculator\n";
    cout << "1. Add two matrices\n";
    cout << "2. Subtract two matrices\n";
    cout << "3. Multiply two matrices\n";
    cout << "4. Transpose a matrix\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        // Addition of two matrices
        cout << "Enter the number of rows and columns: ";
        cin >> rows >> cols;
        cout << "Enter the first matrix:\n";
        vector<vector<int>> mat1 = inputMatrix(rows, cols);
        cout << "Enter the second matrix:\n";
        vector<vector<int>> mat2 = inputMatrix(rows, cols);
        vector<vector<int>> result = addMatrices(mat1, mat2);
        cout << "Result of matrix addition:\n";
        printMatrix(result);
        break;
    }
    case 2: {
        // Subtraction of two matrices
        cout << "Enter the number of rows and columns: ";
        cin >> rows >> cols;
        cout << "Enter the first matrix:\n";
        vector<vector<int>> mat1 = inputMatrix(rows, cols);
        cout << "Enter the second matrix:\n";
        vector<vector<int>> mat2 = inputMatrix(rows, cols);
        vector<vector<int>> result = subtractMatrices(mat1, mat2);
        cout << "Result of matrix subtraction:\n";
        printMatrix(result);
        break;
    }
    case 3: {
        // Multiplication of two matrices
        int rows1, cols1, rows2, cols2;
        cout << "Enter the number of rows and columns for the first matrix: ";
        cin >> rows1 >> cols1;
        cout << "Enter the first matrix:\n";
        vector<vector<int>> mat1 = inputMatrix(rows1, cols1);
        cout << "Enter the number of rows and columns for the second matrix: ";
        cin >> rows2 >> cols2;
        cout << "Enter the second matrix:\n";
        vector<vector<int>> mat2 = inputMatrix(rows2, cols2);
        vector<vector<int>> result = multiplyMatrices(mat1, mat2);
        cout << "Result of matrix multiplication:\n";
        printMatrix(result);
        break;
    }
    case 4: {
        // Transpose of a matrix
        cout << "Enter the number of rows and columns: ";
        cin >> rows >> cols;
        cout << "Enter the matrix:\n";
        vector<vector<int>> matrix = inputMatrix(rows, cols);
        vector<vector<int>> result = transposeMatrix(matrix);
        cout << "Transposed matrix:\n";
        printMatrix(result);
        break;
    }
    default:
        cout << "Invalid choice.\n";
        break;
    }

    return 0;
}
