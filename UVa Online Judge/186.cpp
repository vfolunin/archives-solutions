#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> split(string &line) {
    vector<string> words;
    string word;
    for (char c : line) {
        if (c != ',') {
            word += c;
        } else {
            words.push_back(word);
            word.clear();
        }
    }
    words.push_back(word);
    return words;
}

void print(const string &from, const string &to, const string &route, const string &miles) {
    cout << setw(20) << left << from << " ";
    cout << setw(20) << left << to << " ";
    cout << setw(10) << left << route << " ";
    cout << setw(5) << right << miles << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    map<string, int> vertexId;
    vector<string> vertexName;

    vector<vector<int>> dist(100, vector<int>(100, 1e9));
    vector<vector<int>> next(100, vector<int>(100, -1));
    vector<vector<string>> name(100, vector<string>(100));
    for (int v = 0; v < 100; v++)
        dist[v][v] = 0;

    while (1) {
        string line;
        getline(cin, line);

        if (line.empty())
            break;

        vector<string> tokens = split(line);

        if (!vertexId.count(tokens[0])) {
            vertexId[tokens[0]] = vertexId.size();
            vertexName.push_back(tokens[0]);
        }
        if (!vertexId.count(tokens[1])) {
            vertexId[tokens[1]] = vertexId.size();
            vertexName.push_back(tokens[1]);
        }

        int a = vertexId[tokens[0]], b = vertexId[tokens[1]], w = stoi(tokens[3]);
        if (dist[a][b] > w) {
            dist[a][b] = w;
            next[a][b] = b;
            name[a][b] = tokens[2];
        }
        if (dist[b][a] > w) {
            dist[b][a] = w;
            next[b][a] = a;
            name[b][a] = tokens[2];
        }
    }

    for (int v = 0; v < vertexId.size(); v++) {
        for (int a = 0; a < vertexId.size(); a++) {
            for (int b = 0; b < vertexId.size(); b++) {
                if (dist[a][b] > dist[a][v] + dist[v][b]) {
                    dist[a][b] = dist[a][v] + dist[v][b];
                    next[a][b] = (a != v ? next[a][v] : next[v][b]);
                }
            }
        }
    }

    while (1) {
        string line;
        getline(cin, line);

        if (line.empty())
            break;

        vector<string> tokens = split(line);
        int total = 0;

        cout << "\n\n";
        print("From", "To", "Route", "Miles");
        print(string(20, '-'), string(20, '-'), string(10, '-'), string(5, '-'));
        for (int a = vertexId[tokens[0]], b = vertexId[tokens[1]]; a != b; a = next[a][b]) {
            print(vertexName[a], vertexName[next[a][b]], name[a][next[a][b]], to_string(dist[a][next[a][b]]));
            total += dist[a][next[a][b]];
        }
        print("", "", "", string(5, '-'));
        print("", "", "Total", to_string(total));
    }
}