#pragma once
#include <vector>

static const int seq_cnt = 6;
extern const std::vector<int>* (*seq_array[seq_cnt])(int);

enum ns_type {
	ns_fibon, ns_lucas, ns_pell,
	ns_triang, ns_square, ns_pent
};


bool is_size_ok(int size);
int get_random_int(int);
bool seq_elem(int pos, int& elem, const std::vector<int>* (*seq_ptr)(int));
const std::vector<int>* fibon_seq(int size);
const std::vector<int>* lucas_seq(int size);
const std::vector<int>* pell_seq(int size);
const std::vector<int>* square_seq(int size);
const std::vector<int>* pent_seq(int size);
const std::vector<int>* triang_seq(int size);
void display(const std::vector<int>*);
void display(int, int);

