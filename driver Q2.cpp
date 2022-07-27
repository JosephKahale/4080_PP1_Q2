#include <iostream>
#include <chrono>

float** allocateMat(int, int);
void setMatValues(float**, int, int);
void set10MatValues(float**, int, int);
float** addMatrix(float**, float**, int, int, int, int);
float** subtractMatrix(float**, float**, int, int, int, int);
float** multiplyMatrix(float**, float**, int, int, int, int);
void displayVals(float**, int, int);

int main() {
	int matOneSizeRow, matOneSizeCol, matTwoSizeRow, matTwoSizeCol;
	int choice;

	choice = -1;

	do {

		float** matrix;
		float** matrix2;
		std::cout << "Enter Row Size of Matrix 1" << std::endl;
		std::cin >> matOneSizeRow;
		std::cout << "Enter Col Size of Matrix 1" << std::endl;
		std::cin >> matOneSizeCol;
		std::cout << "Enter Row Size of Matrix 2" << std::endl;
		std::cin >> matTwoSizeRow;
		std::cout << "Enter Col Size of Matrix 2" << std::endl;
		std::cin >> matTwoSizeCol;

		matrix = allocateMat(matOneSizeRow, matOneSizeCol);
		setMatValues(matrix, matOneSizeRow, matOneSizeCol);

		matrix2 = allocateMat(matTwoSizeRow, matTwoSizeCol);
		setMatValues(matrix2, matTwoSizeRow, matTwoSizeCol);

		std::cout << "Matrix Values Saved!" << std::endl;

		do {
			float** matrix3;
			std::cout << "Please Make a Selection: " << std::endl;
			std::cout << "	1. Create a new matrix." << std::endl;
			std::cout << "	2. Add Current Matricies." << std::endl;
			std::cout << "	3. Subtract Current Matricies." << std::endl;
			std::cout << "	4. Multiply Current Matricies." << std::endl;
			std::cout << "	5. Quit the Program." << std::endl;
			std::cin >> choice;

			switch (choice)
			{
			case 1:
			{

				break;
			}
			case 2:
			{
				matrix3 = allocateMat(matTwoSizeRow, matTwoSizeCol);
				auto start = std::chrono::steady_clock::now();
				matrix3 = addMatrix(matrix, matrix2, matOneSizeRow, matOneSizeCol, matTwoSizeRow, matTwoSizeCol);
				auto end = std::chrono::steady_clock::now();

				std::cout << "Elapsed time in nanoseconds: "
					<< std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
					<< " ns" << std::endl;

				displayVals(matrix3, matOneSizeRow, matOneSizeCol);

				for (int i = 0; i < matTwoSizeRow; i++) {
					delete[] matrix3[i];
				}
				delete[] matrix3;

				break;
			}
			case 3:
			{
				matrix3 = allocateMat(matTwoSizeRow, matTwoSizeCol);

				auto start = std::chrono::steady_clock::now();
				matrix3 = subtractMatrix(matrix, matrix2, matOneSizeRow, matOneSizeCol, matTwoSizeRow, matTwoSizeCol);
				auto end = std::chrono::steady_clock::now();

				std::cout << "Elapsed time in nanoseconds: "
					<< std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
					<< " ns" << std::endl;
				displayVals(matrix3, matOneSizeRow, matOneSizeCol);

				for (int i = 0; i < matTwoSizeRow; i++) {
					delete[] matrix3[i];
				}
				delete[] matrix3;
				break;
			}
			case 4:
			{
				matrix3 = allocateMat(matOneSizeRow, matTwoSizeCol);

				auto start = std::chrono::steady_clock::now();
				matrix3 = multiplyMatrix(matrix, matrix2, matOneSizeRow, matOneSizeCol, matTwoSizeRow, matTwoSizeCol);
				auto end = std::chrono::steady_clock::now();

				std::cout << "Elapsed time in nanoseconds: "
					<< std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
					<< " ns" << std::endl;
				displayVals(matrix3, matOneSizeRow, matTwoSizeCol);

				for (int i = 0; i < matOneSizeRow; i++) {
					delete[] matrix3[i];
				}
				delete[] matrix3;
				break;
			}
			case 5:
				std::cout << "Goodbye!" << std::endl;
				break;
			default:
				std::cout << "Incorrect choice, Please try again." << std::endl;
				break;
			}
		} while (choice != 1 && choice != 5);
		for (int i = 0; i < matOneSizeRow; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
		for (int i = 0; i < matTwoSizeRow; i++) {
			delete[] matrix2[i];
		}
		delete[] matrix2;
	} while (choice != 5);

	return 0;
}

float** allocateMat(int row, int col) {
	float** matrix;
	matrix = new float* [row];

	for (int i = 0; i < row; i++) {
		matrix[i] = new float[col];
	}

	return matrix;
}

void setMatValues(float** mat, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cout << "Please enter the float values for: i: " << i << " | j: " << j << std::endl;
			std::cin >> mat[i][j];
		}
	}
}

void set10MatValues(float** mat, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cout << "Please enter the float values for: i: " << i << " | j: " << j << std::endl;
			mat[i][j] = 2.56;
		}
	}
}

float** addMatrix(float** mat, float** mat2, int row, int col, int row2, int col2) {
	if (row != row2 || col != col2) {
		std::cout << "Incompatible types: Please Use Same Dimension Matrix.";
	}
	else {
		float** matrix;

		matrix = allocateMat(row, col);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				matrix[i][j] = mat[i][j] + mat2[i][j];
			}
		}

		return matrix;
	}

}

float** subtractMatrix(float** mat, float** mat2, int row, int col, int row2, int col2) {
	float** matrix;

	if (row != row2 || col != col2) {
		std::cout << "Incompatible types: Please Use Same Dimension Matrix.";
	}
	else {
		float** matrix;

		matrix = allocateMat(row, col);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				matrix[i][j] = mat[i][j] - mat2[i][j];
			}
		}
		return matrix;
	}

}

float** multiplyMatrix(float** mat, float** mat2, int row, int col, int row2, int col2) {
	float** matrix;

	if (col2 != row) {
		std::cout << "Incompatible types: Please Use Compatible Dimension Matrix.";
	}
	else {
		float** matrix;

		matrix = allocateMat(row, col2);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				matrix[i][j] = 0;
			}
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col2; j++) {
				for (int k = 0; k < col; k++) {
					matrix[i][j] += mat[i][k] * mat2[k][j];
				}
			}
		}
		return matrix;
	}
}

void displayVals(float** mat3, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cout << mat3[i][j] << " ";
		}
		std::cout << std::endl;
	}
}