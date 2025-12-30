struct Compressor {
    map<int, int> compressed;
    vector<int> decompressed;
    
    void insert(int value) {
        compressed[value];
    }
    
    void prepare() {
        for (auto &[value, compressedValue] : compressed) {
            compressedValue = decompressed.size();
            decompressed.push_back(value);
        }
    }
    
    int size() {
        return compressed.size();
    }
    
    int compress(int value) {
        return compressed[value];
    }
    
    int decompress(int value) {
        return decompressed[value];
    }
};

class Solution {
    void updateCost(vector<vector<int>> &cost, vector<vector<int>> &a) {
        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a[0].size(); x++) {
                if (y)
                    cost[y][x] = min(cost[y][x], cost[y - 1][x] + a[y][x]);
                if (x)
                    cost[y][x] = min(cost[y][x], cost[y][x - 1] + a[y][x]);
            }
        }
    }

public:
    int minCost(vector<vector<int>> &a, int jumpLimit) {
        Compressor compressor;
        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a[0].size(); x++)
                compressor.insert(a[y][x]);
        compressor.prepare();

        vector<vector<int>> cost(a.size(), vector<int>(a[0].size(), 1e9));
        cost[0][0] = 0;
        updateCost(cost, a);

        for (int jumps = 0; jumps < jumpLimit; jumps++) {
            vector<int> jumpCost(compressor.size(), 1e9);
            for (int y = 0; y < a.size(); y++) {
                for (int x = 0; x < a[0].size(); x++) {
                    int i = compressor.compress(a[y][x]);
                    jumpCost[i] = min(jumpCost[i], cost[y][x]);
                }
            }

            for (int i = (int)jumpCost.size() - 2; i >= 0; i--)
                jumpCost[i] = min(jumpCost[i], jumpCost[i + 1]);
            
            for (int y = 0; y < a.size(); y++)
                for (int x = 0; x < a[0].size(); x++)
                    cost[y][x] = min(cost[y][x], jumpCost[compressor.compress(a[y][x])]);
            
            updateCost(cost, a);
        }

        return cost.back().back();
    }
};