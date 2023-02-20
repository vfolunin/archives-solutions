class Excel {
    vector<vector<int>> values;
    vector<vector<vector<pair<int, int>>>> formulas;

    int getValue(int y, int x) {
        if (values[y][x] != -1e9)
            return values[y][x];
        
        int sum = 0;
        for (auto &[cy, cx] : formulas[y][x])
            sum += getValue(cy, cx);
        return sum;
    }

public:
    Excel(int h, char w) :
        values(h, vector<int>(w, -1e9)), formulas(h, vector<vector<pair<int, int>>>(w)) {}
    
    void set(int y, char x, int value) {
        values[y - 1][x - 'A'] = value;
    }
    
    int get(int y, char x) {
        return getValue(y - 1, x - 'A');
    }
    
    int sum(int y, char x, const vector<string> &cells) {
        values[y - 1][x - 'A'] = -1e9;
        formulas[y - 1][x - 'A'].clear();

        for (const string &cell : cells) {
            stringstream ss(cell);
            if (cell.find(':') == -1) {
                int cy;
                char cx;
                ss >> cx >> cy;
                formulas[y - 1][x - 'A'].push_back({ cy - 1, cx - 'A' });
            } else {
                int cy1, cy2;
                char cx1, cx2, colon;
                ss >> cx1 >> cy1 >> colon >> cx2 >> cy2;
                for (char cy = cy1; cy <= cy2; cy++)
                    for (char cx = cx1; cx <= cx2; cx++)
                        formulas[y - 1][x - 'A'].push_back({ cy - 1, cx - 'A' });
            }
        }

        return getValue(y - 1, x - 'A');
    }
};