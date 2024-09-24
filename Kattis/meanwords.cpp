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
    int width = 0;
    for (string &s : a) {
        cin >> s;
        width = max<int>(width, s.size());
    }

    for (int i = 0; i < width; i++) {
        int num = 0, den = 0;
        for (string &s : a) {
            if (i < s.size()) {
                num += s[i];
                den++;
            }
        }
        cout << (char)(num / den);
    }
}