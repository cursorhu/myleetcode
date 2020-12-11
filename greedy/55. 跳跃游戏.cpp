/*
55. 跳跃游戏
给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个位置。

示例 1:
输入: [2,3,1,1,4]
输出: true

*/

/*
一版解答(不通过)：
有点像134加油站问题，都是连续遍历数组求能不能到终点
反向思考：什么情况不能到达？
每个跳跃长度的和 < 数组长度，不能到达
因此贪心算法，能跳多远就跳多远，最终总长度要大于数组长度即可
写出第一版如下：

结果：
用例[3,2,1,0,4]不通过
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
    	int len = 0;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		len += nums[i];
    	}
    	return len >= nums.size() ? true : false;
    }
};

/*
二版解答：
还是贪心，不过遍历时，需要维护当前位置能走到的最远范围
1.如果已经覆盖了数组末端，返回true
2.如果遇到‘死结’，例如用例的位置0，提前退出遍历，返回false

或者另一种写法：
1.只在可跳范围内，迭代最远可跳范围，直到可跳范围迭代完成
2.如果覆盖了数组距离，返回true, 如果迭代完还没覆盖，返回false
*/

bool canJump(vector<int>& nums) 
{
	int range = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		//遍历位置超出了可跳返回，说明可跳范围没覆盖完整数组
		if (i > range) 
			return false;
		range = max(range, i + nums[i]);
	}
	return true;
}

bool canJump(vector<int>& nums) 
{
	int range = 0;
    for (int i = 0; i <= range; i++) { // 注意这里是小于等于range
        range = max(i + nums[i], range);
        if (range >= nums.size() - 1) 
        	return true; // 说明可以覆盖到终点了
    }
    return false;
}
