#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int h, w;
    if (!(cin >> h >> w))
        return 0;

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    int counter = 0;
    vector<int> across, down;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (!isalpha(a[y][x]) || y && x && isalpha(a[y - 1][x]) && isalpha(a[y][x - 1]))
                continue;
            counter++;
            if (!y || !isalpha(a[y - 1][x])) {
                down.push_back(counter);
                down.push_back(y);
                down.push_back(x);
            }
            if (!x || !isalpha(a[y][x - 1])) {
                across.push_back(counter);
                across.push_back(y);
                across.push_back(x);
            }
        }
    }

    if (test > 1)
        cout << "\n";
    cout << "puzzle #" << test << ":\n";
    cout << "Across\n";
    for (int i = 0; i < across.size(); i += 3) {
        cout << setw(3) << across[i] << ".";
        for (int y = across[i + 1], x = across[i + 2]; x < w && isalpha(a[y][x]); x++)
            cout << a[y][x];
        cout << "\n";
    }
    cout << "Down\n";
    for (int i = 0; i < down.size(); i += 3) {
        cout << setw(3) << down[i] << ".";
        for (int y = down[i + 1], x = down[i + 2]; y < h && isalpha(a[y][x]); y++)
            cout << a[y][x];
        cout << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}