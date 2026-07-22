class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> map;
        map[nullptr]=nullptr;
        Node* curr=head;
        while(curr){
            if(map.find(curr)==map.end()){
                map[curr]=new Node(curr->val);
            }
            map[curr]->val=curr->val;
            if(curr->next && map.find(curr->next)==map.end()){
                map[curr->next]=new Node(curr->next->val);
            }
            map[curr]->next=map[curr->next];
            if(curr->random && map.find(curr->random)==map.end()){
                map[curr->random]=new Node(curr->random->val);
            }
            map[curr]->random=map[curr->random];
            curr=curr->next;
        }
        return map[head];
    }
};