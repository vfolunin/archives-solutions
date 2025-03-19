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

    int a, b, c, d;
    char colon;
    cin >> a >> colon >> b >> c >> colon >> d;

    cout << (d <= b && c <= a ? "YES" : "NO");
}