#include "func.h"

int LinearSearch(const vector<int>& arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int BinarySearch(const vector<int>& arr, int target)
{
    int L = 0, R = arr.size() - 1;
    while (L <= R)
    {
        int mid = L + (R - L) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target) L = mid + 1;
        else R = mid - 1;
    }
    return -1;
}

int CheckPresence(const vector<int>& arr, int target, bool useBinary)
{
    if (useBinary)
        return BinarySearch(arr, target);
    return LinearSearch(arr, target);
}

int FindUpperBound(const vector<int>& arr, int target, bool useBinary)
{
    if (useBinary)
    {
        int L = 0, R = arr.size() - 1, ans = -1;
        while (L <= R)
        {
            int mid = L + (R - L) / 2;
            if (arr[mid] >= target)
            {
                ans = mid; R = mid - 1;
            }
            else L = mid + 1;
        }
        return ans;
    } else {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] >= target)
                return i;
        }
        return -1;
    }
}

void Results(string name, int result, nanoseconds duration)
{
    cout << setfill(' ') << left << setw(30) << name << "  Res: " << setw(8) << result << "  Time: ";
    auto h = duration_cast<hours>(duration);
    duration -= h;
    auto m = duration_cast<minutes>(duration);
    duration -= m;
    auto s = duration_cast<seconds>(duration);
    duration -= s;
    auto micro = duration_cast<microseconds>(duration);
    cout << setfill('0') << setw(2) << h.count() << ":" << setw(2) << m.count() << ":"
         << setw(2) << s.count() << "." << setw(7) << micro.count() << endl;
}