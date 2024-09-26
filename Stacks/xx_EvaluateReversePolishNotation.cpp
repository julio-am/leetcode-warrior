//You are given an array of strings tokens that represents a valid arithmetic expression in Reverse Polish Notation.
//Return the integer that represents the evaluation of the expression.

//The operands may be integers or the results of other operations.
//The operators include '+', '-', '*', and '/'.
//Assume that division between integers always truncates toward zero.

class Solution {
public:

    bool isOperator(string& c) {
        static const std::unordered_set<string> operators = {"+", "-", "*", "/"};
        return operators.find(c) != operators.end();
    }

    int applyOperator(int l, int r, string& op) {
        if (op == "+") return l+r;
        if (op == "-") return l-r;
        if (op == "*") return l*r;
        if (op == "/") return l/r;  
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        
        for (auto c : tokens) {
            if (isOperator(c)) {
                int r = numbers.top(); numbers.pop();
                int l = numbers.top(); numbers.pop();
                numbers.push(applyOperator(l, r, c));
            }
            else
                numbers.push(stoi(c));
        }
        return numbers.top();
    }
};
