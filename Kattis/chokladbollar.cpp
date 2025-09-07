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

    int size, a, b;
    cin >> size >> a >> b;

    if (a < b)
        swap(a, b);

    int count = a + b;
    int ratio = count / size;
    int remainder = count % size;

    int res = 0;
    if (a > ratio + (remainder > 0))
        res += a - (ratio + (remainder > 0));
    if (b > ratio + (remainder > 1))
        res += b - (ratio + (remainder > 1));

    cout << res;
}