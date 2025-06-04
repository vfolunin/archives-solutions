#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<long long> a = { 1, 2, 3 };

    for (int i = 3; i < 100; i++)
        a.push_back(a[i - 3] + a[i - 1]);

    for (long long value : a)
        cout << value << "\n";
}