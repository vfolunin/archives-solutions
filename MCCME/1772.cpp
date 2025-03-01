#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, limit;
    cin >> size >> limit;

    vector<int> res(size - 1, 1);
    while (1) {
        int sum = accumulate(res.end() - (size - 1), res.end(), 0);
        if (sum <= limit)
            res.push_back(sum);
        else
            break;
    }

    cout << res.size() << "\n";
    for (int value : res)
        cout << value << " ";
}