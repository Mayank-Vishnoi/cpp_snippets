// Using queues (costly push)
template <typename T> 
struct stack {
   int cur_size;
   queue<T> q1, q2;

   stack () : cur_size(0) {}

   void push (T x) {
      q2.push(x);
      while (!q1.empty()) {
         q2.push(q1.front());
         q1.pop();
      }
      q1.swap(q2);
      cur_size++;
   }

   T top () {
      return q1.front();
   }

   void pop () {
      q1.pop();
      cur_size--;
   }

   int size () {
      return cur_size;
   }

   bool empty () {
      return (cur_size == 0);
   }
};


// Using array
template <typename T> 
struct stack {
   int tp; //keeps track of the most recently inserted element
   T* arr;
   int capacity;

   public:
      stack () {
         tp = -1;
         capacity = (int)1e5;
         arr = new T[capacity];
      }

   void push (T x) {
      tp++;
      arr[tp] = x;
      // if tp == size - 1, then stack overflow error 
   }

   T top () {
      return arr[tp]; // if tp == -1, then should throw default error
   }

   void pop () {
      tp--; // equivalent to removal as we care about recently entered.
   }

   int size () {
      return (tp + 1);
   }

   bool empty () {
      return (tp == -1);
   }
};


// Using linked list
template <typename T> 
struct stack {
   struct node {
      T data;
      node* next;
   };

   node* first;
   int cur_size;

   public:
      stack() {
         cur_size = 0;
         first = new node;
      }

   void push (T x) {
      node* oldfirst = first;
      first = new node;
      first->data = x;
      first->next = oldfirst;
      cur_size++;
   }

   T top () {
      return first->data;
   }

   void pop () {
      first = first->next;
      cur_size--;
   }

   int size () {
      return cur_size;
   }

   bool empty () {
      return (cur_size == 0);
   }
};
