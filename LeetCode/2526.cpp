class DataStream {
    queue<int> window;
    int targetValue, width, count = 0;

public:
    DataStream(int targetValue, int width) :
        targetValue(targetValue), width(width) {}
    
    bool consec(int value) {
        count += value == targetValue;
        window.push(value);        
        if (window.size() > width) {
            count -= window.front() == targetValue;
            window.pop();
        }
        return count == width;
    }
};