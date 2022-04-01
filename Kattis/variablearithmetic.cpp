#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> split(string &line, char delimiter) {
    vector<string> words;
    string word;

    for (char c : line) {
        if (c != delimiter) {
            word += c;
        } else {
            words.push_back(word);
            word.clear();
        }
    }
    words.push_back(word);

    return words;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    map<string, int> value;

    while (1) {
        string line;
        getline(cin, line);

        if (line == "0")
            break;

        vector<string> tokens = split(line, ' ');
        
        if (tokens.size() > 1 && tokens[1] == "=") {
            value[tokens[0]] = stoi(tokens[2]);
        } else {
            int sum = 0;
            vector<string> undefined;

            for (int i = 0; i < tokens.size(); i += 2) {
                if (isdigit(tokens[i][0]))
                    sum += stoi(tokens[i]);
                else if (value.count(tokens[i]))
                    sum += value[tokens[i]];
                else
                    undefined.push_back(tokens[i]);
            }

            if (sum) {
                cout << sum;
                if (!undefined.empty())
                    cout << " + ";
            }
            for (int i = 0; i < undefined.size(); i++) {
                cout << undefined[i];
                if (i + 1 < undefined.size())
                    cout << " + ";
            }
            cout << "\n";
        }
    }
}