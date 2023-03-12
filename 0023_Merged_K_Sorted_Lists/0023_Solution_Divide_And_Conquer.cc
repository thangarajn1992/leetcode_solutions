/* 
Divide and Conquer Approach:
We don't need to traverse most nodes many times repeatedly
Pair up k lists and merge each pair.
After the first pairing, k lists are merged into k/2 lists with average 2N/k length, then k/4,, k/8 and so on.


Repeat this procedure until we get the final sorted linked list.
Thus, we'll traverse almost N nodes per pairing and merging, and repeat this procedure about log⁡2k times.

Time: O(N logK), K is the number of lists
Space: O(1)
*/

#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
   ListNode* mergeTwoLists(ListNode* l1, ListNode *l2)
   {
       ListNode dummy = ListNode(0);
       ListNode *prev = &dummy;

       while(l1 != nullptr && l2 != nullptr)
       {
           if(l1->val <= l2->val)
           {
               prev->next = l1;
               l1 = l1->next;
           }
           else
           {
               prev->next = l2;
               l2 = l2->next;
           }
           prev = prev->next;
       }
       prev->next = (l1 != nullptr) ? l1 : l2;
      
       return dummy.next;
   }

   ListNode* mergeKLists(vector<ListNode*>& lists) {
       int length = lists.size();
      
       if(length == 0)
           return nullptr;

       int interval = 1; // Start with interval 1, and * by 2 each loop
       while(interval < length)
       {
           for(int i = 0; i+interval < length; i += (interval * 2))
           {
               lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
           }
           interval *= 2;
       }

       return lists[0];
   }
};