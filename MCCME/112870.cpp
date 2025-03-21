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

    vector<string> a(size);
    int dot = 0;

    for (string &s : a) {
        cin >> s;
        dot = max<int>(dot, s.find('.'));
    }

    for (string &s : a)
        cout << string(dot - s.find('.'), '#') << s << "\n";
}