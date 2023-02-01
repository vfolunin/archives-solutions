class MovingAverage {
    int size;
    double sum = 0;
    queue<int> q;

public:
    MovingAverage(int size) : size(size) {}
    
    double next(int value) {
        sum += value;
        q.push(value);
        if (q.size() > size) {
            sum -= q.front();
            q.pop();
        }
        return sum / q.size();
    }
};