#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int editDistance(string &a, string &b) {
    vector<vector<int>> dist(a.size() + 1, vector<int>(b.size() + 1));

    for (int na = 1; na <= a.size(); na++)
        dist[na][0] = 7 * na;
    for (int nb = 1; nb <= b.size(); nb++)
        dist[0][nb] = 7 * nb;

    for (int na = 1; na <= a.size(); na++) {
        for (int nb = 1; nb <= b.size(); nb++) {
            if (a[na - 1] == b[nb - 1])
                dist[na][nb] = dist[na - 1][nb - 1] - 5;
            else
                dist[na][nb] = min(dist[na - 1][nb - 1] + 4, min(dist[na - 1][nb], dist[na][nb - 1]) + 7);
        }
    }

    return dist[a.size()][b.size()];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string query;
    cin >> query >> query;

    int bestDist = 1e9;
    vector<string> bestSequences;

    while (1) {
        string sequence;
        if (!(cin >> sequence >> sequence))
            break;

        int dist = editDistance(query, sequence);

        if (bestDist > dist) {
            bestDist = dist;
            bestSequences.clear();
        }
        if (bestDist == dist)
            bestSequences.push_back(sequence);
    }

    cout << "The query sequence is:\n" << query << "\n\n";
    cout << "The most similar sequences are:\n";
    for (string &sequence : bestSequences) {
        cout << "\n" << sequence << "\n";
        cout << "The similarity score is: " << -bestDist << "\n";
    }
}