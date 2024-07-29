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

    int size, oneCount;
    cin >> size >> oneCount;

    string s(size, '0');
    fill(s.end() - oneCount, s.end(), '1');

    do {
        for (char c : s)
            cout << c << " ";
        cout << "\n";
    } while (next_permutation(s.begin(), s.end()));
}