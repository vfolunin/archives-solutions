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

    string text, word;
    cin >> text >> word;

    int res = 0, wi = 0;
    for (char c : text) {
        if (word[wi] == c) {
            wi++;
            if (wi == word.size()) {
                wi = 0;
                res++;
            }
        }
    }

    cout << res;
}