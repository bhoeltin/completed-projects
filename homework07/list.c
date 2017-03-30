/* list.c */

#include "list.h"

/* Internal Function Prototypes */

static struct node*	reverse(struct node *curr, struct node *next);
static struct node *	msort(struct node *head, node_compare f);
static void		split(struct node *head, struct node **left, struct node **right);
static struct node *	merge(struct node *left, struct node *right, node_compare f);

/**
 * Create list.
 *
 * This allocates a list that the user must later deallocate.
 * @return  Allocated list structure.
 */
struct list *	list_create() {
  
   return calloc(1, sizeof(struct node));
}

/**
 * Delete list.
 *
 * This deallocates the given list along with the nodes inside the list.
 * @param   l	    List to deallocate.
 * @return  NULL pointer.
 */
struct list *	list_delete(struct list *l) {

  node_delete(l->head,true);
  free(l);

    return NULL;
}

/**
 * Push front.
 *
 * This adds a new node containing the given string to the front of the list.
 * @param   l	    List structure.
 * @param   s	    String.
 */
void		list_push_front(struct list *l, char *s) {

  l->head = node_create(s, l->head);
  if(l->size == 0) l->tail = l->head;
 
 (*l).size++;

}

/**
 * Push back.
 *
 * This adds a new node containing the given string to the back of the list.
 * @param   l	    List structure.
 * @param   s	    String.
 */
void		list_push_back(struct list *l, char *s) {  

  struct node *newNode = node_create(s, NULL);

  if(l->tail){
    l->tail->next = newNode;
  }

  l->tail = newNode;
  if (l->size == 0) l->head = newNode;
  
  (*l).size++;

}

/**
 * Dump list to stream.
 *
 * This dumps out all the nodes in the list to the given stream.
 * @param   l	    List structure.
 * @param   stream  File stream.
 */
void		list_dump(struct list *l, FILE *stream){
  
  struct node*iter = l->head;


  while(iter != NULL){
    node_dump(iter,stream);
    iter = iter->next;
  }

}

/**
 * Convert list to array.
 *
 * This copies the pointers to nodes in the list to a newly allocate array that
 * the user must later deallocate.
 * @param   l	    List structure.
 * @return  Allocate array of pointers to nodes.
 */
struct node **	list_to_array(struct list *l) {

  struct node ** nodeArray;
  nodeArray = (struct node **) malloc(l->size * sizeof(struct node*));

  struct node*iter = l->head;
  int i = 0;
  if (iter == NULL){
    return NULL;
  }


  while (iter != NULL){
    nodeArray[i] = iter;
    iter = iter->next;
    i++;
  }

  return nodeArray;
}

/**
 * Sort list using qsort.
 *
 * This sorts the list using the qsort function from the standard C library.
 * @param   l	    List structure.
 * @param   f	    Node comparison function.
 */
void		list_qsort(struct list *l, node_compare f) {

  if (l->size <= 1) return; 

  struct node ** listArray;
  
  listArray = list_to_array(l);

  qsort(listArray, (*l).size, sizeof(struct node*), f);


  for (int i = 0; i < (*l).size -1; i++){
    (*listArray[i]).next = listArray[i+1];
  }

  (*l).head = listArray[0];
  (*l).tail = listArray[(*l).size - 1];
  l->tail->next = NULL;


  free(listArray);

}

/**
 * Reverse list.
 *
 * This reverses the list.
 * @param   l	    List structure.
 */
void		list_reverse(struct list *l) {

  struct node * prev = NULL;
  struct node * current = l->head;

  l->head = reverse(current,prev);
  while(current->next){
    current = current->next;
  }
  l->tail = current;

}
/**
 * Reverse node.
 *
 * This internal function recursively reverses the node.
 * @param   curr    The current node.
 * @param   prev    The previous node.
 * @return  The new head of the singly-linked list.
 */
struct node*	reverse(struct node *curr, struct node *prev) {
  struct node * tail;
  tail = curr;
  if(curr->next){
    tail = reverse(curr->next ,curr);
  }
  curr->next = prev;
  return tail;
}

/**
 * Sort list using merge sort.
 *
 * This sorts the list using a custom implementation of merge sort.
 * @param   l	    List structure.
 * @param   f	    Node comparison function.
 */

void		list_msort(struct list *l, node_compare f) {
  
  l->head = msort(l->head,f);

  struct node * iter = l->head;
  while(iter->next) iter = iter->next;

  l->tail = iter;

}


/**
 * Performs recursive merge sort.
 *
 * This internal function performs a recursive merge sort on the singly-linked
 * list starting with head.
 * @param   head    The first node in a singly-linked list.
 * @param   f	    Node comparison function.
 * @return  The new head of the list.
 */
struct node *	msort(struct node *head, node_compare f) {

  struct node * left = head;
  struct node * right = head;

  if (head->next == NULL) return head;
  split(head, &left, &right);
  left = msort(left,f);
  right = msort(right,f);
  head = merge(left,right,f);
  return head;
}

/**
 * Splits the list.
 *
 * This internal function splits the singly-linked list starting with head into
 * left and right sublists.
 * @param   head    The first node in a singly-linked list.
 * @param   left    The left sublist.
 * @param   right   The right sublist.
 */
void		split(struct node *head, struct node **left, struct node **right) {

  struct node * fast = head;
  struct node * slow = head;
  struct node * tail = head;

  if(!head || !(head->next)){
    *left = head;
    *right = NULL;
  }
  else{
    while (fast){
      fast = fast->next;
      slow = slow->next;
      if (tail->next != slow) tail = tail->next;
      if (fast){
	fast = fast->next;
      }

    }
  }

 *left = head;
 tail->next = NULL;
 *right = slow;

}

/**
 * Merge sublists.
 *
 * This internal function merges the left and right sublists into one ordered
 * list.
 * @param   left    The left sublist.
 * @param   right   The right sublist.
 * @param   f	    Node comparison function.
 * @return  The new head of the list.
 */
struct node *	merge(struct node *left, struct node *right, node_compare f) {
  
  struct node * answer = NULL; 
  if (!right) return left;
  if (!left) return right;

  if (f(&left,&right) < 0){
    answer = left;
    answer->next = merge(left->next, right,f);
  }
  else{
    answer = right;
    answer->next = merge(left, right->next,f);
  }
  return answer;
 


}
