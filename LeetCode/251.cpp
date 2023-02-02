class Vector2D {
    vector<vector<int>> a;
    int i = 0, j = 0;

public:
    Vector2D(vector<vector<int>> &a) : a(a) {
        while (i < a.size() && a[i].empty())
            i++;
    }
    
    int next() {
        int res = a[i][j];
        j++;
        if (j == a[i].size()) {
            i++;
            while (i < a.size() && a[i].empty())
                i++;
            j = 0;
        }
        return res;
    }
    
    bool hasNext() {
        return i < a.size();
    }
};