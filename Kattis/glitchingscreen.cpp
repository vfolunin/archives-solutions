#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> read(int height) {
    vector<string> a(height);
    for (string &s : a)
        cin >> s;
    return a;
}

bool isValid(const vector<string> &a, const vector<string> &b) {
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < a[0].size(); x++)
            if (a[y][x] == '.' && b[y][x] == 'x')
                return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int height, width, count;
    cin >> height >> width >> count;

    vector<vector<string>> a(count);
    for (vector<string> &a : a)
        a = read(height);

    vector<string> b = read(height);

    int validCount = 0;
    for (vector<string> &a : a)
        validCount += isValid(a, b);

    cout << (validCount == 1 ? "yes" : "no");
}