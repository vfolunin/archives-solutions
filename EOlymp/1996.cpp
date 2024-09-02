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

    int count, capacity;
    cin >> count >> capacity;

    if (count <= capacity)
        cout << 2;
    else
        cout << (2 * count + capacity - 1) / capacity;
}