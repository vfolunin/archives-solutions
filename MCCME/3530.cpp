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

    int from = 1;
    for (int i = 0; i < n; i++)
        from *= 10;

    int to = from / 10;

    for (int i = from - 1; i >= to; i -= 2)
        cout << i << " ";
}