//You are given an array of integers temperatures where temperatures[i] represents the daily temperatures on the ith day.

//Return an array result where result[i] is the number of days after the ith day before a warmer temperature appears on a future day.
//If there is no day in the future where a warmer temperature will appear for the ith day, set result[i] to 0 instead.

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());
        stack<pair<int,int> > pastTemps; //<temperature, index>

        for (int i = 0; i<temperatures.size(); ++i) {
            while (!pastTemps.empty() && temperatures[i] > pastTemps.top().first) {
                int lastTemp = pastTemps.top().first;
                int lastIndex = pastTemps.top().second;
                pastTemps.pop();
                result[lastIndex] = i-lastIndex;
            }

            pastTemps.push({temperatures[i], i});
        }

        return result;
    }
};
