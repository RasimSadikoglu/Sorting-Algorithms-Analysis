#include "list.h"

#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <algorithm>

std::vector<short> create_random_list(ull size) {

    std::vector<short> numbers(size);

    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<short> random_number(0, 10000);

    for (auto &i: numbers) {
        i = random_number(generator);
    }

    return numbers;
}

std::vector<short> create_sorted_list(ull size) {

    std::vector<short> numbers = create_random_list(size);

    std::sort(numbers.begin(), numbers.end());

    return numbers;
}

std::vector<short> create_reverse_sorted_list(ull size) {

    std::vector<short> numbers = create_sorted_list(size);

    std::reverse(numbers.begin(), numbers.end());

    return numbers;
}

std::vector<short> create_list_with_same_elements(ull size) {

    std::vector<short> numbers(size);

    for (auto &i: numbers) i = 1;

    return numbers;
}