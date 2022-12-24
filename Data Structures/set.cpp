// A binary search tree implementation. 
// O(logN) average search time, but the worst is O(N) as the tree is not balanced
struct node {
   int v;   // value
   node* l; // left child / subtree
   node* r; // right child
};

node* root; // represents a BST tree

node* makenode (int x) { // helper method
   node* p = new node;
   p->v = x;
   p->l = nullptr;
   p->r = nullptr;
   return p;
}

void insert (int x) {
   if (!root) {
      root = makenode(x);
      return;
   }
   node* cur = root;
   while (true) {
      if (x < cur->v) {
         if (cur->l == nullptr) {
            cur->l = makenode(x);
            break; // insertion completed
         } else {
            cur = cur->l;
         }
      } else {
         if (cur->r == nullptr) {
            cur->r = makenode(x);
            break;
         } else {
            cur = cur->r;
         }
      }
   }
}

node* find (int x) {
   node* cur = root;
   while (cur != nullptr) {
      if (x > cur->v) {
         cur = cur->r;
      } else if (x < cur->v) {
         cur = cur->l;
      } else {
         return cur;
      }
   }
   return nullptr;
}

bool erase (int x, node* parent = nullptr, node* n1 = root) {
   node* cur = n1;   
   while (cur != nullptr) {
      if (x < cur->v) { // search for value first
         parent = cur;
         cur = cur->l;
      } else if (x > cur->v) {
         parent = cur;
         cur = cur->r;
      } else {
         // 2 childs: replace with the smallest value in the right subtree of that node
         if (cur->l != nullptr && cur->r != nullptr) {
            node* tmp = cur->r;
            while (tmp->l != nullptr) {
               tmp = tmp->l;
            }
            cur->v = tmp->v;
            erase(cur->v, cur, cur->r); // this would just fall into one of the simpler cases.
            return true;
         } else if (cur->l != nullptr) { // one child: replace current node with that child
            if (!parent) {
               cur = cur->l;
               return true;
            }   
            if (parent->l == cur) {
               parent->l = cur->l;
            } else {
               parent->r = cur->l;
            }
            return true;
         } else if (cur->r != nullptr) {
            if (!parent) {
               cur = cur->r;
               return true;
            }   
            if (parent->l == cur) {
               parent->l = cur->r;
            } else {
               parent->r = cur->r;
            }
            return true;
         } else { // no childs: replace with null
            if (!parent) {
               cur = nullptr;
               return true;
            }   
            if (parent->l == cur) {
               parent->l = nullptr;
            } else {
               parent->r = nullptr;
            }
            return true;
         }
      }
   }
   return false; // value not found in BST
}  

// O(N) time, O(depth of the tree) space.
bool ValidateBST (node* n1, int minval = INT_MIN, int maxval = INT_MAX) {
   /*
   1. all nodes on its left subtree are smaller
   2. all on right are greater than or equal to its value
   3. both left and right subtrees are also valid BST's.
   */
   if (n1 == nullptr) {
      return true;
   }
   if (n1->v <= minval || n1->v > maxval) {
      return false;
   }
   bool f1 = ValidateBST(n1->l, minval, n1->v);
   bool f2 = ValidateBST(n1->r, n1->v, maxval);
   return (f1 && f2);
}

void inorder (node* n1) {
   if (n1->l != nullptr) {
      inorder(n1->l);  
   } 
   cout << n1->v << " "; 
   if (n1->r != nullptr) {
      inorder(n1->r);
   }
}

void pre_order (node* n1) {
   cout << n1->v << " "; 
   if (n1->l != nullptr) {
      pre_order(n1->l);  
   } 
   if (n1->r != nullptr) {
      pre_order(n1->r);
   }
}

void post_order (node* n1) {
   if (n1->l != nullptr) {
      post_order(n1->l);  
   } 
   if (n1->r != nullptr) {
      post_order(n1->r);
   }
   cout << n1->v << " "; 
}
