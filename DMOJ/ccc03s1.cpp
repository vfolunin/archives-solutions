#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unordered_map<int, int> to = {
        { 9, 34 }, { 40, 64 }, { 54, 19 }, { 67, 86 }, { 90, 48 }, { 99, 77 }
    };
    int pos = 1;

    while (1) {
        int toss;
        cin >> toss;

        if (!toss) {
            cout << "You Quit!\n";
            break;
        }

        if (pos + toss <= 100) {
            pos += toss;
            if (to.count(pos))
                pos = to[pos];
        }

        cout << "You are now on square " << pos << "\n";

        if (pos == 100) {
            cout << "You Win!\n";
            break;
        }
    }
}