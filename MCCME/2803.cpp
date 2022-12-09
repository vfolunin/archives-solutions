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

    for (int spaceCount = size - 1, starCount = 1; spaceCount >= 0; spaceCount--, starCount += 2)
        cout << string(spaceCount, ' ') << string(starCount, '*') << "\n";
}