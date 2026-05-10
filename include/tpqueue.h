// Copyright 2026 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
   static int getPrior(const T& item) {
     return item.prior;
   }
   void listCleaner() {
     Node* currn = root;
     while (currn != nullptr) {
       Node* next = currn->next;
       delete currn;
       currn = next;
     }
     root = nullptr;
   }
   struct Node {
     T value;
     Node* next;
     Node(const T& item) : value(item), next(nullptr) {}
   };
   Node* root;
 public:
   TPQueue() : root(nullptr) {}
   ~TPQueue() {
     listCleaner();
   }
   void push(const T& item) {
     Node* newbie = new Node(item);
     if (root == nullptr || getPrior(item) > getPrior(root->value)) {
       newbie->next = root;
       root = newbie;
       return;
     }
     Node* curr = root;
     while (curr->next != nullptr &&
       getPrior(curr->next->value) > getPrior(item)) {
       curr = curr->next;
     }
     newbie->next = curr->next;
     curr->next = newbie;
   }
   T pop() {
     if (root == nullptr) {
       throw "queue is empty(";
     }
     Node* oldRoot = root;
     T answer = root->value;
     root = root->next;
     delete oldRoot;
     return answer;
   }
};
struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
