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

    map<string, int> score;
    set<string> killed;
    
    string a, b;
    while (cin >> a >> b) {
        score[a]++;
        killed.insert(b);
    }

    cout << "HALL OF MURDERERS\n";
    for (auto &[name, score] : score)
        if (!killed.count(name))
            cout << name << " " << score << "\n";
}