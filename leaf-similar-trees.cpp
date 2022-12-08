class Solution {
public:
   vector<int>v1;
   vector<int>v2;

    void traverse1(TreeNode*root1){
         if(root1==NULL)return;
       if(root1->left==NULL and root1->right==NULL){
          v1.push_back(root1->val);
          return;
       }

        traverse1(root1->left);
        traverse1(root1->right);
   }


   void traverse2(TreeNode*root2){
       
        if(root2==NULL)return;
       if(root2->left==NULL and root2->right==NULL){
          v2.push_back(root2->val);
          return;
       }
        traverse2(root2->left);
        traverse2(root2->right);
   }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
         
         traverse1(root1);
         traverse2(root2);

         return v1 == v2;
        
    }
};
