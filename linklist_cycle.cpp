class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(head==NULL){
            return false;
        }
        
        
        
        ListNode* first = head;
        ListNode*second = head;
            
      
        
        while(second!=NULL and second->next!=NULL){
        
            first = first->next;
            second = second->next->next;
            
            if(first == second){
                return true;
            }
        }
        
        return false;
    }
};
