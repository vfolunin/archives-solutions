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

    string word;
    cin >> word;

    map<char, int> letterCount;
    for (char letter : word)
        letterCount[letter]++;

    int oddCount = 0;
    for (auto &[letter, count] : letterCount)
        oddCount += count % 2;

    cout << max(0, oddCount - 1);
}