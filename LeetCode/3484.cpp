class Spreadsheet {
    unordered_map<string, int> valueOf;

public:
    Spreadsheet(int rows) {}
    
    void setCell(const string &cell, int value) {
        valueOf[cell] = value;
    }
    
    void resetCell(const string &cell) {
        valueOf.erase(cell);
    }

    int getCell(const string &cell) {
        if (isdigit(cell[0]))
            return stoi(cell);
        else if (valueOf.count(cell))
            return valueOf[cell];
        else
            return 0;
    }
    
    int getValue(const string &formula) {
        int plus = formula.find('+');
        return getCell(formula.substr(1, plus - 1)) + getCell(formula.substr(plus + 1));
    }
};