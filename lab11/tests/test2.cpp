#include <gtest/gtest.h>
#include "fisier2.h"
//Zapodeanu Nadia

TEST(SortingAlgorithmB, HandlesEmptyVector) {
    std::vector<int> vec;
    sortingAlgorithm(vec);
    EXPECT_EQ(vec.size(), 0);
}

TEST(SortingAlgorithmB, HandlesSingleElement) {
    std::vector<int> vec = {1};
    sortingAlgorithm(vec);
    EXPECT_EQ(vec.size(), 1);
    EXPECT_EQ(vec[0], 1);
}

TEST(SortingAlgorithmB, SortsCorrectly) {
    std::vector<int> vec = {4, 3, 2, 1};
    sortingAlgorithm(vec);
    EXPECT_TRUE(std::is_sorted(vec.begin(), vec.end()));
}

TEST(SortingAlgorithmB, DetectsIncorrectSwap) {
    std::vector<int> vec = {1, 3, 2};
    sortingAlgorithm(vec);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
}

TEST(SortingAlgorithmB, DetectsUnnecessaryModification) {
    std::vector<int> vec = {5};
    sortingAlgorithm(vec);
    EXPECT_EQ(vec.size(), 1);
    EXPECT_EQ(vec[0], 5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
