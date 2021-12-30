#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int size;
    if (!(cin >> size))
        return 0;

    if (!size)
        return 1;

    vector<long long> numbers(size);
    for (long long &number : numbers)
        cin >> number;
    sort(numbers.begin(), numbers.end());

    vector<long long> res;
    int row = 1;
    for (int i = 1; i < size; i++) {
        if (numbers[i] == numbers[i - 1]) {
            row++;
        } else {
            if (row % 2)
                res.push_back(numbers[i - 1]);
            row = 1;
        }
    }
    if (row % 2)
        res.push_back(numbers[size - 1]);

    cout << res[0] << " " << res[1] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}