// LeeCode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <set>
#include<algorithm>
#include <vector>
#include <string>
using namespace std;

//leeCode(1)  
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

	int i = 0;
	int j = 0;
	*returnSize = 2;
	int * result = NULL;
	for (i = 0; i < numsSize - 1; i++)
	{
		int temp = target - nums[i];

		for (j = i + 1; j < numsSize; j++)
		{

			if (nums[j] == temp)
			{
				result = (int*)malloc(sizeof(int) * 2);
				result[0] = i;
				result[1] = j;

				return result;

			}
		}

	}

	return returnSize;
}

//leeCode(2)  
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

	struct ListNode* root = (struct ListNode*)malloc(sizeof(struct ListNode));

	struct ListNode* p = root;

	struct ListNode* l1temp = l1;
	struct ListNode* l2temp = l2;

	int flag = 0;
	int v = 0;
	int temp = 0;
	int num = 0;
	while (l1temp != NULL || l2temp != NULL)
	{
		struct ListNode*q = (struct ListNode*)malloc(sizeof(struct ListNode));
		if (l1temp != NULL && l2temp != NULL)
		{
			temp = l1temp->val + l2temp->val + flag;

			v = temp % 10;
			flag = temp / 10;

			if (num == 0)
			{
				p->val = v;
				p->next = NULL;

			}
			else
			{
				q->val = v;
				q->next = NULL;
				p->next = q;
				p = p->next;
			}



			l1temp = l1temp->next;
			l2temp = l2temp->next;
		}
		else if (l1temp == NULL)
		{
			temp = l2temp->val + flag;
			v = temp % 10;
			flag = temp / 10;
			q->val = v;
			q->next = NULL;
			p->next = q;
			p = p->next;
			l2temp = l2temp->next;


		}
		else if (l2temp == NULL)
		{
			temp = l1temp->val + flag;
			v = temp % 10;
			flag = temp / 10;
			q->val = v;
			q->next = NULL;
			p->next = q;
			p = p->next;
			l1temp = l1temp->next;
		}

		num++;

	}

	if (flag != 0)
	{
		struct ListNode* tt = (struct ListNode*)malloc(sizeof(struct ListNode));
		tt->val = flag;
		tt->next = NULL;
		p->next = tt;
	}
	return root;
}

//leeCode(3)  最长子串
int lengthOfLongestSubstring(char * s) {
	int i;
	int j;
	int len = 0;
	int res = 0;
	int temp[256] = { 0 };


	for (i = 0, j = 0; s[i] != '\0'; i++)
	{

		int k = s[i];
		if (temp[k] != 0)
		{
			if (len > res)
			{
				res = len;
			}
			int m;
			while (s[j] != s[i])
			{
				m = s[j];
				temp[m] = 0;
				j++;
				len--;
			}
			j++;

		}
		else
		{
			temp[k] = 1;
			len++;
		}
	}

	if (len > res)
	{
		res = len;
	}
	return res;
}

//leeCode(4) 中位数
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

	double result = 0;

	int sumSize = nums1Size + nums2Size;
	int len = sumSize / 2;
	int size = len + 1;

	int * merge = (int *)malloc(size * sizeof(int));

	int i, n1, n2;

	for (i = 0, n1 = 0, n2 = 0; i < size; i++)
	{
		if (n1 < nums1Size && n2 < nums2Size)
		{
			if (nums1[n1] > nums2[n2])
			{
				merge[i] = nums2[n2];
				n2++;
			}
			else
			{
				merge[i] = nums1[n1];
				n1++;
			}

		}

		else if (n1 >= nums1Size)
		{
			merge[i] = nums2[n2];
			n2++;
		}
		else if (n2 >= nums2Size)
		{
			merge[i] = nums1[n1];
			n1++;
		}

	}


	if (sumSize % 2 != 0)
	{
		result = merge[len];
	}
	else
	{
		result = merge[len - 1] + merge[len];
		result = result / 2;
	}

	return result;
}
// 也可利用中位数的特点计算，未实现

//leeCode(5)  最大回文子串
char * longestPalindrome(const char * s) {

	char *res;
	char* tempstr;
	int * temprids;
	int len = 0; //表示s的长度
	int i, j;
	for (i = 0; s[i] != '\0'; i++)
	{
		len++;
	}


	if (len == 0)
	{
		//	return s;
	}

	int tempsize = 2 * len + 3;

	tempstr = (char*)malloc(tempsize + 1);

	temprids = (int*)malloc(tempsize * sizeof(int));

	for (i = 1, j = 0; i < tempsize; i++)
	{
		if (i % 2 == 0)
		{
			tempstr[i] = s[j];
			j++;
		}
		else
		{
			tempstr[i] = '#';
		}

		temprids[i] = 0;
	}

	tempstr[0] = '@';
	tempstr[tempsize - 1] = '!';
	tempstr[tempsize] = '\0';


	int rid = 0;
	int center = 0;
	for (center = 0; center < tempsize; center++)
	{


		for (i = center + 1; i < center + rid; i++)
		{
			j = 2 * center - i;

			if (j > 0)
			{
				if (temprids[j] + i < center + rid)
				{
					temprids[i] = temprids[j];

					center = i;
				}
				else
				{
					break;
				}
			}
		}

		rid = 0;

		while (center - rid >= 0 && center + rid < tempsize)
		{
			if (tempstr[center - rid] == tempstr[center + rid])
			{
				rid++;
			}
			else
			{
				break;
			}
		}

		temprids[center] = rid;

		//center = center + rid;

	}

	int maxpos = 0;
	int maxrids = 0;
	for (i = 0; i < tempsize; i++)
	{
		cout << temprids[i] << " ";

		if (temprids[i] > maxrids)
		{
			maxpos = i;
			maxrids = temprids[i];
		}
	}


	int ressize = maxrids - 1;

	res = (char*)malloc(ressize + 1);

	for (i = maxpos - maxrids + 1, j = 0; i < maxpos + maxrids; i++)
	{
		if (tempstr[i] != '#')
		{
			res[j] = tempstr[i];
			j++;
		}
	}

	res[j] = '\0';



	cout << endl;

	//res = tempstr;

	return res;

}
//使用Manacher算法实现，但是好像有一点问题，因为时间效率有点大
char * longestPalindromeManacher(const char * s) {

	char *res;
	char* tempstr;
	int * temprids;
	int len = 0; //表示s的长度
	int i, j;
	for (i = 0; s[i] != '\0'; i++)
	{
		len++;
	}


	if (len == 0)
	{
		//	return s;
	}

	int tempsize = 2 * len + 3;

	tempstr = (char*)malloc(tempsize + 1);

	temprids = (int*)malloc(tempsize * sizeof(int));

	for (i = 1, j = 0; i < tempsize; i++)
	{
		if (i % 2 == 0)
		{
			tempstr[i] = s[j];
			j++;
		}
		else
		{
			tempstr[i] = '#';
		}

		temprids[i] = 0;
	}

	tempstr[0] = '@';
	tempstr[tempsize - 1] = '!';
	tempstr[tempsize] = '\0';


	int rid = 0;
	int center = 0;
	for (center = 0; center < tempsize; center++)
	{


		for (i = center + 1; i < center + rid; i++)
		{
			j = 2 * center - i;

			if (j > 0)
			{
				if (temprids[j] + i < center + rid)
				{
					temprids[i] = temprids[j];

					center = i;
				}
				else
				{
					break;
				}
			}
		}

		rid = 0;

		while (center - rid >= 0 && center + rid < tempsize)
		{
			if (tempstr[center - rid] == tempstr[center + rid])
			{
				rid++;
			}
			else
			{
				break;
			}
		}

		temprids[center] = rid;

		//center = center + rid;

	}

	int maxpos = 0;
	int maxrids = 0;
	for (i = 0; i < tempsize; i++)
	{
		cout << temprids[i] << " ";

		if (temprids[i] > maxrids)
		{
			maxpos = i;
			maxrids = temprids[i];
		}
	}


	int ressize = maxrids - 1;

	res = (char*)malloc(ressize + 1);

	for (i = maxpos - maxrids + 1, j = 0; i < maxpos + maxrids; i++)
	{
		if (tempstr[i] != '#')
		{
			res[j] = tempstr[i];
			j++;
		}
	}

	res[j] = '\0';



	cout << endl;

	//res = tempstr;

	return res;

}

//leeCode(6) 一个转换字符串
char * convert(const char * s, int numRows) {

	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}

	char *res = (char*)malloc(len);
	int num = 0;
	int line = 0;
	int inter = 0;
	int next = 0;
	int pos = 0;

	res[len] = '\0';
	while (num < len)
	{
		int temp = numRows - line;
		inter = (temp) * 2 - 2;
		next = 2 * line;
		pos = line;

		while (num < len && pos < len && inter != 0)
		{
			res[num] = s[pos];
			num++;
			pos = pos + inter;
			if (line != 0 && pos < len &&num < len)
			{
				res[num] = s[pos];
				num++;
				pos = pos + next;
			}
			
		}

		while (inter == 0 && pos < len)
		{
			res[num] = s[pos];
			num++;
			pos = pos + next;
		}
		line++;
	}

	return res;

}

//leeCode(7) 倒置数
int reverse(int x) {

	int num = 0;
	int mod = 0;

	int temp = 0;
	double res = 0;


	if (x > -10 && x < 10)
	{
		return x;
	}

	mod = x % 10;
	num = x / 10;

	// res = mod;
	while (num != 0)
	{
		res = mod + 10 * res;
		mod = num % 10;
		num = num / 10;

	}

	res = 10 * res;
	//判断是否越界
	if ((int)res != res)  
	{
		return 0;
	}

	res = res + mod;

	return res;
}

//leeCode(8) 字符串转为Int
int myAtoi(const char * str) {
	double res = 0;
	int i;
	bool flag = false;
	bool positive = false;
	bool begin = false;
	bool number = false;

	//bool isdig =false;
	int temp;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ' && begin == false)
		{
			continue;
		}
		else if (str[i] == ' ')
		{
			break;
		}

		if (str[i] == '+'&& number == false && begin == false)
		{
			begin = true;
			positive = true;
			continue;
		}
		else if (str[i] == '+')
		{
			break;
		}

		if (str[i] == '-' && number == false && begin == false)
		{
			begin = true;
			flag = true;
			continue;
		}
		else if (str[i] == '-')
		{
			break;
		}

		if (str[i] > '9' || str[i] < '0')
		{
			break;
		}

		temp = str[i] - '0';

		res = temp + res * 10;
		begin = true;
		number = true;

	}

	if (flag == true && positive == true)
	{
		return 0;
	}

	int value = res;

	if (value != res)
	{
		if (flag == true)
		{
			return -2147483648;
		}
		else
		{
			return 2147483647;
		}

	}

	if (flag == true)
	{
		res = -res;
	}

	return res;

}


//leeCode(9) 判断是否为回文数
bool isPalindrome(int x) {

	if (x < 0)
	{
		return false;
	}

	bool res = false;
	int mod = 0;
	int con = x;
	double new0 = 0;


	while (con > 0)
	{
		mod = con % 10;
		con = con / 10;
		new0 = new0 * 10 + mod;
	}

	if (x == new0)
	{
		res = true;
	}

	return res;
}

//leeCode(10) 字符串匹配
bool isMatch(const char * s, const char * p) {

	char  before;

	int i;
	int j;

	bool res = false;
	for (i = 0, j = 0; s[i] != '\0'&& p[j] != '\0';)
	{
		if (j > 0)
		{
			before = p[j - 1];
		}




		if (p[j] == '.')
		{
			i++;
			j++;
			continue;
		}



		if (s[i] == p[j])
		{
			i++;
			j++;
			continue;
		}
		else
		{
			if (p[j + 1] == '*')
			{
				j = j + 2;
				continue;
			}
			if (p[j] == '*')
			{
				if (before == s[i] || before == '.')
				{
					i++;
					j++;
					continue;
				}  

				j = j + 1;
				continue;
			}
			if (before == '*')
			{
				i++;
				continue;
			}

			break;
		}
		/*
		if (p[j] == '*')
		{
			if (before == s[i] || before == '.')
			{
				i++;
				j++;
				continue;
			}
		}
	*/


	}

	if (s[i] == '\0' && p[j] == '\0')
	{
		res = true;
	}

	else if (s[i] == '\0' && p[j + 1] == '\0' &&(p[j] == '*' || p[j] =='.'))
	{
		res = true;
	}




	return res;

}


//leeCode(234) 是否为回文链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };


bool isPalindrome(struct ListNode* head) {

	int len;
	bool res = false;
	len = 0;
	int loc = 0;

	struct ListNode* p = head;
	struct LIstNode* q;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}

	if (len == 0 || len == 1)
	{
		return true;
	}


	int pos = len / 2;

	p = head;
	struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
	while (pos > 0)
	{
		if (loc == 0)
		{
			temp = p;
			p = p->next;
			temp->next = NULL;
			loc++;
		}
		else
		{
			q = p->next;
			p->next = temp;
			temp = p;
			p = q;

		}

		pos--;
	}

	if (len % 2 != 0)
	{
		p = p->next;
	}

	while (temp != NULL && p != NULL)
	{
		if (temp->val == p->val)
		{
			temp = temp->next;
			p = p->next;

			continue;
		}
		else
		{
			return false;
		}
	}

	return true;


}
 */

//leeCode(39)  组合之和
bool sortFun(const int &p1, const int &p2)
{
	return p1 < p2;//升序排列  
}
class Solution {
public:

		vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

		set<vector<int>> result;
		vector<vector<int>> resultset;
		vector<int> current;
		sort(candidates.begin(), candidates.end(), sortFun);
		combinationSumCore(result, candidates, current, target);
		
		for (set<vector<int>>::iterator iter = result.begin(); iter != result.end(); ++iter)
		{
			resultset.push_back(*iter);
		}
		
		return resultset;

	}

	int combinationSumCore(set<vector<int>> &result, vector<int> candidates, vector<int>current, int target)
	{
		if (target == 0)
		{
			sort(current.begin(), current.end(), sortFun);
			result.insert(current);
		}
		else
		{
			for (vector<int>::iterator iter = candidates.begin(); iter != candidates.end(); ++iter)
			{
				vector<int> new_cur = current;
				int newnum = target - (*iter);
				if (newnum >= 0)
				{
					new_cur.push_back(*iter);
					combinationSumCore(result, candidates, new_cur, newnum);
				}
				else
				{
					break;
				}
			}

		}

		return 0;

	}

};


//leetcode46 全排列
class Solution46 {
public:
	vector<vector<int>> permute(vector<int>& nums) {

		vector<vector<int>> result;
		if (nums.size() == 1)
		{
			result.push_back(nums);
			return result;
		}
		permuteCore(result, nums);

		return result;
	}


	void permuteCore(vector<vector<int>>& result, vector<int> unused)
	{
		vector<vector<int>> result_c;
		int i = unused.back();
		unused.pop_back();
		if (result.size() == 0)
		{
			vector<int> tmp;
			tmp.push_back(i);
			result.push_back(tmp);
			permuteCore(result, unused);
		}
		else 
		{
			for (vector<vector<int>>::iterator iter = result.begin(); iter != result.end(); ++iter)
			{

				for (int j = 0; j < iter->size(); j++)
				{
					vector<int> tmp = *iter;
					tmp.insert(tmp.begin() + j, i);
					result_c.push_back(tmp);
				}
				vector<int> tmp = *iter;
				tmp.push_back(i);
				result_c.push_back(tmp);
			}
			result.clear();
			result = result_c;

			if (unused.size() != 0)
			{
				permuteCore(result, unused);
			}
		}

	}
};


class Solution139 {
public:



	bool wordBreak(string s, vector<string>& wordDict) {

		return wordBreakCore(s, wordDict);
	}
	bool wordBreakCore(string s, vector<string>& wordDict)
	{


		vector<int> result(s.size(), 0);
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = 0; j < wordDict.size(); j++)
			{
				if ( (i != 0 && result[i - 1] == 1) || i==0 )
				{
					if (wordDict[j].size() + i <= s.size() && s.substr(i,wordDict[j].size()) == wordDict[j])
					{
						result[i + wordDict[j].size() - 1] = 1;
					}
					
				}

			}
		}


		return result.back();
	}

};

struct TreeNode
{
	TreeNode*  left;
	TreeNode* right;
	int val;
};

//二叉树中最大路径的和
class Solution124 {
public:

	int maxPathSum(TreeNode* root) {

		if (root == NULL)
			return 0;
		int max = root->val;
		maxPathSumCore(root, max);
		return max;
	}
	/*
	对于一个根节点，其最大值max()有三种情况：
	1. result = val
	2. result = val + max(left)
	3. result = vla + max(right);

	判断以当前节点为根结点的子树中的最大路径为：
	1. max = val
	2. max = val + max(left)
	3. max = val + max(right);
	4. max = val + max(left) + max(right);
	*/
	int maxPathSumCore(TreeNode* root, int &max)
	{
		TreeNode* left = root->left;
		TreeNode* right = root->right;
		int n_r = 0;
		int n_l = 0;
		int result = 0;
		if (left == NULL && right == NULL)
		{
			result = root->val;
		}

		if (left == NULL && right != NULL)
		{
			n_r = maxPathSumCore(right, max);
			if (n_r < 0)
			{
				result = root->val;
			}
			else
			{
				result = root->val + n_r;
			}
		}
		if (right == NULL && left != NULL)
		{
			n_l = maxPathSumCore(left, max);
			if (n_l < 0)
			{
				result = root->val;
			}
			else
			{
				result = root->val + n_l;
			}
		}
		if (right != NULL && left != NULL)
		{
			n_r = maxPathSumCore(right, max);
			n_l = maxPathSumCore(left, max);
			int max_c = n_r > n_l ? n_r : n_l;
			if (max_c < 0)
			{
				result = root->val;
			}
			else
			{
				result = root->val + max_c;
			}
		}


		if (root->val + n_l + n_r > max)
		{
			max = root->val + n_l + n_r;
		}

		if (root->val + n_l > max)
		{
			max = root->val + n_l;
		}
		if (root->val + n_r > max)
		{
			max = root->val + n_r;
		}
		return result;
	}


};



//对不同的函数可构建main函数体
int main(){
	//string s = "aaa";
	
	//string t = "ab*a*c*a";
    //std::cout << isMatch(s.c_str(), t.c_str());

	string str = "ab";


	string s_a[] = { "a", "b" };
	vector<string> a;
	for (int i = 0; i < 2; i++)
	{
		a.push_back(s_a[i]);
	}

	Solution139 s;
	std::cout << s.wordBreak(str, a) << std::endl;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
