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
 
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
    }

    cout << x1 << " " << y2 << " " << x2 << " " << y1;
}