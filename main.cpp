#include <iostream>
#include <chrono>

#include "list.h"
#include "sorts.h"

const int test_table[7][4] =	{{8, 20, 7, 20}, 	    // Insertion Sort
				                {8, 14, 7, 8},   	    // Binary Insertion Sort
				                {17, 17, 17, 17},   	// Merge Sort
				                {14, 9, 8, 7},   	    // Quicksort
				                {14, 12, 12, 7},   	    // Quicksort - MOT
				                {16, 16, 16, 20},   	// Heap Sort
				                {20, 20, 20, 20}};  	// Counting Sort

void start_tests(ull size, int power);

int main() {

    auto start_time = std::chrono::high_resolution_clock::now();
	
    ull size = 1000;
    for (int i = 0; i < 11; i++) {
        start_tests(size, i);
        size *= 2;
    }
	
	auto end_time = std::chrono::high_resolution_clock::now();
	
	std::chrono::duration<double> duration = end_time - start_time;
	
	std::cout << "\nAll tests are applied.\nTotal execution time: " << duration.count() << " sec.\n\n";

    return 0;
}

void start_tests(ull size, int power) {

    const int RANDOM_TESTS = 10;

    std::cout << "------------------Size: " << thousand_seperator(size) << "------------------" << std::endl << std::endl;

    for (int i = 1; i < RANDOM_TESTS + 4; i++) {
        
        std::vector<short> numbers;
        std::string id;
        if (i == RANDOM_TESTS + 3) {
            numbers = create_list_with_same_elements(size);
            id = "13-SPECIAL-ALL ELEMENTS ARE SAME";
        } else if (i == RANDOM_TESTS + 2) {
            numbers = create_reverse_sorted_list(size);
            id = "12-SPECIAL-REVERSE SORTED LIST";
        } else if (i == RANDOM_TESTS + 1) {
            numbers = create_sorted_list(size);
            id = "11-SPECIAL-SORTED LIST";
        } else {
            numbers = create_random_list(size);
            id = std::to_string(i);
        }

        std::cout << "\t(" << id << "/" << RANDOM_TESTS + 3 << ") list(s) generated.\n" << std::endl;

        if (test_table[0][(i % 10) * (i / 10)] > power) insertion_sort(numbers, id);
        if (test_table[1][(i % 10) * (i / 10)] > power) binary_insertion_sort(numbers, id);
        if (test_table[2][(i % 10) * (i / 10)] > power) merge_sort(numbers, id);
        if (test_table[3][(i % 10) * (i / 10)] > power) quicksort(numbers, id);
        if (test_table[4][(i % 10) * (i / 10)] > power) quicksort_mot(numbers, id);
        if (test_table[5][(i % 10) * (i / 10)] > power) heap_sort(numbers, id);
        if (test_table[6][(i % 10) * (i / 10)] > power) counting_sort(numbers, id);
    }

    std::cout << std::endl;
    return;
}
