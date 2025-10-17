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

    cout << "A long time ago in a galaxy";
    for (int i = 0; i < size - 1; i++)
        cout << " far,";
    cout << " far away...";
}