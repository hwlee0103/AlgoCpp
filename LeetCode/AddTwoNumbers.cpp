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
#include <List>
#include <cstring>

using namespace std;

class Solution {
public:
    int getListCount(ListNode* head) {
        int count;
        
        ListNode * tmp = head;
        
        while(tmp != NULL) {
            count++;
            tmp = tmp->next;
        }
        
        return count;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer;
        
        //올림수
        int tenNum = 0;
        int minIdx = min(getListCount(l1), getListCount(l2));
        
        for(int i = 0; i < minIdx; ++i) {
            answer[i] = (l1[i] + l2[i] + tenNum)%10;
            tenNum = (l1[i] + l2[i] + tenNum)/10;
        }
        
        if(l1.length() > minIdx) {
            for(int i = 0; i < l1.length() - minIdx; ++i) {
                answer[minIdx + i + 1] = (l1[minIdx + i + 1] + tenNum)%10;
                tenNum = (l1[minIdx + i + 1] + tenNum)/10;
            }
        } else {
            for(int i = 0; i < l2.length() - minIdx; ++i) {
                answer[minIdx + i + 1] = (l2[minIdx + i + 1] + tenNum)%10;
                tenNum = (l2[minIdx + i + 1] + tenNum)/10;
            }
        }
        
        return answer;
    }
};