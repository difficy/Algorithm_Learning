/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {//处理没有头节点的情况
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr) {
            if (n + 1 <= 0) {//找出待删除节点的前一个节点
                slow = slow->next;
            }
            fast = fast->next;
            n--;
        }
        if (n == 0) {//处理待删除节点为头节点的情况
            fast = head;
            head = head->next;
        }
        else {
            fast = slow->next;
            slow->next = fast->next;
        }
        delete fast;//释放被删除节点
        return head;
    }
};