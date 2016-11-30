// Source : https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/
// Author : Hao Chen
// Date   : 2014-07-19

/********************************************************************************** 
* 
* Given a string, find the length of the longest substring without repeating characters. 
* For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
* which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*               
**********************************************************************************/

/**
 * 我的解法，先扫描一遍字符串，统计字符串上次出现的距离，上一次没有，就用-1，例如 abcacbb -> sub[-1,-1,-1,3,2,4,1] (用hash表快速计算出，如果string都是ascii码可以用 int hash[128])
 * int max_len, len; 然后遍历字符串，如果sub[i] 为-1，len++, 如果sub[i]>len,len++; 可以把-1替换成一个很大的数，就可以合成一种情况
 * ，如果sub[i]<=len len=sub[i]   (先把sub数组初始化为全部-1，或一个大于len的值，上面步骤可以在一个循环完成，复杂度O(n))
 * */

#include <string.h>
#include <iostream>
#include <string>
#include <map>

using namespace std;

/*
 * Idea:
 * 
 * Using a map store each char's index.
 * 
 * So, we can be easy to know the when duplication and the previous duplicated char's index.
 * 
 * Then we can take out the previous duplicated char, and keep tracking the maxiumn length. 
 * 
 */
int lengthOfLongestSubstring1(string s) {
    map<char, int> m;
    int maxLen = 0;
    int lastRepeatPos = -1;
    for (int i = 0; i < s.size(); i++) {
        if (m.find(s[i]) != m.end() && lastRepeatPos < m[s[i]]) {
            lastRepeatPos = m[s[i]];
        }
        if (i - lastRepeatPos > maxLen) {
            maxLen = i - lastRepeatPos;
        }
        m[s[i]] = i;
    }
    return maxLen;
}

//don't use <map>
int lengthOfLongestSubstring(string s) {
    const int MAX_CHARS = 256;
    int m[MAX_CHARS];
    memset(m, -1, sizeof(m));

    int maxLen = 0;
    int lastRepeatPos = -1;
    for (int i = 0; i < s.size(); i++) {
        if (m[s[i]] != -1 && lastRepeatPos < m[s[i]]) {
            lastRepeatPos = m[s[i]];
        }
        if (i - lastRepeatPos > maxLen) {
            maxLen = i - lastRepeatPos;
        }
        m[s[i]] = i;
    }
    return maxLen;
}

int main(int argc, char **argv) {
    string s = "abcabcbb";
    cout << s << " : " << lengthOfLongestSubstring(s) << endl;

    s = "bbbbb";
    cout << s << " : " << lengthOfLongestSubstring(s) << endl;

    s = "bbabcdb";
    cout << s << " : " << lengthOfLongestSubstring(s) << endl;

    if (argc > 1) {
        s = argv[1];
        cout << s << " : " << lengthOfLongestSubstring(s) << endl;
    }

    return 0;
}
