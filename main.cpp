#include "func.h"

int main()
{

    const int n = 100000000;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = i * 2;

    int target;
    cout << "Input target: "; cin >> target;
    cout << "\n" << string(85, '-') << "\n";


    auto s = high_resolution_clock::now();
    int r1 = CheckPresence(arr, target, false);
    auto e = high_resolution_clock::now();
    Results("Task 1 (Linear Search)", r1, e - s);

    s = high_resolution_clock::now();
    int r2 = CheckPresence(arr, target, true);
    e = high_resolution_clock::now();
    Results("Task 1 (Binary Search)", r2, e - s);

    cout << string(85, '-') << "\n";

    s = high_resolution_clock::now();
    int r3 = FindUpperBound(arr, target, false);
    e = high_resolution_clock::now();
    Results("Task 2 (Linear UpperBound)", r3, e - s);

    s = high_resolution_clock::now();
    int r4 = FindUpperBound(arr, target, true);
    e = high_resolution_clock::now();
    Results("Task 2 (Binary UpperBound)", r4, e - s);

    cout << string(85, '-') << "\n";

    return 0;
}