/**
 * @file main.c
 * @description Testing the matrixLib.h library
 * @assignment BP3 - PROJECT 1
 * @date 10/12/2022
 * @author HALIL BURAK OZTURK halilburak.ozturk@stu.fsm.edu.tr
 */
#include <stdio.h>
#include <stdlib.h>
#include "matrixLib.h"

int main(int argc, char *argv[])
{
    // Take the seed from the command line
    int seed = argv[1] ? atoi(argv[1]) : 0;

    // Test the functions
    printf("----------returnVector------------\n");
    float *vector = returnVector(5);
    printVector(vector, 5);
    free(vector);
    printf("----------------------------------\n");

    printf("----------returnMatrix------------\n");
    float **matrix = returnMatrix(2, 2);
    printMatrix(matrix, 2, 2);
    freeMatrix(matrix, 2);
    printf("----------------------------------\n");

    printf("----------freeMatrix--------------\n");
    float **matrix1 = returnMatrix(2, 2);
    matrix1 = fillMatrix(matrix1, 2, 2, seed);
    printMatrix(matrix1, 2, 2);
    freeMatrix(matrix1, 2);
    // printMatrix(matrix1, 3,3);
    printf("----------------------------------\n");

    printf("----------mean--------------------\n");
    float *vector1 = returnVector(5);
    vector1 = fillVector(vector1, 5, seed);
    printVector(vector1, 5);
    printf("mean = %f \n", mean(vector1, 5));
    free(vector1);
    printf("----------------------------------\n");

    printf("----------correlation-------------\n");
    float *vector2 = returnVector(5);
    float *vector3 = returnVector(5);
    vector2 = fillVector(vector2, 5, seed);
    vector3 = fillVector(vector3, 5, seed * 2);
    printVector(vector2, 5);
    printf("*****************************\n");
    printVector(vector3, 5);
    printf("correlation = %f \n", correlation(vector2, vector3, 5, 5));
    free(vector2);
    free(vector3);
    printf("----------------------------------\n");

    printf("----------covariance--------------\n");
    float *vector4 = returnVector(5);
    float *vector5 = returnVector(5);
    vector4 = fillVector(vector4, 5, seed * 4);
    vector5 = fillVector(vector5, 5, seed * 6);
    printVector(vector4, 5);
    printf("*****************************\n");
    printVector(vector5, 5);
    printf("covariance = %f \n", covariance(vector4, vector5, 5, 5));
    free(vector4);
    free(vector5);
    printf("----------------------------------\n");

    printf("----------matrixMultiplication----\n");
    float **matrix2 = returnMatrix(2, 2);
    float **matrix3 = returnMatrix(2, 2);
    matrix2 = fillMatrix(matrix2, 2, 2, seed * 8);
    matrix3 = fillMatrix(matrix3, 2, 2, seed * 10);
    printf("matrix1: \n");
    printMatrix(matrix2, 2, 2);
    printf("*****************************\n");
    printf("matrix2\n");
    printMatrix(matrix3, 2, 2);
    printf("*****************************\n");
    float **matrix4 = matrixMultiplication(matrix2, matrix3, 2, 2, 2, 2);
    printf("Result of Matrix Multiplication: \n");
    printMatrix(matrix4, 2, 2);
    freeMatrix(matrix2, 2);
    freeMatrix(matrix3, 2);
    freeMatrix(matrix4, 2);
    printf("----------------------------------\n");

    printf("----------matrixTranspose---------\n");
    float **matrix5 = returnMatrix(2, 3);
    matrix5 = fillMatrix(matrix5, 2, 3, seed * 12);
    printf("matrix1: \n");
    printMatrix(matrix5, 2, 3);
    printf("*****************************\n");
    float **matrix6 = matrixTranspose(matrix5, 2, 3);
    printf("Result of Matrix Transpose: \n");
    printMatrix(matrix6, 3, 2);
    freeMatrix(matrix5, 2);
    freeMatrix(matrix6, 3);
    printf("----------------------------------\n");

    printf("----------rowMeans----------------\n");
    float **matrix7 = returnMatrix(2, 3);
    matrix7 = fillMatrix(matrix7, 2, 3, seed * 14);
    printf("matrix1: \n");
    printMatrix(matrix7, 2, 3);
    printf("*****************************\n");
    float *vector6 = rowMeans(matrix7, 2, 3);
    printf("Result of Row Means: \n");
    printVector(vector6, 2);
    freeMatrix(matrix7, 2);
    free(vector6);
    printf("----------------------------------\n");

    printf("----------columnMeans-------------\n");
    float **matrix8 = returnMatrix(2, 3);
    matrix8 = fillMatrix(matrix8, 2, 3, seed * 16);
    printf("matrix1: \n");
    printMatrix(matrix8, 2, 3);
    printf("*****************************\n");
    float *vector7 = columnMeans(matrix8, 2, 3);
    printf("Result of Column Means: \n");
    printVector(vector7, 3);
    freeMatrix(matrix8, 2);
    free(vector7);
    printf("----------------------------------\n");

    printf("----------covarianceMatrix--------\n");
    float **matrix9 = returnMatrix(3, 3);
    matrix9 = fillMatrix(matrix9, 3, 3, seed * 18);
    printf("matrix1: \n");
    printMatrix(matrix9, 3, 3);
    printf("*****************************\n");
    float **matrix10 = covarianceMatrix(matrix9, 3, 3);
    printf("Result of Covariance Matrix: \n");
    printMatrix(matrix10, 3, 3);
    freeMatrix(matrix9, 3);
    freeMatrix(matrix10, 3);
    printf("----------------------------------\n");

    printf("----------determinant-------------\n");
    float **matrix11 = returnMatrix(3, 3);
    matrix11 = fillMatrix(matrix11, 3, 3, seed * 20);
    printf("matrix1: \n");
    printMatrix(matrix11, 3, 3);
    printf("*****************************\n");
    float det = determinant(matrix11, 3);
    printf("Result of Determinant: %f \n", det);
    freeMatrix(matrix11, 3);
    printf("----------------------------------\n");

    printf("----------printVector-------------\n");
    float *vector8 = returnVector(5);
    vector8 = fillVector(vector8, 5, seed * 22);
    printf("vector1: \n");
    printVector(vector8, 5);
    free(vector8);
    printf("----------------------------------\n");

    printf("----------printMatrix-------------\n");
    float **matrix12 = returnMatrix(2, 3);
    matrix12 = fillMatrix(matrix12, 2, 3, seed * 24);
    printf("matrix1: \n");
    printMatrix(matrix12, 2, 3);
    freeMatrix(matrix12, 2);
    printf("----------------------------------\n");

    return 0;
}
