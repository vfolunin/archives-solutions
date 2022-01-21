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
        int shift = key[i] - 'A';
        if (i % 2 == 0)
            shift *= -1;

        cypher[i] -= 'A';
        cypher[i] = (cypher[i] + shift + 26) % 26;
        cypher[i] += 'A';
    }

    cout << cypher;
}