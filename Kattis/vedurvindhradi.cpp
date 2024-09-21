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

    double value;
    cin >> value;

    vector<string> name = { "Logn", "Andvari", "Kul", "Gola", "Stinningsgola", "Kaldi", "Stinningskaldi", "Allhvass vindur", "Hvassvidri", "Stormur", "Rok", "Ofsavedur", "Farvidri" };
    vector<double> from = { 0, 0.3, 1.6, 3.4, 5.5, 8.0, 10.8, 13.9, 17.2, 20.8, 24.5, 28.5, 32.7 };

    cout << name[upper_bound(from.begin(), from.end(), value) - from.begin() - 1];
}