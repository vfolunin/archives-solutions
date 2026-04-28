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

    int size, index, delta;
    cin >> size >> index >> delta;

    cout << ((index - 1 + delta) % size + size) % size + 1;
}