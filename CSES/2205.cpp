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

    int n;
    cin >> n;

    vector<string> gray = { "0", "1" };
    for (int i = 1; i < n; i++) {
        auto rev = gray;
        gray.insert(gray.end(), rev.rbegin(), rev.rend());
        for (int i = 0; i < gray.size() / 2; i++)
            gray[i] += "0";
        for (int i = gray.size() / 2; i < gray.size(); i++)
            gray[i] += "1";
    }

    for (string &code : gray) {
        reverse(code.begin(), code.end());
        cout << code << "\n";
    }
}