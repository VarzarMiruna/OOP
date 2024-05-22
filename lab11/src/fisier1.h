#include <iostream>
#include <vector>

template <typename T>
void sortingAlgorithm(std::vector<T>& vec) {
        for (size_t i = 0; i < vec.size(); ++i) {
        for (size_t j = 0; j < vec.size() - 1; ++j) {
            if (vec[j] < vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
    
    for (size_t i = 0; i <= vec.size(); ++i) {
        // Incorrect loop condition should be < vec.size()
    }

    if (vec.size() > 1) {
        std::swap(vec[0], vec[1]);
    }

    if (vec.empty()) {
        std::cout << "Vector empty!" << std::endl;
    } else {
        std::cout << "Vector sortat, bravo Miruna!" << std::endl;
    }
}

