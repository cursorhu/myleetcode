205. 同构字符串.cpp
给定两个字符串 s 和 t，判断它们是否是同构的。
如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。

示例:
输入: s = "paper", t = "title"
输出: true

输入: s = "foo", t = "bar"
输出: false


/*
题解：
理解一下题意：对字符串每个位置都允许字符替换，要换都得换，换完看两个字符串是否相同

思路一：
每个字符都是一对一替换，即char->char映射，这不就是哈希表？

先遍历一遍，建立从s到t的每个字符的哈希表
如果字符串异构，一定有一个s字符映射多个t字符的情况，如样例的 oo->ar，o先映射a, 然后o映射r，最终哈希表是o->r
遍历s->t的哈希表，每次和t的对应字符比一下，如果有不一样就是异构，都一样就是同构

以上是思路，实际要建立两个哈希表，分别表示s->t的映射和t->s的映射，因为不知道字符的一对多映射发生在哪个方向

思路二：
建立 字符->该字符的位置索引 的哈希映射，可以理解成对字符做编码，比较编码是否相同

如果位置索引是首次出现的下标，例子：
egg add 分别返回结果是011 011
foo bar 分别返回结果是011 012
paper title分别返回结果是01034 01034

C++可用string的方法：s.find_first_of(char)

实际上不用首次，在每次循环中比较两边字符串的当前字符的位置，有不同则为异构
位置映射只是个“中间人”，取代了思路一的两个映射方向

*/


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
        	return false;
        
        int size = s.size();
        unordered_map<char, char> hash1, hash2;
        for (int i = 0; i < size; ++i)
        {
        	hash1[s[i]] = t[i];
        	hash2[t[i]] = s[i];
        }

        for (int i = 0; i < size; ++i)
        {
        	if(hash1[s[i]] != t[i] || hash2[t[i]] != s[i])
        		return false;
        }
        return true;

    }
};


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
        	return false;
        
        int size = s.size();
        unordered_map<char, int> hash1, hash2;
        for (int i = 0; i < size; ++i)
        {
        	if(hash1[s[i]] != hash2[t[i]])
        		return false;
        	//这里用i+1是因为默认hash映射到0，如果用i, 用例ab aa, 会把默认的0和已映射的0弄混
        	hash1[s[i]] = hash2[t[i]] = i+1; 
        }

        return true;

    }
};