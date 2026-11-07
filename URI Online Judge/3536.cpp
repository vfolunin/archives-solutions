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

    int size;
    cin >> size;

    map<string, int> count;
    for (string s : { "arco", "escudo", "espada", "pocao" })
        count[s];

    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        count[s]++;
    }

    for (auto &[s, count] : count)
        cout << s << " " << count << "\n";
}