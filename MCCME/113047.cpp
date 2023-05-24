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

    int size;
    cin >> size;

    vector<long long> ways = { 1, 2, 4 };
    for (int i = 3; i <= size; i++)
        ways.push_back(ways[i - 1] + ways[i - 2] + ways[i - 3]);

    cout << ways[size];
}