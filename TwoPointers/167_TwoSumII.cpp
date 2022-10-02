class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int found = numbers[left] + numbers[right];
    
            if (found == target) 
                return vector<int>({left+1, right+1});
            
            if (found < target)
                left += 1;  

            if (found > target)
                right -= 1;
        }
        return vector<int>({-1,-1});
    }
};