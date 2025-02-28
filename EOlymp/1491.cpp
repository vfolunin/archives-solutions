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

    if (size < 6) {
        cout << -1;
        return 0;
    }

    cout << "1 1 0 1 ";
    for (int i = 4; i < size; i++)
        cout << "0 ";
}