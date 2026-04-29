class DetectSquares {
private:
    unordered_map<int, int> points_frequency_map;
    vector<vector<int>> points;
    int getPointHash(int x, int y) {
        return x*1007 + y;
    }
    bool isDiagonal(int x1, int y1, int x2, int y2) {
        return (x1 != x2 && y1 != y2 && abs(x1 - x2) == abs(y1 - y2));
    }
public:
    DetectSquares() {
        points_frequency_map.clear();
        points.clear();
    }
    
    void add(vector<int> point) { // T.C: O(log(N)) -> O(1)
        int pointHash = getPointHash(point[0], point[1]);
        points_frequency_map[pointHash]++;
        points.push_back(point);
    }
    
    int count(vector<int> queryPoint) { // T.C: O(NlogN) -> O(N)
        int x1 = queryPoint[0], y1 = queryPoint[1];
        int formedSqurareCount = 0;
        for(auto point: points) {
            int x2 = point[0], y2 = point[1];
            if(isDiagonal(x1, y1, x2, y2)) {
                formedSqurareCount += points_frequency_map[ getPointHash(x1, y2) ] 
                                    * points_frequency_map[ getPointHash(x2, y1) ];
            }
        }
        return formedSqurareCount;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */