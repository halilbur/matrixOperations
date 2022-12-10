/**
 * @file matrixLib.c
 * @description Includes the functions body of matrixLib.h
 * @assignment BP3 - PROJECT 1
 * @date 10/12/2022
 * @author HALIL BURAK OZTURK halilburak.ozturk@stu.fsm.edu.tr
 */
#include "matrixLib.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

//@desc This function returns a vector of given
float *returnVector(int size)
{
    // Allocate memory for the vector
    float *vector = (float *)malloc(size * sizeof(float));
    // Return vector
    return vector;
}
//@desc This function returns a matrix of size rows x cols
float **returnMatrix(int rows, int cols)
{
    // Allacote memory for the matrix
    float **matrix = (float **)malloc(rows * sizeof(float *));
    for (int i = 0; i < rows; i++)
    {
        // Allocate memory for each row of the matrix
        matrix[i] = (float *)malloc(cols * sizeof(*(matrix[i])));
    }
    // Return matrix
    return matrix;
}
//@desc This function freeing the memory given to the matrix
void freeMatrix(float **matrix, int rows)
{
    // Free the memory given to each row of the matrix
    for (int i = rows - 1; i >= 0; i--)
    {
        free(matrix[i]);
    }
    // Free the memory given to the matrix itself
    free(matrix);
}
//@desc This function calculate the mean of a vector
float mean(float *vector, int size)
{
    // Create a variable to store the sum of the elements of the vector
    float sum = 0;
    // Loop over the elements of the vector and add them to the sum
    for (int i = 0; i < size; i++)
    {
        sum += vector[i];
    }

    // Return the mean
    return sum / size;
}
//@desc This function calculating the multiplication of two matrices
float **matrixMultiplication(float **mat1, float **mat2, int row1, int col1, int row2, int col2)
{
    // Check if the number of columns of the first matrix is equal to the number of rows of the second matrix
    if (col1 == row2)
    {
        // Allocate memory for the result matrix
        float **matMulti = returnMatrix(row1, col2);
        // Loop over the rows of the first matrix
        for (int i = 0; i < row1; i++)
        {
            // Loop over the columns of the second matrix
            for (int j = 0; j < col2; j++)
            {
                // matMulti[i][j] = 0;
                for (int k = 0; k < col1; k++)
                {
                    // Calculate the multiplication of the two matrices
                    matMulti[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
        // Return the result matrix
        return matMulti;
    }
    else
        printf("The number of columns of the first matrix is not equal to the number of rows of the second matrix");
    exit(1);
    return NULL;
}
//@desc This function printing the vector
void printVector(float *vec, int size)
{
    // Loop over the elements of the vector
    for (int i = 0; i < size; i++)
    {
        // Print the vector of each element
        printf("vec[%d] = %f \n", i, vec[i]);
    }
}
//@desc This function printing the matrix
void printMatrix(float **mat, int rows, int cols)
{
    // Loop over the elements of the matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // Print the matrix of each element
            printf("mat[%d][%d] = %f \t", i, j, mat[i][j]);
        }
        printf("\n");
    }
}
//@desc This function calculating the transpose of a matrix
float **matrixTranspose(float **mat, int row, int col)
{
    // Allocate memory for the transpose matrix
    float **matTranspose = returnMatrix(col, row);
    // Loop over the elements of the matrix
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // Calculate the transpose of the matrix
            matTranspose[j][i] = mat[i][j];
        }
    }
    // Return the transpose matrix
    return matTranspose;
}
//@desc This function filling the matrix with random numbers
float **fillMatrix(float **mat, int rows, int cols, int seed)
{
    // Set the seed with given parameter for the random numbers
    srand(seed);
    // Loop over the elements of the matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // Fill the matrix with random numbers
            mat[i][j] = rand() % 20;
        }
    }
    // Return the matrix
    return mat;
}
//@desc This function filling the vector with random numbers
float *fillVector(float *vec, int size, int seed)
{
    // Set the seed with given parameter for the random numbers
    srand(seed);
    // Loop over the elements of the vector
    for (int i = 0; i < size; i++)
    {
        // Fill the vector with random numbers
        vec[i] = rand() % 20;
    }
    // Return the vector
    return vec;
}
//@desc This function calculating the mean of each row of the matrix
float *rowMeans(float **mat, int row, int col)
{
    // Allocate memory for the vector
    float *rowMeans = returnVector(row);

    // Calculate the mean of each row
    for (int i = 0; i < row; i++)
    {
        rowMeans[i] = mean(mat[i], col);
    }
    // Return the vector
    return rowMeans;
}
//@desc This function calculating the mean of each column of the matrix
float *columnMeans(float **mat, int row, int col)
{
    // Allocate memory for the vector
    float *colMeans = returnVector(col);

    // Loop over the columns of the matrix
    for (int i = 0; i < col; i++)
    {
        // Create a vector to store the elements of the column
        float *col = returnVector(row);
        // Loop over the elements of the column
        for (int j = 0; j < row; j++)
        {
            // Store the elements of the column in the vector
            col[j] = mat[j][i];
        }
        // Calculate the mean of the column
        colMeans[i] = mean(col, row);
        // Free the memory of the vector
        free(col);
    }

    // Return the vector
    return colMeans;
}
//@desc This function calculating the covariance of two vectors
float covariance(float *vec1, float *vec2, int size1, int size2)
{
    if (size1 == size2 && size1 != 0 && size2 != 0 && vec1 != NULL && vec2 != NULL)
    {
        // Calculate the mean of each vector
        float meanVec1 = mean(vec1, size1);
        float meanVec2 = mean(vec2, size1);

        // Define a variable of type float to store the sum
        float sum = 0;

        // Calculate the covariance
        for (int i = 0; i < size1; i++)
        {
            // Calculate the sum of the multiplication of the difference of each element of the vectors and the mean of each vector
            sum += ((vec1[i] - meanVec1) * (vec2[i] - meanVec2));
        }
        // Return the covariance
        return sum / (size1 - 1);
    }
    else
        printf("The vectors are empty or have different size");
    exit(1);
    return 1;
}
//@desc This function calculating the correlation of two vectors
float correlation(float *vec, float *vec2, int size1, int size2)
{
    // int vecSize = sizeof(vec) / sizeof(vec[0]);
    // int vec1Size = sizeof(vec2) / sizeof(vec2[0]);
    //  Check if the vectors are not empty and have the same size
    if (size1 != 0 && size2 != 0 && vec != NULL && vec2 != NULL && size1 == size2)
    {
        // Calculate the covariance
        float cov = covariance(vec, vec2, size1, size2);

        // Calculate the standard deviation of each vector
        float stdVec1 = sqrt(covariance(vec, vec, size1, size2));
        float stdVec2 = sqrt(covariance(vec2, vec2, size1, size2));

        // Return the correlation
        return cov / (stdVec1 * stdVec2);
    }
    else
        printf("The vectors are empty or have different size! \n");
    exit(1);
    return 1;
}
//@desc This function calculating the covariance matrix of a matrix
float **covarianceMatrix(float **mat, int row, int col)
{
    if (mat != NULL && row != 0 && col != 0 && row == col)
    {
        // Allocate memory for the covariance matrix
        float **covMat = returnMatrix(row, col);
        // Calculate and store the mean of each column of the given matrix
        float *colMeans = columnMeans(mat, row, col);
        // Allocate memory for the transpose matrix
        float **covMatT = returnMatrix(col, col);
        // Allocate memory for the Multiplication opeartion
        float **covMatMultiply = returnMatrix(col, col);
        // Loop over the elements of the matrix
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                // Calculate the Xc matrix
                covMat[j][i] = mat[j][i] - colMeans[i];
            }
        }
        // Calculate the transpose of the Xc matrix
        covMatT = matrixTranspose(covMat, row, col);
        // Calculate the multiplication of the Xc matrix and the transpose of the Xc matrix
        covMatMultiply = (matrixMultiplication(covMat, covMatT, row, col, col, col));
        // Return the covariance matrix
        freeMatrix(covMat, row);
        freeMatrix(covMatT, col);
        free(colMeans);
        return matrixMultiplicationWithNumber(covMatMultiply, col, col, 1.0 / (row));
    }
    else
        printf("The matrix is empty or row and col not equal!\n");
    exit(1);
    return NULL;
}
//@desc This function calculating the matrix multiplication with numbers
float **matrixMultiplicationWithNumber(float **mat, int row, int col, float number)
{
    // Allocate memory for the matrix
    float **matMult = returnMatrix(row, col);

    // Multiply the matrix with the number
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // Store the result in the matrix
            matMult[i][j] = mat[i][j] * number;
        }
    }

    // Return the matrix
    return matMult;
}
//@desc This function calculating the matrix determinant with sarrus rule
float determinant(float **mat, int row)
{
    if (mat != NULL && row != 0 && row == 3)
    {
        // Resizing the matrix for the determinant calculation
        for (int i = 0; i < row; i++)
        {
            mat[i] = realloc(mat[i], 5 * sizeof(float));
        }
        // Putting the first two columns of the matrix in the last two columns
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < row; j++)
            {
                mat[j][i + 3] = mat[j][i];
            }
        }
        // Printing the matrix
        printMatrix(mat, row, row + 2);

        // Define two variables of type float to store the sum of the multiplication of the elements of the matrix
        float upSum = 0;
        float downSum = 0;
        // Loop over the elements of the matrix
        for (int j = 0; j < row; j++)
        {
            int i = 0;
            // Calculating determinat of matrix with sarrus rule
            upSum += mat[i][j] * mat[i + 1][j + 1] * mat[i + 2][j + 2];
            downSum += mat[i + 2][j] * mat[i + 1][j + 1] * mat[i][j + 2];
        }
        // Printing the upSum and downSum
        printf("upSum = %f \n", upSum);
        printf("downSum = %f \n", downSum);
        // Return the determinant
        return (upSum - downSum);
    }
    else
        printf("The matrix is empty or row not equal 3!\n");
    exit(1);
    return 1;
}
