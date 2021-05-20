#include "sorts.h"

#include <chrono>
#include <iostream>
#include <fstream>
#include <algorithm>

void insertion_sort(std::vector<short> input, std::string id) {
    ull comparison = 0, memory_access = 0, write_into_memory = 0;

    auto start_time = std::chrono::high_resolution_clock::now();

    for (ull i = 1; i < input.size(); i++) {
        short temp = input[i];
        memory_access++;
        write_into_memory++;

        ull j = i - 1;
        
        while (j != 0xFFFFFFFFFFFFFFFF) {
            comparison++;
            memory_access += 2;
            if (input[j] <= temp) {
                break;
                j--;
            }
            write_into_memory++;
            memory_access++;
            input[j + 1] = input[j];
            j--;
        }

        write_into_memory++;
        memory_access++;
        input[j + 1] = temp;
    }

    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end_time - start_time;

    std::ofstream file("logs_insertion_sort.txt", std::ios_base::app);

    add_log(file, input.size(), id, duration.count(), comparison, memory_access, write_into_memory);

    file.close();

    std::cout << "\t\tInsertion sort applied. (" << duration.count() << "s)" << std::endl << std::endl;
    return;
}

void binary_insertion_sort(std::vector<short> input, std::string id) {
    ull comparison = 0, memory_access = 0, write_into_memory = 0;

    auto start_time = std::chrono::high_resolution_clock::now();

    for (ull i = 1; i < input.size(); i++) {
        ull j = binary_search(input, 0, i - 1, input[i], comparison, memory_access, write_into_memory);
        short temp = input[i];
        memory_access++;
        write_into_memory++;
        for (ull k = i; k > j; k--) {
            memory_access++;
            write_into_memory++;
            input[k] = input[k - 1];
        }
        memory_access++;
        write_into_memory++;
        input[j] = temp;
    }

    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end_time - start_time;

    std::ofstream file("logs_binary_insertion_sort.txt", std::ios_base::app);

    add_log(file, input.size(), id, duration.count(), comparison, memory_access, write_into_memory);

    file.close();

    std::cout << "\t\tBinary insertion sort applied. (" << duration.count() << "s)" << std::endl << std::endl;
    return;
}

void merge_sort(std::vector<short> input, std::string id) {
    ull comparison = 0, memory_access = 0, write_into_memory = 0;

    auto start_time = std::chrono::high_resolution_clock::now();

    merge_sort_helper(input, 0, input.size() - 1, comparison, memory_access, write_into_memory);

    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end_time - start_time;

    std::ofstream file("logs_merge_sort.txt", std::ios_base::app);

    add_log(file, input.size(), id, duration.count(), comparison, memory_access, write_into_memory);

    file.close();

    std::cout << "\t\tMerge sort applied. (" << duration.count() << "s)" << std::endl << std::endl;
    return;
}

void quicksort(std::vector<short> input, std::string id) {
    ull comparison = 0, memory_access = 0, write_into_memory = 0;

    auto start_time = std::chrono::high_resolution_clock::now();

    quicksort_helper(input, 0, input.size() - 1, comparison, memory_access, write_into_memory);

    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end_time - start_time;

    std::ofstream file("logs_quicksort.txt", std::ios_base::app);

    add_log(file, input.size(), id, duration.count(), comparison, memory_access, write_into_memory);

    file.close();

    std::cout << "\t\tQuicksort applied. (" << duration.count() << "s)" << std::endl << std::endl;
    return;
}

void quicksort_mot(std::vector<short> input, std::string id) {
    ull comparison = 0, memory_access = 0, write_into_memory = 0;

    auto start_time = std::chrono::high_resolution_clock::now();

    quicksort_mot_helper(input, 0, input.size() - 1, comparison, memory_access, write_into_memory);

    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end_time - start_time;

    std::ofstream file("logs_quicksort_mot.txt", std::ios_base::app);

    add_log(file, input.size(), id, duration.count(), comparison, memory_access, write_into_memory);

    file.close();

    std::cout << "\t\tMedian of Three - Quicksort applied. (" << duration.count() << "s)" << std::endl << std::endl;
    return;
}

void heap_sort(std::vector<short> input, std::string id) {
    ull comparison = 0, memory_access = 0, write_into_memory = 0;

    auto start_time = std::chrono::high_resolution_clock::now();

 	for (ull i = 1; i < input.size(); i++) {
		ull j = i; while (j && input[j] > input[(j - 1) / 2]) {
            comparison++;
            memory_access += 5;
            write_into_memory += 3;
            std::swap(input[j], input[(j - 1) / 2]);
			j = (j - 1) / 2;
		}
        if (j) {
            comparison++;
            memory_access += 2;
        }
	}
	
	for (ull i = input.size() - 1; i != 0xFFFFFFFFFFFFFFFF; i--) {
        memory_access += 3;
        write_into_memory += 3;
		std::swap(input[0], input[i]);
		
		ull j = 0; while (true) {
			short temp1 = 0, temp2 = 0;
			if (2 * j + 1 < i) {
                write_into_memory++;
                memory_access++;
                temp1 = input[2 * j + 1];
            }
			if (2 * j + 2 < i) {
                memory_access++;
                write_into_memory++;
                temp2 = input[2 * j + 2];
            }

            bool big_child = temp1 > temp2;

			if (big_child && temp1 > input[j]) {
                comparison += 2;
                memory_access += 7;
                write_into_memory += 3;
                std::swap(input[j], input[2 * j + 1]);
				j = 2 * j + 1;
			} else if (temp2 > input[j]) {
                comparison += 2 + big_child;
                memory_access += (2 + big_child) * 2 + 3;
                write_into_memory += 3;
				std::swap(input[j], input[2 * j + 2]);
				j = 2 * j + 2;
			} else {
                comparison += 2 + big_child;
                memory_access += (2 + big_child) * 2;
                break;
            }
		}
	}

    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end_time - start_time;

    std::ofstream file("logs_heap_sort.txt", std::ios_base::app);

    add_log(file, input.size(), id, duration.count(), comparison, memory_access, write_into_memory);

    file.close();

    std::cout << "\t\tHeap sort applied. (" << duration.count() << "s)" << std::endl << std::endl;
    return;
}

void counting_sort(std::vector<short> input, std::string id) {
    ull comparison = 0, memory_access = 0, write_into_memory = 0;

    auto start_time = std::chrono::high_resolution_clock::now();

    std::vector<ull> counts(10001);
    for (const auto &i: input) counts[i]++;

    memory_access += input.size();
    write_into_memory += input.size();

    short j = 0;
    for (auto &i: input) {
        while (counts[j] == 0) j++;
        i = j;
        counts[j]--;
    }

    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end_time - start_time;

    std::ofstream file("logs_counting_sort.txt", std::ios_base::app);

    add_log(file, input.size(), id, duration.count(), comparison, memory_access, write_into_memory);

    file.close();

    std::cout << "\t\tCounting sort applied. (" << duration.count() << "s)" << std::endl << std::endl;
    return;
}

void merge_sort_helper(std::vector<short> &input, ull begin_index, ull end_index, ull &comparison, ull &memory_access, ull &write_into_memory) {

	if (begin_index == end_index) return;
	if (begin_index + 1 == end_index) {
        comparison++;
		if (input[begin_index] > input[end_index]) {
            memory_access += 3;
            write_into_memory += 3;
            std::swap(input[begin_index], input[end_index]);
        }
		return;
	}
	
	merge_sort_helper(input, begin_index, (begin_index + end_index) / 2, comparison, memory_access, write_into_memory);
	merge_sort_helper(input, (begin_index + end_index) / 2 + 1, end_index, comparison, memory_access, write_into_memory);
	
	ull size = (end_index - begin_index) / 2 + 1;
	std::vector<short> temp_array = vector_partial_copy(input, begin_index, size);
    memory_access += size;
    write_into_memory += size;
	
	ull i = 0, j = (begin_index + end_index) / 2 + 1;
	ull p = begin_index;
	
	while (i < size && j <= end_index) {
        comparison++;
        memory_access += 4;
        write_into_memory++;
		if (temp_array[i] < input[j]) {
			input[p++] = temp_array[i++];
		} else {
			input[p++] = input[j++];
		}
	}
	
	while (i < size) {
        memory_access++;
        write_into_memory++;
		input[p++] = temp_array[i++];
	}
	
	while (j <= end_index) {
        memory_access++;
        write_into_memory++;
		input[p++] = input[j++];
	}
	
	return;
}

void quicksort_helper(std::vector<short> &input, ull begin_index, ull end_index, ull &comparison, ull &memory_access, ull &write_into_memory) {

    while (begin_index != end_index) {

        if (begin_index + 1 == end_index) {
            comparison++;
            memory_access += 2;
            if (input[begin_index] > input[end_index]) {
                memory_access += 3;
                write_into_memory += 3;
                std::swap(input[begin_index], input[end_index]);
            }
            return;
        }

        ull left_index = begin_index + 1, right_index = end_index;
        
        while (left_index < right_index) {

            while (input[left_index] <= input[begin_index] && left_index != end_index) {
                memory_access += 2;
                comparison++;
                left_index++;
            }

            while (input[right_index] > input[begin_index] && right_index != begin_index) {
                memory_access += 2;
                comparison++;
                right_index--;
            }

            memory_access += 4;
            comparison += 2;

            if (left_index < right_index) {
                memory_access += 3;
                write_into_memory += 3;
                std::swap(input[left_index], input[right_index]);
            }
        }

        memory_access += 3;
        write_into_memory += 3;
        std::swap(input[begin_index], input[right_index]);

        if (right_index - begin_index > end_index - right_index) {
            if (right_index != end_index) quicksort_helper(input, right_index + 1, end_index, comparison, memory_access, write_into_memory);
            end_index = right_index - 1;
        } else {
            if (right_index != begin_index) quicksort_helper(input, begin_index, right_index - 1, comparison, memory_access, write_into_memory);
            begin_index = right_index + 1;
        }

    }

    return;
}

void quicksort_mot_helper(std::vector<short> &input, ull begin_index, ull end_index, ull &comparison, ull &memory_access, ull &write_into_memory) {

    while (begin_index != end_index) {

        if (begin_index + 1 == end_index) {
            comparison++;
            if (input[begin_index] > input[end_index]) {
                memory_access += 3;
                write_into_memory += 3;
                std::swap(input[begin_index], input[end_index]);
            }
            return;
        }

        ull mid_point = (end_index + begin_index) / 2;
        if (input[begin_index] > input[mid_point]) {
            memory_access += 3;
            write_into_memory += 3;
            std::swap(input[begin_index],input[mid_point]);
        }
        if (input[mid_point] > input[end_index]) {
            memory_access += 3;
            write_into_memory += 3;
            std::swap(input[mid_point],input[end_index]);
        }
        if (input[begin_index] > input[mid_point]) {
            memory_access += 3;
            write_into_memory += 3;
            std::swap(input[begin_index],input[mid_point]);
        }

        comparison += 3;
        memory_access += 6;

        if (begin_index + 2 == end_index) return;

        memory_access += 3;
        write_into_memory += 3;
        std::swap(input[begin_index], input[mid_point]);

        ull left_index = begin_index + 1, right_index = end_index;
        
        while (left_index < right_index) {

            while (input[left_index] <= input[begin_index] && left_index != end_index) {
                memory_access += 2;
                comparison++;
                left_index++;
            }

            while (input[right_index] > input[begin_index] && right_index != begin_index) {
                memory_access += 2;
                comparison++;
                right_index--;
            }

            memory_access += 4;
            comparison += 2;

            if (left_index < right_index) {
                memory_access += 3;
                write_into_memory += 3;
                std::swap(input[left_index], input[right_index]);
            }
        }

        memory_access += 3;
        write_into_memory += 3;
        std::swap(input[begin_index], input[right_index]);

        if (right_index - begin_index > end_index - right_index) {
            if (right_index != end_index) quicksort_mot_helper(input, right_index + 1, end_index, comparison, memory_access, write_into_memory);
            end_index = right_index - 1;
        } else {
            if (right_index != begin_index) quicksort_mot_helper(input, begin_index, right_index - 1, comparison, memory_access, write_into_memory);
            begin_index = right_index + 1;
        }

    }

    return;
}

ull binary_search(const std::vector<short> &input, ull begin_index, ull end_index, short elem, ull &comparison, ull &memory_access, ull &write_into_memory) {

    if (begin_index == end_index) {
        comparison++;
        memory_access += 2;
        return begin_index + (input[begin_index] < elem);
    }
    
    ull new_index = (begin_index + end_index) / 2;

    memory_access += 2;
    comparison++;
    if (elem == input[new_index]) return new_index;
    else if (elem > input[new_index]) {
        comparison++;
        memory_access += 2;
        begin_index = new_index + 1;
    } else {
        comparison++;
        memory_access += 2;
        end_index = new_index - (begin_index != new_index);
    }

    return binary_search(input, begin_index, end_index, elem, comparison, memory_access, write_into_memory);
}

std::vector<short> vector_partial_copy(std::vector<short> &input, ull begin_index, ull size) {

    std::vector<short> partial_copy(size);

    for (ull i = 0; i < size; i++) {
        partial_copy[i] = input[begin_index + i];
    }

    return partial_copy;
}

std::string thousand_seperator(ull n) {
    if (n < 1000) return std::to_string(n);

    std::string result = "";
    int i = 0;

    do {
        if (i % 3 == 0 && i) result.push_back(',');
        result.push_back(n % 10 + '0');
        i++;
    } while (n /= 10);

    std::reverse(result.begin(), result.end());

    return result;
}

void add_log(std::ofstream &file, ull size, std::string id, double time, ull comparison, ull memory_access, ull write_into_memory) {
    
    if (id == "1") file << "----------SIZE: " << thousand_seperator(size) << "----------" << std::endl;

    file << "\tTest: #" << id << std::endl;
    file << "Real Time: " << time << " sec." << std::endl;
    file << "Comparisons: " << thousand_seperator(comparison) << std::endl;
    file << "Memory Accesses: " << thousand_seperator(memory_access) << std::endl;
    file << "Write Into Memory: " << thousand_seperator(write_into_memory) << std::endl << std::endl;
    
    return;
}