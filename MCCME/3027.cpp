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

    for (int dotCount = size - 1, starCount = 1; dotCount >= 0; dotCount--, starCount += 2)
        cout << string(dotCount, '.') << string(starCount, '*') << string(dotCount, '.') << "\n";
}