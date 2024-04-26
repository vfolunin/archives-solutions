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

    int index;
    cin >> index;

    vector<int> a = {
        5 + 10 + 15 + 20 + 25 + 30 + 35 + 40 + 45 + 50,
        1 + 4 + 7 + 10 + 13 + 16 + 19 + 22 + 25 + 28,
        4 + 8 + 12 + 16 + 20 + 24 + 28 + 32 + 36 + 40,
        1 + 3 + 5 + 7 + 9 + 11 + 13 + 15 + 17 + 19,
        2 + 4 + 6 + 8 + 10 + 12 + 14 + 16 + 18 + 20,
        1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10
    };

    cout << a[index - 1];
}