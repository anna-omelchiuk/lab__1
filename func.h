#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <string>

using namespace std;
using namespace std::chrono;

int LinearSearch(const vector<int>& arr, int target);
int BinarySearch(const vector<int>& arr, int target);

int CheckPresence(const vector<int>& arr, int target, bool useBinary);
int LowerBound(const vector<int>& arr, int target, bool useBinary);

void Results(string name, int result, nanoseconds duration);
