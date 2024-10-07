//You are given a 0-indexed string s of even length n. The string consists of exactly n / 2 opening brackets '[' and n / 2 closing brackets ']'.

//A string is called balanced if and only if:
  //It is the empty string, or
  //It can be written as AB, where both A and B are balanced strings, or
  //It can be written as [C], where C is a balanced string.
  //You may swap the brackets at any two indices any number of times.

//Return the minimum number of swaps to make s balanced.

class Solution {
public:
    int minSwaps(string s) {
        // we know that if there are ever more closing parenthesis than 
        // matched open parenthesis we have to do a swap.
        int freeOpens = 0;    

        // another way to think of this is counting the iterations during which
        // the balance was off.
        //int offBalance = 0;
        for (auto c : s) {
            if (c == '[') ++freeOpens;

            else {
                if (freeOpens) --freeOpens;
                //else ++offBalance;
            }
        }

        // One swap will fix 2 unmatched brackets/
        // +1 needed to avoid rounding down for odd numbers.
        return (freeOpens+1) / 2;
        //return (offBalance+1) / 2;
    }
};
