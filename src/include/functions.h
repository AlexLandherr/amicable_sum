#include <cstdint>
#include <vector>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

namespace func {
    std::vector<int64_t> proper_divisors_of(int64_t number, bool use_sort);
    int64_t sum_of_proper_divisors_of(int64_t number);
    int64_t sum_of_all_amicable_numbers_less_than(int64_t limit);
}

#endif