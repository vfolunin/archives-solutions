#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int pairCount, queryCount;
    cin >> pairCount >> queryCount;

    unordered_map<string, string> partner;
    list<string> line;
    unordered_map<string, list<string>::iterator> pos;
    
    for (int i = 0; i < pairCount; i++) {
        string a, b;
        cin >> a >> b;

        partner[a] = b;
        partner[b] = a;

        pos[a] = line.insert(line.end(), a);
        pos[b] = line.insert(line.end(), b);
    }

    string queries;
    cin >> queries;

    list<string>::iterator cur = line.begin();
    for (char query : queries) {
        if (query == 'F') {
            cur--;
        } else if (query == 'B') {
            cur++;
        } else if (query == 'R') {
            string name = *cur;
            
            cur = line.erase(cur);
            if (cur == line.end())
                cur = line.begin();

            pos[name] = line.insert(line.end(), name);
        } else if (query == 'C') {
            string name = *cur;

            cur = line.erase(cur);
            if (cur == line.end())
                cur = line.begin();

            pos[name] = line.insert(next(pos[partner[name]]), name);
        } else {
            cout << partner[*cur] << "\n";
        }
    }

    cout << "\n";

    for (string name : line)
        cout << name << "\n";
}