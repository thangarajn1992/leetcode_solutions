/*
Divide And Conquer Approach:
Insert all the list nodes into the min priority queue and pop them one by one and create a new sorted list.
Time: O(NlogK)
Space: O(K)
where K is the number of lists
*/


#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct CompareNode {
   bool operator()(const ListNode* l, const ListNode* r) {
       return l->val > r->val;
   }
};

class Solution {
public:
   ListNode* mergeKLists(vector<ListNode*>& lists) {
       priority_queue<ListNode*, vector<ListNode*>, CompareNode> pq;
       for(ListNode* list : lists)
       {
           while(list != nullptr)
           {
               pq.push(list);
               list = list->next;
           }
       }

       ListNode *dummy = new ListNode(0);
       ListNode *prev = dummy;
       while(pq.empty() == false)
       {
           ListNode *top = pq.top(); pq.pop();
           prev->next = top;
           top->next = nullptr;
           prev = prev->next;
       }
       return dummy->next;
   }
};