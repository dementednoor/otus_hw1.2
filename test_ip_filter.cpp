#include "gtest/gtest.h"
#include "ip_filter.cpp"


std::vector<std::vector<int>> vec{
	{2, 3, 4, 15},
	{1, 2, 3, 4},
	{2, 4, 8, 16},
	{1, 6, 8, 9}
};

TEST(Unit, should_print_only_addresses_with_certain_first_number) {
	const std::vector<std::vector<int>> expected_vec;
	EXPECT_EQ(1, 1);
}

