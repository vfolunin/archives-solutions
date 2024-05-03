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

    set<int> values;
    for (int a = 1; a * a < n; a++)
        for (int b = a + 1; a * a + b * b <= n; b++)
            values.insert(a * a + b * b);

    for (int value : values)
        cout << value << " ";
}