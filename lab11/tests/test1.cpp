#include <gtest/gtest.h>
#include "fisier1.h"
//Varzar Alina-Miruna

TEST(SortingAlgorithmA, HandlesEmptyVector) {
    std::vector<int> vec;
    sortingAlgorithm(vec);
    EXPECT_EQ(vec.size(), 0);
}

TEST(SortingAlgorithmA, HandlesSingleElement) {
    std::vector<int> vec = {1};
    sortingAlgorithm(vec);
    EXPECT_EQ(vec.size(), 1);
    EXPECT_EQ(vec[0], 1);
}

TEST(SortingAlgorithmA, SortsCorrectly) {
    std::vector<int> vec = {4, 3, 2, 1};
    sortingAlgorithm(vec);
    EXPECT_FALSE(std::is_sorted(vec.begin(), vec.end()));
}

TEST(SortingAlgorithmA, DetectsWrongOrder) {
    std::vector<int> vec = {1, 2, 3, 4};
    sortingAlgorithm(vec);
    EXPECT_FALSE(std::is_sorted(vec.begin(), vec.end(), std::greater<int>()));
}

TEST(SortingAlgorithmA, DetectsUnnecessarySwap) {
    std::vector<int> vec = {1, 2, 3};
    sortingAlgorithm(vec);
    EXPECT_EQ(vec[0], 2);
    EXPECT_EQ(vec[1], 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
