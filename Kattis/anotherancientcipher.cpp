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
        int letter = cypher[i] - 'a';
        int delta = key[i % key.size()] - 'a';

        int decoded0 = (letter - delta + 26) % 26;
        int decoded1 = (letter + delta) % 26;

        cout << (char)((decoded1 % 2 ? decoded1 : decoded0) + 'a');
    }
}