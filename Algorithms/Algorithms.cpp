// Algorithms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <queue>
#include <iostream>
std::vector<double> medians(const std::vector<int>& vec);

int main()
{
	std::vector<int> vec = { 83,38,56,95,99,25,15 };
	std::vector<int> v = { 83,38,56,95,99,25,15 };
	auto res = medians(v);
	for (auto i : res)std::cout << i << std::endl;


    return 0;
}

