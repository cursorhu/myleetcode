242. 异位字符串.cpp
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位字符串。

示例 1:
输入: s = "anagram", t = "nagaram"
输出: true

说明:你可以假设字符串只包含小写字母。

/*
提解：
两个乱序的字符串 => 每个字母出现次数的映射表一样
构建（字母值->字母出现次数）的哈希表，判断两个字符串的哈希表完全一样
可以直接用unordered_map<char, int>直接映射字符和次数值，也可以'x'-'a'转化成偏移值，形成<int, int>的映射，用数组构建
*/


class Solution {
public:
    bool isAnagram(string s, string t) {
    	if(s.size() != t.size())
    		return false;
    	
    	int size = s.size();
    	unordered_map<char, int> hash;
    	for (int i = 0; i < size; ++i)
    	{
    		hash[s[i]]++;
    		hash[t[i]]--; //本应构建两个hash对应两个字符串，这里直接抵消掉，hash表示已经抵消的计数，即不匹配的字符
    	}
    	//遍历hash的键，即26个字母，获取值，即出现次数
    	for (int i = 0; i < 26; ++i)
    	{
    		if(hash['a'+i] != 0) //题目只有小写字母
    			return false;
    	}
    	return true;
    }
};


class Solution {
public:
    bool isAnagram(string s, string t) {
    	if(s.size() != t.size())
    		return false;
    	
    	int size = s.size();
    	vector<int> hash(26, 0);
    	for (int i = 0; i < size; ++i)
    	{
    		hash[s[i]-'a']++;
    		hash[t[i]-'a']--; 
    	}
    
    	for (int i = 0; i < 26; ++i)
    	{
    		if(hash[i] != 0)
    			return false;
    	}
    	return true;
    }
};