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

    string cypher;
    cin >> cypher;

    cypher.pop_back();

    string word(cypher.size(), ' ');
    for (int i = 0, l = 0, r = cypher.size() - 1; i < cypher.size(); i++) {
        if (i % 2 == 0)
            word[l++] = cypher[i];
        else
            word[r--] = cypher[i];
    }

    cout << word;
}