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

    int size, base;
    cin >> size >> base;

    vector<int> ways = { 0, base - 1, (base - 1) * base };
    for (int i = 3; i <= size; i++)
        ways.push_back((ways[i - 2] + ways[i - 1]) * (base - 1));

    cout << ways[size];
}