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

    cout << string(size + 1, ' ') << "x\n";
    for (int l = size, m = 1; l; l--, m += 2)
        cout << string(l, ' ') << "/" << string(m, ' ') << "\\\n";
    cout << "x" << string(size * 2 + 1, ' ') << "x\n";
    for (int l = 1, m = size * 2 - 1; l <= size; l++, m -= 2)
        cout << string(l, ' ') << "\\" << string(m, ' ') << "/\n";
    cout << string(size + 1, ' ') << "x\n";
}