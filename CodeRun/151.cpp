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

    int size, limit;
    cin >> size >> limit;

    vector<long long> ways(size);
    ways[0] = 1;

    for (int i = 1; i < ways.size(); i++)
        for (int delta = 1; 0 <= i - delta && delta <= limit; delta++)
            ways[i] += ways[i - delta];

    cout << ways.back();
}