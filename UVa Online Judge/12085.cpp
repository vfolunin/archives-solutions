#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string next(string n) {
    int i = n.size() - 1;
    while (n[i] == '9') {
        n[i] = '0';
        i--;
    }
    n[i]++;
    return n;
}

bool solve(int test) {
    int numberCount;
    cin >> numberCount;

    if (!numberCount)
        return 0;

    vector<string> numbers(numberCount);
    for (string &number : numbers)
        cin >> number;
    sort(numbers.begin(), numbers.end());

    vector<pair<string, string>> res = { {numbers[0], numbers[0]} };
    for (int i = 1; i < numberCount; i++) {
        if (next(res.back().second) == numbers[i])
            res.back().second = numbers[i];
        else
            res.push_back({ numbers[i], numbers[i] });
    }

    cout << "Case " << test << ":\n";
    for (auto &[l, r] : res) {
        if (l == r) {
            cout << l << "\n";
        } else {
            cout << l << "-";
            int i = 0;
            while (l[i] == r[i])
                i++;
            cout << r.substr(i) << "\n";
        }
    }
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}