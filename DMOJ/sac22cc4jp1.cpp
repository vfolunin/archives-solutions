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

    string s;
    cin >> s;

    string vowels = "aeiouy";
    int vowelCount = 0;
    for (char c : s)
        vowelCount += vowels.find(c) != -1;

    cout << (vowelCount >= 2 ? "good" : "bad");
}