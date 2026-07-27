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

    int size, alphabetSize;
    string s;
    cin >> size >> alphabetSize >> s;

    vector<int> count(alphabetSize);
    for (char c : s)
        count[c - 'A']++;

    cout << *min_element(count.begin(), count.end()) * alphabetSize;
}