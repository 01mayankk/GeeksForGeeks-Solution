/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        // code here
        Node* temp = head ;
        
        vector<Node*>v;
        while(temp != nullptr)
        {
            v.push_back(temp);
            temp = temp -> next;
            
        }
        
        if(v.size() < k)
        {
            return -1;
        }
        
        return v[v.size() - k]-> data;
    }
};