#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a, b;
    cin >> a >> b;

    unordered_set<string> colors = { "red", "green", "white" };

    cout << (colors.count(a) && colors.count(b) ? "Jingle Bells" : "Boring...");
}