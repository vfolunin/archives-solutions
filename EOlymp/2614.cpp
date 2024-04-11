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

    int n;
    cin >> n;

    for (int i = 0, value = 1; i < n; value++)
        for (int j = 0; i < n && j < value; i++, j++)
            cout << value << " ";
}