void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    for (int i = 0; i < matrixSize / 2; i++) {
        int *tmp = matrix[i];
        matrix[i] = matrix[matrixSize - i - 1];
        matrix[matrixSize - i - 1] = tmp;
    }
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < i; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }
}