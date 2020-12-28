5. 最长回文子串.cpp
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。


/*
思路：和647求回文子串的个数一样，遍历每个位置作为奇偶子串的中心，
在辅助函数返回该位置作为中心的所有子串长度的最大值，主函数返回全局最大值
*/

//返回最长回文子串的长度：
/*
class Solution {
public:
    int longestPalindrome(string s) {
    	if(s.empty())
    		return 0;

    	int totalLongest = 0;
    	for (int i = 0; i < s.size(); ++i)
    	{
    		totalLongest = max(longestSubString(s, i, i), totalLongest); //更新全局变量，本题是求最大
    		totalLongest = max(longestSubString(s, i, i+1), totalLongest);
    	}
    	return totalLongest;
    }
    //求当前位置为中心的所有情况
    int longestSubString(string s, int l, int r)
    {
    	int longest = 0;
    	int len = 0;
    	while(s[l] == s[r])
    	{
    		//更新长度
    		++len;
    		longest = max(len, longest);
    		--l;
    		++r;
    		if(l < 0 || r > s.size()-1)
    			break;
    	}
    	return longest;
    }
};
*/

//返回最长回文子串的字符，转化成求其左右下标：
class Solution {
public:
    string longestPalindrome(string s) {
    	if(s.empty())
    		return nullptr;

    	int l = 0, r = 0; //记录全局最大子串的左右下标
    	int longestLen = 0; //遍历时，当前中心字符的所有子串的最大长度
    	for (int i = 0; i < s.size(); ++i)
    	{
    		longestLen = max(longestSubString(s, i, i), longestSubString(s, i, i+1));
    		
    		if(longestLen >= r-l+1) //注意等号，是子串只有一个字符的情况，此时更新的l,r均等于i
    		{
    			//由长度求左右边界，要分当前中心位置i是奇串还是偶串
    			//长度 左减右不减，都除2，作为偏移，可以完美处理奇偶两种情况，这个要记住
    			l = i - (longestLen-1)/2;
    			r = i + longestLen/2;
    		}
    	}
    	//C++ string的子串：substr(起始下标，拷贝长度)
    	return s.substr(l, r - l + 1);
    }
    //求当前位置为中心的所有情况
    int longestSubString(string s, int l, int r)
    {
    	int len = 0;
    	while(s[l] == s[r])
    	{
    		//更新局部变量，本应是求子串，转化成求子串长度更简洁，注意长度是 下标差+1
      		len = r - l + 1;

    		//更新子串边界
    		--l;
    		++r;
    		if(l < 0 || r > s.size()-1)
    			break;
    	}
    	return len;
    }
};