#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include <string>

typedef unsigned long long ull;

void insertion_sort(std::vector<short> input, std::string id);
void binary_insertion_sort(std::vector<short> input, std::string id);
void merge_sort(std::vector<short> input, std::string id);
void quicksort(std::vector<short> input, std::string id);
void quicksort_mot(std::vector<short> input, std::string id);
void heap_sort(std::vector<short> input, std::string id);
void counting_sort(std::vector<short> input, std::string id);

void merge_sort_helper(std::vector<short> &input, ull begin_index, ull end_index, ull &comparison, ull &memory_access, ull &write_into_memory);
void quicksort_helper(std::vector<short> &input, ull begin_index, ull end_index, ull &comparison, ull &memory_access, ull &write_into_memory);
void quicksort_mot_helper(std::vector<short> &input, ull begin_index, ull end_index, ull &comparison, ull &memory_access, ull &write_into_memory);

ull binary_search(const std::vector<short> &input, ull begin_index, ull end_index, short elem, ull &comparison, ull &memory_access, ull &write_into_memory);
std::vector<short> vector_partial_copy(std::vector<short> &input, ull begin_index, ull end_index);
std::string thousand_seperator(ull n);

void add_log(std::ofstream &file, ull size, std::string id, double time, ull comparison, ull memory_access, ull write_into_memory);

#endif
