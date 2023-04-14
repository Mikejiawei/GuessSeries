#include <vector>
#include <iostream>
#include <cmath>
#include <cstdlib>

int get_random_int(int Max)
{
	int ans = 0;
	srand((unsigned)time(0));
	ans = rand() % Max;
	return ans;
}

bool is_size_ok(int size)
{
	const int max_size = 1024;
	if (size <= 0 || size > max_size)
	{
		std::cerr << "Oops: requested size is not supported : "
			<< size << " -- can't fulfill request.\n";
		return false;
	}
	return true;
}

bool seq_elem(int pos, int& elem, const std::vector<int>* (*seq_ptr)(int))
{
	const std::vector<int>* pseq = seq_ptr(pos);

	if (!pseq)
	{
		elem = 0; return false;
	}
	elem = (*pseq)[pos - 1];
	return true;
}

const std::vector<int>* fibon_seq(int size)
{

	static std::vector<int> elems;
	if (!is_size_ok(size))
		return 0;// ·µ»Ø¿ÕµØÖ·
	for (int pos = elems.size(); pos < size; pos++)
	{
		if (pos == 0 || pos == 1)
			elems.push_back(1);
		else elems.push_back(elems[pos - 1] + elems[pos - 2]);
	}
	return &elems;
}

const std::vector<int>* lucas_seq(int size)
{
	static std::vector<int> elems;
	if (!is_size_ok(size))
		return 0;
	for (int pos = elems.size(); pos < size; pos++)
	{
		if (pos == 0 || pos == 1)
		{
			if (pos == 0) elems.push_back(1);
			else elems.push_back(3);
		}
		else
		{
			elems.push_back(elems[pos - 1] + elems[pos - 2]);
		}

	}
	return &elems;
}
const std::vector<int>* pell_seq(int size)
{
	static std::vector<int> elems;
	if (!is_size_ok(size))
		return 0;
	for (int pos = elems.size(); pos < size; pos++)
	{
		if (pos == 0 || pos == 1)
		{
			if (pos == 0) elems.push_back(1);
			else
			{
				elems.push_back(2);
			}
		}
		else elems.push_back(elems[pos - 2] + elems[pos - 1] * 2);
	}
	return &elems;
}
const std::vector<int>* triang_seq(int size)
{
	static std::vector<int> elems;
	if (!is_size_ok(size))
		return 0;
	for (int pos = elems.size(); pos < size; pos++)
	{
		if (pos == 0)
		{
			elems.push_back(1);
		}
		else
		{
			elems.push_back(elems[pos - 1] + pos + 1);
		}
	}
	return &elems;
}
const std::vector<int>* square_seq(int size)
{
	static std::vector<int> elems;
	if (!is_size_ok(size))
		return 0;
	for (int pos = elems.size(); pos < size; pos++)
	{
		if (pos == 0)
		{
			elems.push_back(1);
		}
		else
		{
			elems.push_back((pos + 1) * (pos + 1));
		}
	}
	return &elems;
}
const std::vector<int>* pent_seq(int size)
{
	static std::vector<int> elems;
	if (!is_size_ok(size))
		return 0;
	for (int pos = elems.size(); pos < size; pos++)
	{
		int px = pos + 1;
		if (pos == 0)
		{
			elems.push_back(1);
		}
		else
		{
			elems.push_back(px * (3 * px - 1) / 2);
		}
	}
	return &elems;

}
void display(const std::vector<int>* arr)
{
	for (auto& ele : *arr)
	{
		std::cout << ele << " ";
	}
	std::cout << std::endl;
}

void display(int n1, int n2)
{
	std::cout << "The series: " << n1 << " " << n2 << " ";
}


const std::vector<int>* (*seq_array[6])(int) = { fibon_seq , lucas_seq,pell_seq,triang_seq,square_seq,pent_seq };