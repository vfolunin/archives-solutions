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
    cin >> size;

    string s;
    for (int i = 0; i < size; i++) {
        char c;
        cin >> c;

        if (s.empty() || s.back() != c)
            s += c;
    }

    cout << s.size() + 1;
}