#include "prefix_sum.hpp"
#ifdef _OPENMP
#include <omp.h>
#endif

std::vector<int> prefixSum(const std::vector<int> &input) {
    int n = input.size();
    std::vector<int> result(n, 0);

    result[0] = input[0];
    for (int i = 1; i < n; i++) {
        result[i] = result[i - 1] + input[i];
    }

    return result;
}

std::vector<int> prefixSumOpenMP(const std::vector<int> &input) {
    int n = input.size();
    std::vector<int> result(n, 0);

    result[0] = input[0];
    #pragma omp parallel for
    for (int i = 1; i < n; i++) {
        result[i] = result[i - 1] + input[i];
    }

    return result;
}
