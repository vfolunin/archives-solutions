#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int size;
    cin >> size;

    if (!size)
        return 0;

    if (test)
        cout << "\n";

    for (int spaces = size - 1, stars = 1; spaces > 0; spaces--, stars += 2)
        cout << string(spaces, ' ') << string(stars, '*') << "\n";
    for (int spaces = 0, stars = size * 2 - 1; stars > 0; spaces++, stars -= 2)
        cout << string(spaces, ' ') << string(stars, '*') << "\n";

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}