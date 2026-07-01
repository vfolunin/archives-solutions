#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, resSize, limit;
    cin >> size >> resSize >> limit;
    cin.ignore();

    vector<string> subjects(size);
    for (string &subject : subjects)
        getline(cin, subject);

    vector<int> ids(size);
    for (int &id : ids)
        cin >> id;

    unordered_map<string, int> count;
    for (int i = 0, resI = 0; i < size && resI < resSize; i++) {
        if (count[subjects[i]] < limit) {
            count[subjects[i]]++;
            resI++;

            cout << subjects[i] << " #" << ids[i] << "\n";
        }
    }
}