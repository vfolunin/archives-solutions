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

    int size;
    string s;
    cin >> size >> s;

    int l = 1, r = size;
    for (char c : s) {
        if (c == '<')
            cout << l++ << " ";
        else
            cout << r-- << " ";
    }

    cout << l;
}