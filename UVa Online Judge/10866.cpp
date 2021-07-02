#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int size;
    cin >> size;

    if (!size)
        return 0;

    if (size == 2) {
        cout << "Impossible\n";
        return 1;
    }

    string s(size, '1');
    for (long long i = 1; i < size; i++)
        s[i * i % size] = '0';

    cout << s.substr(1) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}