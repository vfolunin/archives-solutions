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

    vector<string> a;

    for (string s; getline(cin, s); ) {
        int from = 0;
        for (int i = 0; 1; i++) {
            int to = s.find('|', from);

            if (a.size() <= i)
                a.emplace_back();
            a[i] += s.substr(from, to);

            if (to == -1)
                break;
            from = to + 1;
        }
    }

    for (int i = 0; i < a.size(); i++)
        cout << (i ? " " : "") << a[i];
}