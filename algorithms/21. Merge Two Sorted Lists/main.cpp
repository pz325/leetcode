/**
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(0) {}
};

class Solution
{
  public:
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode head = ListNode(0);
        ListNode* curr = &head;
        while (l1 || l2) {
            if (!l1) {
                curr->next = l2;
                break;
            }

            if (!l2) {
                curr->next = l1;
                break; 
            }

            if (l1->val <= l2->val){
                curr->next = l1;
                l1 = l1->next;
            } 
            else 
            {
                curr->next = l2;
                l2 = l2->next;
            }

            curr = curr->next;
        }

        return head.next;
    }
};

void printList(ListNode *l)
{
    if (!l) return;
    while (true) {
        std::cout << l->val;
        l = l->next;
        if (l) 
        {
            std::cout << " -> ";
        }
        else
        {
            break;
        }
    }
    std::cout << std::endl;
}

int main()
{
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(4);
    ListNode l4(1);
    ListNode l5(3);
    ListNode l6(4);
    l2.next = &l3;
    l1.next = &l2;
    l5.next = &l6;
    l4.next = &l5;

    printList(&l1);
    printList(&l4);
    Solution solution;
    auto ret = solution.mergeTwoLists(&l1, &l4);
    printList(ret);
}