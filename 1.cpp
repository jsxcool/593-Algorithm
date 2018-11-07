#include<iostream>
#include<vector>
#include<climits>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;
        if(head->next->next==nullptr){
            ListNode* temp = head;
            head = head->next;
            head->next = temp;
            temp->next = nullptr;
            return head;
        }
        
        ListNode* iterator = head;
        while(iterator != nullptr);{
            ListNode* p = iterator;
            ListNode* q = iterator->next;
            static ListNode* end;
            
            ListNode* temp = p;
            p = q;
            p->next = temp;
            end = temp;
            
            if(q!=head)    
                end->next = p;
        
            if(iterator->next == nullptr)
                return head;
            iterator = iterator->next->next;
        } 
        
        return head;
}

int main(){
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head = swapPairs(head);
	for(ListNode* p=head; p!=nullptr; p=p->next)
		cout << p->val << ' ';
	cout << '\n';
	
}


