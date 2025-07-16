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

    int size, step;
    cin >> size >> step;

    vector<int> res(size + 1);
    for (int i = 2; i < res.size(); i++)
        res[i] = (res[i - 1] + step) % i;

    cout << res[size];
}