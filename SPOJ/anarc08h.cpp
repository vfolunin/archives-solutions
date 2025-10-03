#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int joseph(int size, int step) {
    return size > 1 ? (joseph(size - 1, step) + step) % size : 0;
}

bool solve() {
    int size, step;
    cin >> size >> step;

    if (!size && !step)
        return 0;

    cout << size << " " << step << " " << joseph(size, step) + 1 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}