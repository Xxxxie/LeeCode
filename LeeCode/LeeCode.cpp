// LeeCode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

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

//leeCode(3)
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

//leeCode(4)
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

//leeCode(5)
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

//leeCode(6)
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

//leeCode(7)
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



//对不同的函数可构建main函数体
int main()
{
	string s = "A";

	char c[5];
	c[0] = '\0';
    std::cout << convert(s.c_str(),1);
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
