class SQL {
    unordered_map<string, unordered_map<int, vector<string>>> tables;
    unordered_map<string, int> index;

public:
    SQL(vector<string> &, vector<int> &) {}

    void insertRow(const string &name, const vector<string> &row) {
        tables[name][++index[name]] = row;
    }
    
    void deleteRow(const string &name, int rowId) {
        tables[name].erase(rowId);
    }
    
    string selectCell(const string &name, int rowId, int columnId) {
        return tables[name][rowId][columnId - 1];
    }
};