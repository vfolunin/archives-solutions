#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    string scale, tone;
    if (!(cin >> scale >> tone))
        return 0;

    cout << "Case " << test << ": ";
    if (scale.size() == 1) {
        cout << "UNIQUE\n";
    } else {
        static string noteA = "A# Bb C# Db D# Eb F# Gb G# Ab";
        static string noteB = "Bb A# Db C# Eb D# Gb F# Ab G#";
        cout << noteB.substr(noteA.find(scale), 2) << " " << tone << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}