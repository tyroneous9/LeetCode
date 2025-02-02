/*

Given a string s, find the length of the longest
substring
 without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> usedChars;
    int longestLength = 0;
    int currentLength = 0;
    for (int i = 0, root = 0; i < s.length(); i++) {  
        if (usedChars.find(s[i]) != usedChars.end() && usedChars[s[i]] >= root) { //char exists AND is after root
            root = usedChars[s[i]]+1; //move root 1 after repeating char
            currentLength = i-root+1; //update length from root to new char
        }
        else {
            currentLength += 1;
        }
        usedChars[s[i]] = i; //update current char pos
        if (currentLength > longestLength) {
            longestLength = currentLength;
        }
    }
    return longestLength;
}

int main()
{
    std::cout << lengthOfLongestSubstring(" ") << "\n"; //1
    std::cout << lengthOfLongestSubstring("c") << "\n"; //1
    std::cout << lengthOfLongestSubstring("abcabcbb") << "\n"; //3
    std::cout << lengthOfLongestSubstring("pwwkew") << "\n"; //3
    std::cout << lengthOfLongestSubstring("dvdf") << "\n"; //3
    std::cout << lengthOfLongestSubstring("tmmzuxt") << "\n"; //5

}
