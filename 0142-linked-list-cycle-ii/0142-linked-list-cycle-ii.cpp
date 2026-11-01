class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    ListNode*Slow = head;
    ListNode*fast = head;  
    while(fast && fast->next){
        Slow = Slow->next;
        fast = fast->next->next;

        if (Slow == fast){ 
        Slow = head;
        while(Slow!= fast){
            Slow = Slow->next;
            fast = fast->next;

        }
        return Slow;



        }
    }  
    return NULL;
        
    }
};