// GuessSeries.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "User.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool ReadFile(ifstream& infile, string usr_name, int& num_tries, int& num_cor, vector<User>& list) {
	string name;
	bool flag = false;
	int nt;
	int nc;
	infile.seekg(0);
	while (infile >> name)
	{
		infile >> nt >> nc;
		list.push_back(User(name,nt,nc));
		
		if (name == usr_name)
		{
			cout << "Welcome back, " << usr_name
				<< "\nYour current score is " << nc
				<< " out of " << nt << "\nGood Luck!\n";
			num_tries = nt;
			num_cor = nc;
			list.pop_back();
			flag = true;
		}
	}
	return flag;
}

void WriteFile(ofstream& outfile, string usr_name, int& num_tries, int& num_cor, vector<User>& list) {


	outfile << usr_name << ' '
		<< num_tries << ' '
		<< num_cor << endl;
	for (auto& usr : list)
	{
		outfile << usr.usr_name << ' '
			<< usr.t_times << ' '
			<< usr.c_times << endl;
	}

}

void Test(vector<User>& inArr) {
	cout << inArr.size()<< endl;
	for (auto& usr : inArr)
	{
		cout << usr.usr_name << endl;
	}
}

void DisplaySeries() {}
void DisplayRecord() {}

int main()
{
	// 全局变量
	string usr_name;
	bool next_seq = true;
	bool go_for_it = true;
	bool got_it = false;
	bool is_existed = false;
	int num_tries_T = 0;
	int num_right = 0;
	int max_tries = 3;
	int next_elem = -1;
	int num_tries_W = 0;
	vector<User> usr_list;
	// 话语
	vector<string> words(4);
	words[0] = "Oops! Nice guess but not quite it.\n";
	words[1] = "Hmm. Sorry. Wrong a second time.\n";
	words[2] = "Ah, this is harder than it looks, isn't it?\n";
	words[3] = "It must be getting pretty frustrating by now!\n";

	// 文件
	ifstream infile("seq_data.txt", ios_base::in);
	if (!infile)
	{
		cerr << "Oops! Unable to save session data!\n";
	}

	// 优化生成函数
	vector<int> fib(3);
	fib[0] = 1;
	fib[1] = 1;
	fib[2] = 2;



	cout << "Welcome to GuessSeries Game! Please Enter your Name\n";
	cin >> usr_name;
	// 读取【创建】文件
	is_existed = ReadFile(infile, usr_name, num_tries_W, num_right, usr_list); 
	//Test(usr_list);
	while (next_seq)
	{
		// 为用户显示数列
		// 优化随机选择函数
		for (int i = 0; i < 2; i++)
		{
			cout << fib[i] << " ";
		}
		//cout << endl;

		next_elem = 2;
		//
		while ((!got_it) && go_for_it && num_tries_T < max_tries)
		{
			int usr_guess;
			cin >> usr_guess;
			num_tries_T++;
			num_tries_W++;
			if (usr_guess == next_elem && next_elem != -1)
			{
				got_it = true;
				num_right++;

			}
			else
			{
				// 用户猜错的输出
				switch (num_tries_T)
				{
				case 1:
					cout << words[0];
					break;
				case 2:
					cout << words[1];
					break;
				case 3:
					cout << words[2];
					break;
				default:
					cout << words[3];
					break;
				}
				// 大于等于3跳出
				if (num_tries_T >= 3) break;
				// 询问用户是否想再猜一次
				cout << "Would you want to try it again? (Y/N)";
				char usr_rsp;
				cin >> usr_rsp;
				if (usr_rsp == 'N' || usr_rsp == 'n')
				{
					go_for_it = false;
				}
			}
		}

		cout << "Want to try another sequence? (Y/N)";
		char try_again;
		cin >> try_again;

		if (try_again == 'N' || try_again == 'n')
		{
			next_seq = false;
		}
		else
		{
			got_it = false;
			go_for_it = true;
			num_tries_T = 0;
		}
	}
	// 写入文件
	ofstream outfile("seq_data.txt", ios_base::trunc);
	WriteFile(outfile, usr_name, num_tries_W, num_right, usr_list);
	// 显示文件内容
}


