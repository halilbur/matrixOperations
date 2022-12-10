/**
* @file main.c
* @description matrixLib.h library
* @assignment BP3 - PROJECT 1
* @date 10/12/2022
* @author HALIL BURAK OZTURK halilburak.ozturk@stu.fsm.edu.tr
*/

//Returning the matrix and vector
float *returnVector(int size);
float **returnMatrix(int rows, int cols);
//Freeing the matrix
void freeMatrix(float **matrix, int rows);
//Calculating the mean of vector
float mean(float *vector, int size);
//Calculating the correlation of two vectors
float correlation(float *vec, float *vec2, int size1, int size2);
//Calculating the covariance of two vectors
float covariance(float *vec1, float *vec2, int size1, int size2);
//Calculating the multiplication of two matrices
float **matrixMultiplication(float **mat1, float **mat2, int row1, int col1, int row2, int col2);
//Calculating the transpose of a matrix
float **matrixTranspose(float **mat, int row, int col);
//Calculating the mean of each row
float *rowMeans(float **mat, int row, int col);
//Calculating the mean of each column
float *columnMeans(float **mat, int row, int col);
//Calculating the covariance matrix
float **covarianceMatrix(float **mat, int row, int col);
//Calculating the determinant of a matrix
float determinant(float **mat, int row);

//Printing the matrix and vector
void printVector(float *vec, int size);
void printMatrix(float **mat, int rows, int cols);

//Filling the matrix and vector with random numbers
float **fillMatrix(float **mat, int rows, int cols, int seed);
float *fillVector(float *vec, int size, int seed);

//Calculating the multiplication of a matrix with a number
float **matrixMultiplicationWithNumber(float **mat, int row, int col, float number);
