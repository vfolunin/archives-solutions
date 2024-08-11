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

    int size, index;
    cin >> size >> index;
    index--;
    
    int y = index / size;
    int x = index % size;

    int res = 1 + max(y, size - 1 - y) + max(x, size - 1 - x);

    cout << res / 60 << " " << res % 60;
}