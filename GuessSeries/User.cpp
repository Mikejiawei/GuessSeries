#include "User.h"
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

User::User(string name, int nt, int nc)
{
	usr_name = name;
	t_times = nt;
	c_times = nc;
}
User::User() {}

User::~User() {}

