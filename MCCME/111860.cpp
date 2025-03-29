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

    int up, down;
    cin >> up >> down;

    for (int i = down + 1; i >= 1; i--)
        cout << i << " ";
    for (int i = 2; i <= up + 1; i++)
        cout << down + i << " ";
}