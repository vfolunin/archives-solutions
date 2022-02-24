#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> readWords() {
    string line;
    getline(cin, line);

    vector<string> words;
    stringstream ss(line);
    string word;
    while (ss >> word)
        words.push_back(word);

    return words;
}

bool solve(int test) {
    int animalCount;
    cin >> animalCount;

    if (!animalCount)
        return 0;

    cin.ignore();

    map<string, int> zoo;
    for (int i = 0; i < animalCount; i++) {
        string animal = readWords().back();
        for (char &c : animal)
            c = tolower(c);
        zoo[animal]++;
    }

    cout << "List " << test << ":\n";
    for (auto &[animal, count] : zoo)
        cout << animal << " | " << count << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}