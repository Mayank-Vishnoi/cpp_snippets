// Erase has not been implemented yet

#define RED true
#define BLACK false

struct node {
   int k; // nodes are stored essentially as keys smaller keys on left and so on, and each node holds a value. 
   int v;   // value
   node* l; // left child 
   node* r; // right child
   bool color; // color of parent link.
}; 

node* newnode(int key, int value, bool color) { // helper method
   node* p = new node;
   p->k = key;
   p->v = value;
   p->l = nullptr;
   p->r = nullptr;
   p->color = color;
   return p;
}

node* root; // represents a BST tree

int find (int key) {
   // get the value corresponding to a key.
   node* cur = root;
   while (cur != nullptr) {
      if (key > cur->k) {
         cur = cur->r;
      } else if (key < cur->k) {
         cur = cur->l;
      } else {
         return cur->v;
      }
   }
   return -1;
}

bool isRed (node* x) {
   if (x == nullptr) {
      return false; // null links are black
   } else {
      return x->color == RED;
   }
}

node* rotateLeft (node* h) {
   // Local operation to fix right leaning red-link
   // Maintains symmetric order and perfect black balance
   assert(isRed(h->r));
   node* x = h->r;
   h->r = x->l;
   x->l = h;
   x->color = h->color;
   h->color = RED;
   return x;
}

node* rotateRight (node* h) {
   // To change temporary orientation of the link.
   assert(isRed(h->l));
   node* x = h->l;
   h->l = x->r;
   x->r = h;
   x->color = h->color;
   h->color = RED;
   return x;
}

void flipColors (node* h) {
   // recolor to split a temporary 4-node
   assert(!isRed(h));
   assert(isRed(h->l));
   assert(isRed(h->r));
   h->color = RED;
   h->l->color = BLACK;
   h->r->color = BLACK;
}

node* insert (node* h, int key, int value) {
   // Recursive implementation for simplicity, otherwise lot's of cases for double rotate left and right and stuff
   if (h == nullptr) {
      return newnode(key, value, RED);  
   }
   if (h->k < key) {
      h->l = insert(h->l, key, value);
   } else if (h->k > key) {
      h->r = insert(h->r, key, value);
   } else {
      h->v = value;
   }
   if (isRed(h->r) && !isRed(h->l)) { // lean-left
      h = rotateLeft(h);
   }
   if (isRed(h->l) && isRed(h->l->l)) { // balance 4-node, sequential potential scenarios, we'll deal with this after we return, convince yourself, quite remarkable actually.
      h = rotateRight(h);
   }
   if (isRed(h->l) && isRed(h->r)) { // split 4-node
      flipColors(h);
   }
   return h;
} 
