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

    vector<int> res = { 1, 2 };
    for (int i = 2; i <= size; i++)
        res.push_back(res[i - 1] + res[i - 2]);

    cout << res[size];
}