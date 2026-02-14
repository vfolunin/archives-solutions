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

    int tailSize, cypherSize;
    string tail, cypher;
    cin >> tailSize >> cypherSize >> tail >> cypher;

    string text = string(cypherSize - tailSize, '?') + tail;
    for (int i = cypherSize - tailSize - 1; i >= 0; i--)
        text[i] = 'a' + (cypher[i + tailSize] - text[i + tailSize] + 26) % 26;

    cout << text;
}