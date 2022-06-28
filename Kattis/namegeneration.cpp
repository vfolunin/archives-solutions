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

    int n;
    cin >> n;

    string vowels = "aeiou";
    string consonants = "bcdfghjklmnpqrstvwxyz";

    for (int i = 0; i < n; i++) {
        for (int index = i, j = 0; j < 3; j++) {
            cout << consonants[index % consonants.size()];
            index /= consonants.size();
            cout << vowels[index % vowels.size()];
            index /= vowels.size();
        }
        cout << "\n";
    }
}