// No3_LongestSubStr.cpp
// 
/**
 * Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

Subscribe to see which companies asked this question.
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    static int lengthOfLongestSubstring(string s)
    {
    	if (s.length() < 2)
    	{
    		return s.length();
    	}

    	int imax = 1;
    	int istart = 0;
		int icur = 1;

    	for (; icur < s.length(); icur++)
    	{
	    	for (int i = istart; i < icur; i++)
	    	{
	    		if (s[icur] == s[i])
	    		{
	    			int inewmax = icur - istart;
	    			imax = imax > inewmax? imax : inewmax;
	    			istart = i + 1;
	    			break;
	    		}
	    	}
    	}

    	int inewmax = icur - istart;
	    imax = imax > inewmax? imax : inewmax;

        return imax;
    }
};

int main(int argc, char **argv)
{
	int iret = Solution::lengthOfLongestSubstring("123456789qwert123");
	cout << iret << endl;
	return 0;
}





