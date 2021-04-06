#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int length;
    cin >> length;

    static string vowels = "AUEOI";
    static string consonants = "JSBKTCLDMVNWFXGPYHQZR";

    string part[2];
    int vowelI = 0, vowelCount = 0;
    int consonantI = 0, consonantCount = 0;

    for (int i = 0; i < length; i++) {
        if (i % 2 == 0) {
            part[i % 2] += vowels[vowelI];
            vowelCount++;
            if (vowelCount == 21) {
                vowelI++;
                vowelCount = 0;
            }
        } else {
            part[i % 2] += consonants[consonantI];
            consonantCount++;
            if (consonantCount == 5) {
                consonantI++;
                consonantCount = 0;
            }
        }
    }

    sort(part[0].begin(), part[0].end());
    sort(part[1].begin(), part[1].end());

    string name(length, ' ');
    for (int i = 0; i < part[0].size(); i++)
        name[2 * i] = part[0][i];
    for (int i = 0; i < part[1].size(); i++)
        name[2 * i + 1] = part[1][i];

    cout << "Case " << test << ": " << name << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}