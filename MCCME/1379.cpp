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

    int h, w, queryCount;
    cin >> h >> w >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int size;
        cin >> size;

        if (h % size == 0 && (w - 2) % size == 0 ||
            (h - 2) % size == 0 && w % size == 0 ||
            (h - 1) % size == 0 && (w - 1) % size == 0 ||
            (h - 1) % size == 0 && w % size == 0 && (w - 2) % size == 0 ||
            h % size == 0 && (h - 2) % size == 0 && (w - 1) % size == 0)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}