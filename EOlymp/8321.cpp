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

    vector<string> a = {
        "1 2 3 4 5 6 7 8 9 10",
        "0 1 2 3 4 5 6 7 8 9",
        "1 3 5 7 9 11 13 15 17 19",
        "2 4 6 8 10 12 14 16 18 20",
        "9 8 7 6 5 4 3 2 1 0",
        "5 10 15 20 25 30 35 40 45 50"
    };

    cout << a[index - 1];
}