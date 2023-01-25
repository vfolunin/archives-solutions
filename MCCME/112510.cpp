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

    map<string, int> count;
    string word;

    while (cin >> word)
        count[word]++;

    for (auto &[word, count] : count)
        cout << word << " " << count << "\n";
}