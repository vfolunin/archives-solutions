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

    string letters, cypher;
    cin >> letters >> cypher;

    for (char &c : cypher)
        c = 'a' + letters.find(c);

    cout << cypher << "\n";
}