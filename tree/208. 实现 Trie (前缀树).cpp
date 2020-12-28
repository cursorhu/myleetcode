208. 实现 Trie (前缀树).cpp
实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

示例:
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // 返回 true
trie.search("app");     // 返回 false
trie.startsWith("app"); // 返回 true
trie.insert("app");   
trie.search("app");     // 返回 true

说明:
你可以假设所有的输入都是由小写字母 a-z 构成的。
保证所有输入均为非空字符串。


/*
背景：
1. 字典树/前缀树（Trie, Prefix Tree），用于判断字符串是否存在或者是否具有某种字符串前缀。
为什么需要用字典树解决这类问题呢？
假如我们有一个储存了近万个单词的字典，即使我们使用哈希，在其中搜索一个单词的实际开销也是非常大的，且无法轻易支持搜索单词前缀。
然而由于一个英文单词的长度 n 通常在 10 以内，如果我们使用字典树，则可以在 O(n)——近似O(1)的时间内完成搜索，且额外开销非常小。
对于大量单词字符串的问题，用字典树


2.Trie 的实现：是一颗非典型的多叉树模型，多叉即每个结点的分支数量可能为多个。
为什么说非典型呢？因为它在结点的数据结构设计上和一般的多叉树不一样
一般的多叉树的结点是这样的：
struct TreeNode {
    VALUETYPE value;    //结点值
    TreeNode* children[NUM];    //指向孩子结点
};

字典树的结点是这样的(假设只包含'a'~'z'中的字符)：
每个节点表示一个字母，但是节点结构体只表示该字母是不是单词最后一个字母，以及下一个字母节点的指针
查询TrieNode，依赖的就是
struct TrieNode {
    bool isEnd; //该结点是否是一个串的结束
    TrieNode* next[26]; //字母映射表，链接到下一个节点（字母）
};

更多参考：
https://leetcode-cn.com/problems/implement-trie-prefix-tree/solution/trie-tree-de-shi-xian-gua-he-chu-xue-zhe-by-huwt/

*/


class TrieNode {
public:
	TrieNode *nextNode[26];
	bool isEnd;
public:
	TrieNode(): isEnd(false){
		for (int i = 0; i < 26; ++i)
		{
			nextNode[i] = nullptr;
		}
	}
};

class Trie {
private:
	TrieNode* root;
public:
	Trie(): root(new TrieNode()) {}
	// 向字典树插入一个词
	void insert(string word) {
		TrieNode* temp = root;
		for (int i = 0; i < word.size(); ++i) {
			if (!temp->nextNode[word[i]-'a']) {
				temp->nextNode[word[i]-'a'] = new TrieNode();
			}
			temp = temp->nextNode[word[i]-'a'];
		}
		temp->isEnd = true; //此时temp指向单词最后一个字母对应的TrieNode节点
	}

	// 判断字典树里是否有一个词
	bool search(string word) {
		TrieNode* temp = root;
		for (int i = 0; i < word.size(); ++i) {
			if (!temp) {
				break;
			}
			temp = temp->nextNode[word[i]-'a'];
		}
		return temp? temp->isEnd: false;
	}
	// 判断字典树是否有一个以词开始的前缀
	bool startsWith(string prefix) {
		TrieNode* temp = root;
		for (int i = 0; i < prefix.size(); ++i) {
			if (!temp) {
				break;
			}
			temp = temp->nextNode[prefix[i]-'a'];
		}
		return temp;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */