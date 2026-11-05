//You are given a nested list of integers nestedList. Each element is either an integer or a list whose elements may also be integers or other lists.
//The depth of an integer is the number of lists that it is inside of. For example, the nested list [1,[2,2],[[3],2],1] has each integer's value set to its depth.
//Return the sum of each integer in nestedList multiplied by its depth.

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {

// Time complexity O(N)
// Space complexity O(D)

// Depth is limited to 50 so this should be good, but the alternative is BFS, which has a 
// space complexity of O(N>)
private:
    int result = 0;

    void dfs(vector<NestedInteger>& nestedList, int level) {
        for (int i = 0; i < nestedList.size(); ++i) {
            NestedInteger cur = nestedList[i];

            if (cur.isInteger()) {
                result += cur.getInteger() * level; 
            }

            else {
                dfs(cur.getList(), level+1);
            }
        }
    } 


public:
    int depthSum(vector<NestedInteger>& nestedList) {
        dfs(nestedList, 1);
        return result;
    }
};
