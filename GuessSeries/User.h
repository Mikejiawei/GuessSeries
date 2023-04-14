#pragma once
#include <string>


class User
{
public:
	std::string usr_name;
	int t_times;
	int c_times;
public:
	User();
	User(std::string, int, int);
	~User();

private:

};