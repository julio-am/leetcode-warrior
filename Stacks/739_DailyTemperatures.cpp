class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());
        stack<pair<int,int>> seen;

        for (int i = 0; i < temperatures.size(); ++i) {
            int curTemp = temperatures[i];

            // While the current temperature is warmer than previously seen temperatures
            // pop the cooler temperatures off the stack and record the number of days in between
            while (!seen.empty() && curTemp > seen.top().first) {
                int prevIndex = seen.top().second;
                result[prevIndex] = i - prevIndex; 
                seen.pop();
            }

            seen.push({curTemp, i});
        }

        return result;
    }
};
