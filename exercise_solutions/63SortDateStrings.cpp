// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <sstream>
#include <ctime>
#include <time.h>
#include <iomanip>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;


char* strptime(const char* s,
	const char* f,
	struct tm* tm) {
	std::istringstream input(s);
	//input.imbue(std::locale(setlocale(LC_ALL, nullptr)));
	input >> std::get_time(tm, f);
	if (input.fail()) {
		return nullptr;
	}
	return (char*)(s + input.tellg());
}

void printTime(string s)
{
	struct tm tm {};
	if (strptime(s.c_str(), "%Y-%m-%dT%H:%M:%S", &tm)) {
		int d = tm.tm_mday,
			m = tm.tm_mon + 1,
			y = tm.tm_year + 1900;
		std::cout <<std::endl<< y << "-" << m << "-" << d << " "
			<< tm.tm_hour << ":" << tm.tm_min << ":" << tm.tm_sec;
	}
}

bool compareTime(const string& s1, const string& s2)
{
	struct tm tm1 {};
	struct tm tm2 {};
	if (strptime(s1.c_str(), "%Y-%m-%dT%H:%M:%S", &tm1) && 
		strptime(s2.c_str(), "%Y-%m-%dT%H:%M:%S", &tm2)) {
		int d1 = tm1.tm_mday;
		int	m1 = tm1.tm_mon + 1;
		int y1 = tm1.tm_year + 1900;
		int hour1 = tm1.tm_hour;
		int min1 = tm1.tm_min;
		int sec1 = tm1.tm_sec;

		int d2 = tm2.tm_mday;
		int	m2 = tm2.tm_mon + 1;
		int y2 = tm2.tm_year + 1900;
		int hour2 = tm2.tm_hour;
		int min2 = tm2.tm_min;
		int sec2 = tm2.tm_sec;

		// All cases when true should be returned
		if (y1 < y2)
			return true;
		if (y1 == y2 && m1 < m2)
			return true;
		if (y1 == y2 && m1 == m2 && d1 < d2)
			return true;
		if (y1 == y2 && m1 == m2 && d1 == d2 && hour1 < hour2)
			return true;
		if (y1 == y2 && m1 == m2 && d1 == d2 && hour1 == hour2 && min1 < min2)
			return true;
		if (y1 == y2 && m1 == m2 && d1 == d2 && hour1 == hour2 && min1 == min2 && sec1 < sec2)
			return true;
	}
	// If none of the above cases satisfy, return false
	return false;
}

int main() {
	
	std::string s1("2023-07-28T14:53:14.763+00:00");
	std::string s2("2023-07-28T08:51:48.685+00:00");
	std::string s3("2023-07-27T19:44:54.269+00:00");
	std::string s4("2023-07-27T18:33:45.684+00:00");
	vector<string> v;
	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s3);
	v.push_back(s4);

	sort(v.begin(), v.end(), compareTime);

	for (auto a : v)
	{
		printTime(a);
	}
	
}

