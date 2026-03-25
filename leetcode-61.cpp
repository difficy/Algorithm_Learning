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
//遍历一遍，计数，将链表化为环，将左移k位转换为头节点移动n位，将链表断开，即可
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        }
        ListNode* p = head;
        int count = 1;
        while (p->next != nullptr) {
            p = p->next;
            count++;
        }
        if (count > k) {
            count = count - k;
        }
        else {
            k = k % count;
            count = count - k;
        }
        p->next = head;
        while (count != 0) {
            if (count == 1) {
                ListNode* q = head;
                head = head->next;
                q->next = nullptr;
                break;
            }
            head = head->next;
            count--;
        }
        return head;
    }
};