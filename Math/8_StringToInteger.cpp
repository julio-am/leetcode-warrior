//Whitespace: Ignore leading whitespaces (" ").
//Signedness: check if the next character is '-' or '+', assuming positivity is neither present.
//Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
//Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.

#include <string>

class Solution {
public:
    int myAtoi(string s) { 
        // Erase leading whitespaces
        s.erase(0, s.find_first_not_of(' '));
        
        int result = 0;
        int multiplier = 1;

        // Process "-" or "+" if it exists
        if (!s.empty()) {
            if (s[0] == '-') {
                multiplier = -1;
                s.erase(0,1);
            }
            
            else if (s[0] == '+') {
                s.erase(0,1);
            }
        }
        
        
        while (s.length() != 0 && isdigit(s[0])) {
            int digit = (s[0] - '0');
            
            // Check overflow and underflow conditions.
            if ((result > INT_MAX / 10) ||
                (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return multiplier == 1 ? INT_MAX : INT_MIN;
            }
          
            result = (10*result) + digit;
            s.erase(0,1);
        }
        
        return result * multiplier;
    }
};
