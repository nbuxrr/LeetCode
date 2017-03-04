// No2_Add_tow_number.cpp

/**
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Subscribe to see which companies asked this question.
 */


#include <iostream>
using namespace std;

//  Definition for singly-linked list.
struct ListNode
{
  	int val;
 	ListNode *next;
 	ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    static ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
    {
    	ListNode *phead = new ListNode(0);
    	ListNode *pcur = phead;
    	int isum = 0;
    	int iadd = 0;

    	while (l1 != NULL || l2 != NULL)
    	{	
    		if (l1 == NULL)
    		{
    			isum = l2->val + iadd;
    			l2 = l2->next;
    		}
    		else if (l2 == NULL)
    		{
    			isum = l1->val + iadd;
    			l1 = l1->next;
    		}
    		else
    		{
    			isum = l1->val + l2->val + iadd;
    			l1 = l1->next;
    			l2 = l2->next;
    		}

    		iadd = (int)(isum / 10);
    		pcur->next = new ListNode(isum % 10);
    		pcur = pcur->next;

    	}

		if (iadd > 0)
		{
			pcur->next = new ListNode(iadd);
		}

		ListNode *pret = phead;

		if (phead->next != NULL)
		{
			pret = phead->next;
			delete phead;
            phead =  NULL;
		}

        return pret;
    }
};

void printListNode(ListNode *l)
{
	if (l == NULL)
	{
		cout << "list is null";
	}
	else
	{
		cout << l->val;
		l = l->next;

		for (; l != NULL; l = l->next)
		{
			cout << " -> " << l->val;
		}

		cout << endl;
	}
}

int main(int argc, char **argv)
{
	ListNode *l1 = new ListNode(3);
	ListNode *l2 = new ListNode(9);

	ListNode *pret = Solution::addTwoNumbers(l1, l2);
	printListNode(pret);	
	return 0;
}