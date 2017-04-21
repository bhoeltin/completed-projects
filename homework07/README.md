Homework 07
===========

Activity 1
==========

1. In node_create I allocated enough memory to hold the size of the struct node, 8 bytes for the char * that pointed to the stirng, 4 bytes for the int, and another 8 bytes for the pointer to the next node. This memory allocation was deallocated later in node_delete. If the recursive function was true, the delete function would delete one node and if it had a next node move on to that node and delete it. This would continue until the function hit NULL. One other thing that had to be accounted for was the fact that strdup made a copy of the original string and allocated memory for it, so that space also had to be freed.

2. In list_create, I used calloc so that every memory space would be initialized to zero and allocated the size of a struct node. To deal with each node in the list, I passed the head of the list to the node_delete function and made the recursive call true. Then I freed all the space originally allocated for the list via free(l). In this way each nodes allocation was fred as well as the list allocation. 

3. The l_qsort works by converting the linked list to an array then passing it to the qsort function to be sorted by the function specified by the original arguments of the qsort function. It then has to reassign the next values, head pointer, and tail pointer. The average time complexity of qsort is O(nlogn) and the worst is O(n^2). The space complexity is O(n).

4. The reverse function uses recursion to flip the pointers of the list to the other way around. This is done by pasing the current node and its previous node to reverse until the current node is equal to the last element. Once this happens, the next pointerof that element is changed to point to its previous node and the current node is returned. This continues until all the pointers have been returned. The time complexity of this is O(n) and the space complexity is O(1). 

5. The msort function has three steps: split, sort, and merge. The msort function is recursive and works to split the list up until it is eventually just single elements. Then the merge function will bring all the elements back together recursively until the list is sorted. The time complexity is O(nlogn) worst case and average case. The space complexity is O(n). 


Activity 2
=========


| NITEMS   | SORT     | TIME      | SPACE     |
| -------- | -------- |-----------|-----------|
|        1 | Merge    |    0.0009 |    0.0009 |
|        1 | Quick    |    0.0019 |    0.0009 |
|       10 | Merge    |    0.0009 |    0.0009 |
|       10 | Quick    |    0.0009 |    0.0019 |
|      100 | Merge    |    0.0009 |    0.0009 |
|      100 | Quick    |    0.0009 |    0.0009 |
|     1000 | Merge    |    0.0019 |    0.0019 |
|     1000 | Quick    |    0.0009 |    0.0019 |
|    10000 | Merge    |    0.0109 |    0.0109 |
|    10000 | Quick    |    0.0089 |    0.0089 |
|   100000 | Merge    |    0.1649 |    0.1479 |
|   100000 | Quick    |    0.1019 |    0.1139 |
|  1000000 | Merge    |    0.5449 |    0.5399 |
|  1000000 | Quick    |    1.4807 |    1.4687 |
| 10000000 | Merge    |    3.4274 |    3.2385 |
| 10000000 | Quick    |   20.4578 |   20.6368 |

1. The space and time complexity does not really change much until it gets to about 100000 elements. For small groups, the quick sort appears to use less space and less time, which is supprising as merge sort has an overall better time complexity. However once the lists get larger, you can tell that merge sort is the superior sorting algorithm. 

2. Although theoretical complexity is generally pretty accurate, it does not take into account the different process running on a machine or the processing ability of a machine. These can affect perfromance. Additionally, some algorithms are optimized for certain groups of data and work better with those groups. Their results might vary when they are not used in the right situations. Therefore it is important to know the strengths and weaknesses of an algorithm. 
