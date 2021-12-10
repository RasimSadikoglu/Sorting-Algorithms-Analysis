#ifndef LIST_H
#define LIST_H

#include <vector>

typedef unsigned long long ull;

std::vector<short> create_random_list(ull size);
std::vector<short> create_sorted_list(ull size);
std::vector<short> create_reverse_sorted_list(ull size);
std::vector<short> create_list_with_same_elements(ull size);

#endif