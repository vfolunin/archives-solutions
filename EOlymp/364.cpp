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

    int size, index;
    cin >> size >> index;
    index--;

    vector<int> factorial(size, 1);
    for (int i = 2; i < factorial.size(); i++)
        factorial[i] = factorial[i - 1] * i;

    string s(size, ' ');
    iota(s.begin(), s.end(), 'a');

    string res;
    for (int i = 0; i < factorial.size(); i++) {
        int count = factorial[factorial.size() - 1 - i];
        res += s[index / count];
        s.erase(s.begin() + index / count);
        index %= count;
    }

    cout << res;
}