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

    int pageCount;
    cin >> pageCount;

    for (int i = 1, l = 1, r = pageCount + (4 - pageCount % 4) % 4; l < r; i++, l += 2, r -= 2) {
        cout << i << " 1 " << (r <= pageCount ? r : 0) << " " << (l <= pageCount ? l : 0) << "\n";
        cout << i << " 2 " << (l + 1 <= pageCount ? l + 1 : 0) << " " << (r - 1 <= pageCount ? r - 1 : 0) << "\n";
    }
}