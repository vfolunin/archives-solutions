#include <cstdio>
#include <vector>
#include <map>
using namespace std;

struct Operation {
    char type[5];
    int x1, x2, y1, y2, z1, z2;
};

struct Compressor {
    map<int, int> m;
    vector<int> v;

    void addCoord(int coord) {
        m[coord];
    }

    void preprocess() {
        for (auto &[coord, compressed] : m) {
            v.push_back(coord);
            compressed = v.size() - 1;
        }
    }

    int compress(int coord) {
        return m[coord];
    }

    int decompress(int compressed) {
        return v[compressed];
    }

    int size() {
        return v.size();
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<Operation> ops;
    Compressor cx, cy, cz;

    while (1) {
        Operation op;
        if (scanf("%s x=%d..%d,y=%d..%d,z=%d..%d",
            op.type, &op.x1, &op.x2, &op.y1, &op.y2, &op.z1, &op.z2) == EOF)
            break;
        ops.push_back(op);
        cx.addCoord(op.x1);
        cx.addCoord(op.x2 + 1);
        cy.addCoord(op.y1);
        cy.addCoord(op.y2 + 1);
        cz.addCoord(op.z1);
        cz.addCoord(op.z2 + 1);
    }

    cx.preprocess();
    cy.preprocess();
    cz.preprocess();

    vector<vector<vector<bool>>> state(cx.size(), vector<vector<bool>>(cy.size(), vector<bool>(cz.size())));

    for (Operation &op : ops) {
        int x1 = cx.compress(op.x1);
        int x2 = cx.compress(op.x2 + 1);
        int y1 = cy.compress(op.y1);
        int y2 = cy.compress(op.y2 + 1);
        int z1 = cz.compress(op.z1);
        int z2 = cz.compress(op.z2 + 1);

        for (int x = x1; x < x2; x++)
            for (int y = y1; y < y2; y++)
                for (int z = z1; z < z2; z++)
                    state[x][y][z] = op.type[1] == 'n';
    }

    long long res = 0;
    for (int x = 0; x + 1 < state.size(); x++) {
        for (int y = 0; y + 1 < state[0].size(); y++) {
            for (int z = 0; z + 1 < state[0][0].size(); z++) {
                if (state[x][y][z]) {
                    long long dx = cx.decompress(x + 1) - cx.decompress(x);
                    long long dy = cy.decompress(y + 1) - cy.decompress(y);
                    long long dz = cz.decompress(z + 1) - cz.decompress(z);
                    res += dx * dy * dz;
                }
            }
        }
    }

    printf("%lld", res);
}