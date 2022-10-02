class LUPrefix {
    set<int> points;
    int prefix = 0;
    
public:
    LUPrefix(int n) {}
    
    void upload(int point) {
        points.insert(point);
        while (points.count(prefix + 1))
            prefix++;
    }
    
    int longest() {
        return prefix;
    }
};