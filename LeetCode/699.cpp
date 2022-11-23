struct Compressor {
    map<int, int> c;
    vector<int> d;
    
    void add(int x) {
        c[x];
    }
    
    void prepare() {
        for (auto &[coord, compressed] : c) {
            compressed = d.size();
            d.push_back(coord);
        }
    }
    
    int size() {
        return d.size();
    }
    
    int compress(int x) {
        return c[x];
    }
    
    int decompress(int x) {
        return d[x];
    }
};

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>> &squares) {
        Compressor compressor;
        for (vector<int> &square : squares) {
            compressor.add(square[0]);
            compressor.add(square[0] + square[1] - 1);
        }
        compressor.prepare();
        
        vector<int> height(compressor.size()), res(squares.size());
        for (int i = 0; i < squares.size(); i++) {
            int l = compressor.compress(squares[i][0]);
            int r = compressor.compress(squares[i][0] + squares[i][1] - 1);
            int h = *max_element(height.begin() + l, height.begin() + r + 1) + squares[i][1];
            fill(height.begin() + l, height.begin() + r + 1, h);
            res[i] = *max_element(height.begin(), height.end());
        }
        return res;
    }
};