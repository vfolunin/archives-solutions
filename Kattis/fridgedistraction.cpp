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

    int size, sum;
    cin >> size >> sum;

    string s(size, ' ');
    iota(s.begin(), s.end(), 'a');

    string res;
    while (sum) {
        int delta = min(sum, size);
        sum -= delta;

        res.push_back(s[delta - 1]);
        s.erase(s.begin() + delta - 1);
        s.insert(s.begin(), res.back());
    }

    cout << res.size() << "\n";
    for (char c : res)
        cout << c << " ";
}