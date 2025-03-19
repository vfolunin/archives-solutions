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

    for (int star = 1, space = size - 1; space >= 0; star += 2, space--)
        cout << string(space, ' ') << string(star, '*') << string(space * 2 + 1, ' ') << string(star, '*') << string(space, ' ') << "\n";
}