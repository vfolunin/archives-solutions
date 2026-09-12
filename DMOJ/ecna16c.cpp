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

    string cypher, key;
    cin >> cypher >> key;

    for (int i = 0; i < cypher.size(); i++) {
        char c = cypher[i] - 'A';
        c += 26 - (key[i] - 'A');
        c = c % 26 + 'A';
        key += c;
        cout << c;
    }
}