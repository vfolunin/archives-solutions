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

    string word = "love";
    vector<long long> count(word.size() + 1);
    count[0] = 1;

    for (char c : s)
        if (int i = word.find(c); i != -1)
            count[i + 1] += count[i];

    cout << count.back();
}