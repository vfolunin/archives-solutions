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

    int view1, load1, len;
    cin >> view1 >> load1 >> len;

    int load = view1 * len;
    int loadTime = (load + load1 - 1) / load1;

    cout << loadTime - len;
}