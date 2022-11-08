class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        string result = "";
        
        if (a) pq.push({a, 'a'});
        if (b) pq.push({b, 'b'});
        if (c) pq.push({c, 'c'});
        
        while (pq.size() > 1) {
            auto pair1 = pq.top(); pq.pop();
            auto pair2 = pq.top(); pq.pop();
            
            int num1 = pair1.first >= 2? 2 : 1;
            result += string(num1, pair1.second);
            pair1.first -= num1;
            
            int num2 = (pair2.first >= 2 and pair2.first >= pair1.first) ? 2 : 1;
            result += string(num2, pair2.second);
            pair2.first -= num2;
            
            if (pair1.first > 0) pq.push(pair1);
            if (pair2.first > 0) pq.push(pair2);
        }
        
        if (!pq.empty()) {
            auto p = pq.top(); pq.pop();
            int num = p.first >= 2 ? 2 : 1;
            result += string(num, p.second);
        }
        
        return result;
    }
};
