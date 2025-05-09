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

    int size, jump;
    cin >> size >> jump;

    vector<long long> ways(size + 1);
    ways[0] = 1;

    for (int i = 1; i < ways.size(); i++)
        for (int j : { 1, jump })
            if (i >= j)
                ways[i] += ways[i - j];

    cout << ways.back();
}