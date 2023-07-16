#include <gtest/gtest.h>

#include "Matrix.hpp"



TEST(test_google_version, test_matrix)
{
	Matrix<int, -1> matrix;
	EXPECT_TRUE(matrix.size() == 0);

	auto a = matrix[0][0];
	EXPECT_TRUE(a == -1);
	EXPECT_TRUE(matrix.size() == 0);

	matrix[100][100] = 314;
	EXPECT_TRUE(matrix[100][100] == 314);
	EXPECT_TRUE(matrix.size() == 1);
}



int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
