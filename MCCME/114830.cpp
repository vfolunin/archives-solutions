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

    int l = 0, r = 0;
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        l = max({ l, stoi(s), stoi("1" + string(s.size() - 1, '0')) });
        r = stoi(string(s.size(), '9'));
    }

    cout << l << "\n" << r;
}