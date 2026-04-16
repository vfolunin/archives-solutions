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

    if (size % 2) {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < size; i += 2)
        cout << i + 2 << " " << i + 1 << " ";
}