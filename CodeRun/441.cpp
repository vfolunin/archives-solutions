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

    int nameCount;
    cin >> nameCount;

    map<string, int> score;
    for (int i = 0; i < nameCount; i++) {
        string name;
        cin >> name;

        score[name];
    }

    int changeCount;
    cin >> changeCount;

    int prevA = 0, prevB = 0;
    for (int i = 0; i < changeCount; i++) {
        int a, b;
        char colon;
        string name;
        cin >> a >> colon >> b >> name;

        score[name] += a + b - prevA - prevB;
        prevA = a;
        prevB = b;
    }

    string resName = score.begin()->first;
    for (auto &[name, nameScore] : score)
        if (score[resName] <= nameScore)
            resName = name;

    cout << resName << " " << score[resName];
}