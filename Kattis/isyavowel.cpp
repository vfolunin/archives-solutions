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

    string vowels = "aeiou";
    int vowelCount = 0, yCount = 0;

    for (char c : s) {
        vowelCount += vowels.find(c) != -1;
        yCount += c == 'y';
    }

    cout << vowelCount << " " << vowelCount + yCount;
}