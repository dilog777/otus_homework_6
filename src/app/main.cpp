#include "Matrix.hpp"

#include <cassert>
#include <iostream>


int main (int, char **)
{
	{
		Matrix<int, -1> matrix;
		assert(matrix.size() == 0);

		auto a = matrix[0][0];
		assert(a == -1);
		assert(matrix.size() == 0);

		matrix[100][100] = 314;
		assert(matrix[100][100] == 314);
		assert(matrix.size() == 1);
	}

	{
		Matrix<int, 0> matrix;
		for (int i = 0; i < 10; ++i)
		{
			matrix[i][i] = i;
			matrix[9 - i][i] = i;
		}

		for (int row = 1; row < 9; ++row)
		{
			for (int column = 1; column < 9; ++column)
			{
				std::cout << matrix[row][column] << " ";
			}
			std::cout << std::endl;
		}

		std::cout << matrix.size() << std::endl;

		((matrix[100][100] = 314) = 0) = 217;
		std::cout << matrix[100][100] << std::endl;
	}

	return 0;
}
