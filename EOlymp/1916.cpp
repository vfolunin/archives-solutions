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
    int vowelCount = 0;
    int consonantCount = 0;
    for (char c : s) {
        if (vowels.find(c) != -1)
            vowelCount++;
        else if (c != 'y')
            consonantCount++;
    }

    int res = 0;
    while (vowelCount + res <= consonantCount - res)
        res++;

    cout << res;
}