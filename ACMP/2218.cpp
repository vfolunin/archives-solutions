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

    int a, b;
    cin >> a >> b;

    int boxCount = (a + b) / 3;

    if ((a + b) % 3 || min(a, b) < boxCount)
        cout << -1;
    else
        cout << a - boxCount << " " << b - boxCount;
}