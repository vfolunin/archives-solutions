#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> readInts() {
    vector<int> res;
    string line;
    cin.ignore();
    while (getline(cin, line)) {
        if (line.empty())
            break;
        res.push_back(stoi(line));
    }
    return res;
}

void apply(vector<int> &order, vector<int> &shuffle) {
    vector<int> res;
    for (int i = 0; i < shuffle.size(); i++)
        res.push_back(order[shuffle[i]]);
    order.swap(res);
}

void printCard(int card) {
    static string suit[] = { "Clubs", "Diamonds", "Hearts", "Spades" };
    static string value[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
    cout << value[card % 13] << " of " << suit[card / 13] << "\n";
}

void solve(int test) {
    int shuffleCount;
    cin >> shuffleCount;

    vector<vector<int>> shuffles(shuffleCount, vector<int>(52));
    for (vector<int> &shuffle : shuffles) {
        for (int &x : shuffle) {
            cin >> x;
            x--;
        }
    }

    vector<int> order;
    for (int i = 0; i < 52; i++)
        order.push_back(i);

    vector<int> shuffleIds = readInts();
    for (int id : shuffleIds)
        apply(order, shuffles[id - 1]);

    if (test)
        cout << "\n";
    for (int card : order)
        printCard(card);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}