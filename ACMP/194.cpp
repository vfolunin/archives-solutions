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

    vector<long long> ways = { 0, 1, 1 };
    for (int i = 3; i <= size; i++)
        ways.push_back(ways[i - 1] + ways[i - 3] + 1);

    cout << ways[size];
}