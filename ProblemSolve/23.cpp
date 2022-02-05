/************************
 * Merge K Sorted Lists *
 ************************/

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
    struct Compare{
        bool operator()(pair<int, ListNode*> a, pair<int, ListNode*> b){
            return a.first > b.first;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode();
        ListNode* pointer = ans;
        
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, Compare> pq;
        
        for(int i=0; i<lists.size(); ++i){
            if(lists[i] != NULL){
                pq.push(make_pair(lists[i]->val, lists[i]));
            }
        }
        
        while(!pq.empty()){
            pair<int, ListNode*> minimumListNVal = pq.top();
            pq.pop();
            pointer->next = new ListNode(minimumListNVal.second -> val);
            pointer = pointer -> next;
            minimumListNVal.second = minimumListNVal.second->next;
            
            if(minimumListNVal.second != NULL){
                pq.push(make_pair(minimumListNVal.second -> val, minimumListNVal.second));
            }
        }
        
        return ans->next;
    }
};