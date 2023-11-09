#include "include/functions.h"
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cmath>
#include <numeric>

namespace func {
    std::vector<int64_t> proper_divisors_of(int64_t number, bool use_sort) {
        std::vector<int64_t> result;
        result.push_back(1);
        
        for (int i = 2; i <= std::sqrt(number); i++) {
            if (number % i == 0) {
                if (number / i == i) {
                    result.push_back(i);
                } else {
                    result.push_back(i);
                    result.push_back(number / i);
                }
            }
        }
        
        if (use_sort) {
            std::sort(result.begin(), result.end());
        }

        //Return the list of divisors of number.
        return result;
    }

    int64_t sum_of_proper_divisors_of(int64_t number) {
        int64_t result = 0;

        if (number == 1 || number == 0) {
            return result;
        }
        
        result++;
        for (int i = 2; i <= std::sqrt(number); i++) {
            if (number % i == 0) {
                if (number / i == i) {
                    result += i;
                } else {
                    result += (i + (number / i));
                }
            }
        }

        //Return the sum of the proper divisors of number.
        return result;
    }

    int64_t sum_of_all_amicable_numbers_less_than(int64_t limit) {
        std::vector<int64_t> amicable_numbers;
        for (int n = 1; n < limit; n++) {
            if (n == sum_of_proper_divisors_of(sum_of_proper_divisors_of(n)) && n != sum_of_proper_divisors_of(n)) {
                amicable_numbers.push_back(n);
            }
        }

        return std::accumulate(amicable_numbers.begin(), amicable_numbers.end(), 0);
    }
}