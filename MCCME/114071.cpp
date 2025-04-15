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

    int size, take;
    cin >> size >> take;

    vector<int> res(size + 1, 2);
    for (int i = 1; i < res.size(); i++)
        for (int j : { i - 1, i - 2, i - take })
            if (0 <= j && res[j] == 2)
                res[i] = 1;

    cout << res[size];
}