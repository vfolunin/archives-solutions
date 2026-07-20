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

    int aa, ab, ba, bb;
    cin >> aa >> ab >> ba >> bb;

    cout << (aa == bb && (!ba || aa));
}