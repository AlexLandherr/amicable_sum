#include "include/functions.h"
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cmath>

/*
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a != b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284.
The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
*/

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
}