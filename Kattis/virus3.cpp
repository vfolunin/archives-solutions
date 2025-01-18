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

    int i = 0;
    for (char c : b)
        if (i < a.size() && a[i] == c)
            i++;

    cout << (i == a.size() ? "Ja" : "Nej");
}