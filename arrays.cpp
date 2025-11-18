#include <iostream>

using namespace std;

const int N = 3;
const int M = 3;

bool isArraySymetrical(int array[3][3]);
void outputLongestSequenceOfElements(int array[3][3]);
void rotateMatrix(int array[3][3]);
bool isMatrixAMagicalSquare(double matrix[N][N]);
void outputMatrixSpirally(double matrix[N][N]);
void sortMaxSumRowInMatrix(double matrix[N][M]);
void findSaddlePoints(double matrix[N][M]);

int main() {
    double array[N][M] = {};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> array[i][j];
        }
    }

    // isArraySymetrical(array);
    // outputLongestSequenceOfElements(array);
    // rotateMatrix(array);
    // bool isMagical = isMatrixAMagicalSquare(array);
    // if (isMagical) {
    //     cout << "Matrix is Magical" << endl;
    // } else {
    //     cout << "Matrix is not Magical" << endl;
    // }
    // outputMatrixSpirally(array);
    // sortMaxSumRowInMatrix(array);

    findSaddlePoints(array);
}

bool isArraySymetrical(int array[3][3]) {
    bool isSymetrical = true;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (array[i][j] != array[j][i]) {
                isSymetrical = false;
                break;
            }
        }
    }

    if (!isSymetrical) {
        cout << "The matrix is not symerical" << endl;
    } else {
        cout << "The matrix is symerical" << endl;
    }

    return isSymetrical;
}

void outputLongestSequenceOfElements(int array[3][3]) {
    int longestElementRow = -1;
    int longestElementCounter = -1;
    int longestElement;

    int longestElementStartIndexI = 0;
    int longestElementStartIndexJ = 0;
    int longestElementEndIndexI = -1;
    int longestElementEndIndexJ = -1;

    int currentElementCounter = 0;
    int currentElement = array[0][0];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (currentElement == array[i][j]) {
                // if (i != 0 || j != 0)
                if (currentElementCounter == 0) {
                    if (j == 0 && i != 0) {
                        longestElementStartIndexI = i - 1;
                        longestElementStartIndexJ = 3;
                    } else {
                        if (j != 0) {
                            longestElementStartIndexI = i;
                            longestElementStartIndexJ = j - 1;
                        }
                    }
                }

                currentElementCounter++;

                if (i == 2 && j == 2) {
                    if (currentElementCounter > longestElementCounter) {
                        longestElementCounter = currentElementCounter;
                        longestElementRow = i;
                        longestElement = array[i][j];
                        longestElementEndIndexI = i;
                        longestElementEndIndexJ = j;
                    }
                    currentElementCounter = 0;
                }
            } else {
                if (currentElementCounter > longestElementCounter) {
                    longestElementCounter = currentElementCounter;
                    longestElementRow = i;
                    longestElement = array[i][j];
                    longestElementEndIndexI = i;
                    longestElementEndIndexJ = j;
                }
                currentElementCounter = 0;
            }

            currentElement = array[i][j];
        }
    }

    cout << "Longest Element row is: " << longestElementRow << endl;
    cout << "Longest Element sequence length is: " << longestElementCounter << endl;
    cout << "The longest element sequence in array form is: " << endl;

    for (int i = longestElementStartIndexI; i < longestElementEndIndexI; i++) {
        for (int j = longestElementStartIndexJ; j < longestElementEndIndexI; j++) {
            cout << array[i][j] << " ";
        }
    }

    cout << "End of element sequence" << endl;

    cout << "longestElementStartIndexI: " << longestElementStartIndexI << endl;
    cout << "longestElementStartIndexJ: " << longestElementStartIndexJ << endl;
    cout << "longestElementEndIndexI: " << longestElementEndIndexI << endl;
    cout << "longestElementEndIndexJ: " << longestElementEndIndexJ << endl;
}

void rotateMatrix(int array[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 2; j >= 0; j--) {
            cout << array[j][i] << " ";
        }
        cout << endl;
    }
}

bool isMatrixAMagicalSquare(double matrix[N][N]) {
    bool isMagicSquare = true;

    double sum = 0;
    for (int i = 0; i < N; i++) {
        sum += matrix[0][i];
    }

    for (int i = 1; i < N; i++) {
        double rowSum = 0;
        for (int j = 0; j < N; j++) {
            rowSum += matrix[i][j];
        }
        if (rowSum != sum) {
            isMagicSquare = false;
        }
    }

    for (int i = 0; i < N; i++) {
        double columnSum = 0;
        for (int j = 0; j < N; j++) {
            columnSum += matrix[j][i];
        }
        if (columnSum != sum) {
            isMagicSquare = false;
        }
    }

    // main diagonal
    double diagonalSum = 0;
    for (int i = 0; i < N; i++) {
        diagonalSum += matrix[i][i];
    }
    if (diagonalSum != sum) {
        isMagicSquare = false;
    }

    // secondary diagonal
    diagonalSum = 0;
    for (int i = 0; i < N; i++) {
        diagonalSum += matrix[N - i - 1][i];
    }

    return isMagicSquare;
}

void outputMatrixSpirally(double matrix[N][N]) {
    int top = 0;
    int bottom = N - 1;
    int left = 0;
    int right = N - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            cout << matrix[top][i] << " ";
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            cout << matrix[i][right] << " ";
        }
        right--;

        for (int i = right; i >= left; i--) {
            cout << matrix[bottom][i] << " ";
        }
        bottom--;

        for (int i = bottom; i >= top; i--) {
            cout << matrix[i][left] << " ";
        }
        left++;
    }
}

void sortMaxSumRowInMatrix(double matrix[N][M]) {
    double maxSum = 0;
    int maxRowIndex = 0;

    // Find hightest sum row
    for (int i = 0; i < N; i++) {
        double rowSum = 0;
        for (int j = 0; j < M; j++) {
            rowSum += matrix[i][j];
        }
        if (rowSum > maxSum) {
            maxSum = rowSum;
            maxRowIndex = i;
        }
    }

    double array[M];
    for (int i = 0; i < M; i++) {
        array[i] = matrix[maxRowIndex][i];
    }

    // Sort the row in the matrix with Bubble sort
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M - 1; j++) {
            if (array[j] > array[j + 1]) {
                double temporary = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temporary;
            }
        }
    }

    // Write the sorted values back to the matrix row
    for (int i = 0; i < M; i++) {
        matrix[maxRowIndex][i] = array[i];
    }

    // Output matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void findSaddlePoints(double matrix[N][M]) {
    double minElementInRow[N];
    double maxElementInColumn[M];

    // Initialize per-row minima and per-column maxima
    for (int i = 0; i < N; i++) {
        minElementInRow[i] = matrix[i][0];
    }

    for (int i = 0; i < M; i++) {
        maxElementInColumn[i] = matrix[0][i];
    }

    // Compute per-row minima and per-column maxima
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] < minElementInRow[i]) {
                minElementInRow[i] = matrix[i][j];
            }
            if (matrix[i][j] > maxElementInColumn[j]) {
                maxElementInColumn[j] = matrix[i][j];
            }
        }
    }

    // Output saddle points (min in row and max in column)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] == minElementInRow[i] && matrix[i][j] == maxElementInColumn[j]) {
                cout << matrix[i][j] << " ";
            }
        }
    }
}