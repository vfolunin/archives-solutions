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

    int size;
    cin >> size;

    unordered_set<string> words = { "he", "her", "him", "she" };
    int res = 0;

    for (int i = 0; i < size; i++) {
        string word;
        cin >> word;

        res += words.count(word);
    }

    cout << res;
}