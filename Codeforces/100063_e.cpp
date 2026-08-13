#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("necklace.in", "r", stdin);
    freopen("necklace.out", "w", stdout);

    int size;
    cin >> size;

    if (size < 6) {
        cout << -1;
        return 0;
    }

    cout << "1 1 0 1 ";
    for (int i = 4; i < size; i++)
        cout << "0 ";
}