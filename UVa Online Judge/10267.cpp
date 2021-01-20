#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

void bfs(vector<string> &img, int y, int x, char c) {
    char initialC = img[y][x];
    queue<int> q;
    q.push(y);
    q.push(x);

    img[y][x] = ' ';

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ty = y + dy[d], tx = x + dx[d];
            if (0 <= ty && ty < img.size() && 0 <= tx && tx <= img[0].size() && img[ty][tx] == initialC) {
                img[ty][tx] = ' ';
                q.push(ty);
                q.push(tx);
            }
        }
    }

    for (string &row : img)
        replace(row.begin(), row.end(), ' ', c);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> img;

    while (1) {
        string op;
        cin >> op;

        if (op == "I") {

            int w, h;
            cin >> w >> h;

            img.assign(h, string(w, 'O'));

        } else if (op == "C") {

            for (string &row : img)
                fill(row.begin(), row.end(), 'O');

        } else if (op == "L") {

            int x, y;
            char c;
            cin >> x >> y >> c;
            y--;
            x--;

            img[y][x] = c;

        } else if (op == "V") {

            int x, y1, y2;
            char c;
            cin >> x >> y1 >> y2 >> c;
            y1--;
            y2--;
            x--;
            if (y1 > y2)
                swap(y1, y2);

            for (int y = y1; y <= y2; y++)
                img[y][x] = c;

        } else if (op == "H") {

            int x1, x2, y;
            char c;
            cin >> x1 >> x2 >> y >> c;
            y--;
            x1--;
            x2--;
            if (x1 > x2)
                swap(x1, x2);

            for (int x = x1; x <= x2; x++)
                img[y][x] = c;

        } else if (op == "K") {

            int x1, x2, y1, y2;
            char c;
            cin >> x1 >> y1 >> x2 >> y2 >> c;
            y1--;
            y2--;
            x1--;
            x2--;
            if (y1 > y2)
                swap(y1, y2);
            if (x1 > x2)
                swap(x1, x2);

            for (int y = y1; y <= y2; y++)
                for (int x = x1; x <= x2; x++)
                    img[y][x] = c;

        } else if (op == "F") {

            int x, y;
            char c;
            cin >> x >> y >> c;
            y--;
            x--;

            bfs(img, y, x, c);

        } else if (op == "S") {

            string name;
            cin >> name;

            cout << name << "\n";
            for (string &row : img)
                cout << row << "\n";

        } else if (op == "X") {

            break;

        } else {

            string line;
            getline(cin, line);

        }
    }
}