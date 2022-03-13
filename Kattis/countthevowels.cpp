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

    string line;
    getline(cin, line);

    string vowels = "aeiou";
    int vowelCount = 0;

    for (char c : line)
        vowelCount += vowels.find(tolower(c)) != -1;

    cout << vowelCount;
}