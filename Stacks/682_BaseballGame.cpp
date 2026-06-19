class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> record;
        int result = 0;

        for (string op : operations) {
            if (op == "C") {
                result -= record.top();
                record.pop();
            }
            else if (op == "D") {
                record.push(2 * record.top());
                result += record.top();
            }
            else if (op == "+") {
                int right = record.top();
                record.pop();
                int left = record.top();
                record.push(right);
                record.push(left + right);
                result += record.top();
            }
            else {
                record.push(stoi(op));
                result += record.top();
            }
        }
       return result; 
    }
};
