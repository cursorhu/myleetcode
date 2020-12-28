/*
409. 异位的最长回文串.cpp
给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。

示例 1:
输入:
"abccccdd"
输出:
7
解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7
*/

/*
题解：
分解题目： 字符可以随便换位置（异位） + 最长回文子串
相关题目：242.异位字符串，5.最长回文子串

异位字符串，用哈希表，统计每个字符出现的次数
回文子串，用中心向两边扩展遍历，左右字符相同，需要分奇偶

那么本题思路：
1.子串分奇偶，分别统计每个字符次数的哈希表
2.由于子串是乱序的，不存在中心对称，只需要统计：
对偶串，每个字符出现次数都是偶数
对奇串，有一个字符出现次数是奇数（中间字符），其他字符都是偶数
满足以上要求，就能重排成回文子串
最后统计出最长的那个子串

怎么统计最长子串？
考虑下示例，abccccdd，偶数出现次数的字符都包含到最长回文子串了，奇数的有a和b, 选出现次数多的作为中心字符，肯定全局最长
即贪心思路，在满足条件的情况下，局部能多则多，最终全局最多
因此计数方法：
对于偶数串，都算到要求的最长串中
对于奇数串，最大长度那个算到要求的最长串中

如果有多个奇数串，以上方法还“不够贪”
对多个奇数串，去掉多余的一个字符，剩下的即偶数串，都应该包含在最终子串，才是所求的最长串
因此改进计数方法：
对每个奇串-1后，算到最终串中，最后在+1，补回中心的那个奇串字符（具体是哪个奇串的字符不重要，有多个解）
*/

class Solution {
public:
    int longestPalindrome(string s) {
    	if(s.empty())
    		return 0;
    	
    	unordered_map<char, int> hash;
    	//统计各字符出现次数，初始化hash
    	for (int i = 0; i < s.size(); ++i)
    	{
    		hash[s[i]]++;
    	}

    	int totalLen = 0; //最长回文子串的长度（即字符个数）
    	int oddFlag = 0; //奇数串需要统计最长
    	for (int i = 0; i < 26; ++i) //26个字母，作为hash表的下标，遍历每个字符的出现次数
    	{
    		//没出现的字符直接跳过
    		if(!hash['a'+i] && !hash['A'+i]) 
    			continue;
    		
    		//该字符出现偶数次
    		if(hash['a'+i] % 2 == 0)
    		{
    			totalLen += hash['a'+i]; //这些字符都属于最大回文子串
    		}
    		if(hash['A'+i] % 2 == 0) //大写字母
    		{
    			totalLen += hash['A'+i];
    		}

    		//该字符出现奇数次
    		if(hash['a'+i] % 2 == 1) 
    		{
    			totalLen += hash['a'+i]-1; 
    			oddFlag = 1;
    		}
    		if(hash['A'+i] % 2 == 1) //大写字母
    		{
    			totalLen += hash['A'+i]-1;
    			oddFlag = 1;
    		}
    	}

    	if(oddFlag)
	    	totalLen += 1;

    	return totalLen;
    }

};

/*
* C++11写法：用auto item : hash 遍历unordered_map hash的有效成员，而不用遍历26个字母，不用处理大小写
* item.second 即为 unordered_map<key,value> 的 value
*/

class Solution {
public:
	int longestPalindrome(string s) {
		unordered_map<char, int> hash;
        for (auto x : s) hash[x] ++;
        int res = 0, center = 0;

        for (auto item : hash){
            if (item.second % 2 == 0) 
                res += item.second;
            else{
                res += item.second - 1;
                center = 1;
            }
        }
        return res + center;
	}
};

