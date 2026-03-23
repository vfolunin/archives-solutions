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

    string text;
    cin >> text;

    string name = "PER";
    int res = 0;
    for (int i = 0; i < text.size(); i++)
        res += text[i] != name[i % name.size()];

    cout << res;
}