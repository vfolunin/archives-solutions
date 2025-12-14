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

    string a, b;
    cin >> a >> b;

    set<string> values = { "BLUE", "RED", "WHITE" };
    values.erase(a);
    values.erase(b);

    cout << *values.begin();
}