#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int size;
    cin >> size;

    cout << "Case #" << test << ": ";
    for (int i = 0; i < size; i++)
        cout << (i ? "koko" : "Koko") << (i + 1 < size ? "," : ".\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}