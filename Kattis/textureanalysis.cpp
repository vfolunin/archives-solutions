#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    string line;
    cin >> line;

    if (line == "END")
        return 0;

    int dist, prev = 0;
    for (int i = 1; i < line.size(); i++) {
        if (line[i] != '*')
            continue;
        if (prev == 0) {
            dist = i - prev;
        } else if (i - prev != dist) {
            cout << test << " NOT EVEN\n";
            return 1;
        }
        prev = i;
    }

    cout << test << " EVEN\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}