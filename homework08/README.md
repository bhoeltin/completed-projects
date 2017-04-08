Homework 08
===========

1. In entry_create I allocated memory for an entry struct, meaning enough space for all the variables that the struct holds. I used calloc because all the values would be initially set to zero. This includes a pointer to the next entry, the type of value that the entry holds, the actual value which is held in a Value union, and a char * to hold the key. Enough space for all of these was allocated in entry_create. Then in entry_delete, if there was a recursive flag, the entry itself would be dealloacted and the one next to it until there were no more next values. Additionally, the fact that strdup was used meant that the space for key and value string had to be freed as well. 

2. The memory allocated in map_create alloacated enough space for one map struct and its variables. Again I used calloc so that all the values would be initialized to null. The map struct holds an array of entries, a size and capacity variable, and a load factor. All of these were allocated for then deallocated in map_delete. Map_delete went through each bucket and recursively called entry_delete, freed the space for m->buckets, and freed the space for the map struct.

3. In map_resize a new set of buckets with the new capacity is allocated. The function then proceeds to parse the old maps buckets for entries so that they can be moved to the new buckets. This is accomplished with two pointers that keep track of an entries next value as well as the value of the entries corresponding new buckets next value. The new bucket for the entry is calculated using the fnv_hash function and moding it with the new capacity. The function will push back each entry from the old list into its new bucket in the new buckets array. The entries pointers are updated and so are the buckets next pointers. At the end, the size and capacity of the map are updated and the old buckets are freed.

4. Map insert first searches to see if a key is already inserted into the map. If so, it will just update the value at that key with entry_update. If not, the function will create a new entry node and push it to the back of its corresponding bucket. At the beginning of the function, there is a check to make sure that there is enough room in the map to insert the entry. If there is no, then it calls the resize function to resize the map accordingly. The time complexity of this function is O(n) average and worst and the space comlexity is O(n).
 
5. Map search takes the key passed in and hashes it so that it can look in one bucket to see if the key is already in the map. Each entry in the bucket is searched and if the key is found a pointer to that entry is returned. The function returns NULL if the key isnt found. The average and worst time complexity of the function is O(n) and the space complexity is O(n).

6. Map remove takes the key passed to it and hashes it to get the correct bucket to go into to delete the entry. Each entry in the bucket is looked through. If the entry is found at the front of the list, then the bucket locations next pointer has to be update to point to the entry being removed's next value. Otherwise, the entry's next value is linked to the entrys previous value so that their is no lost data. The size is decremented and the entry is deleted. If no entry is removed, the function returns false. The time complexity is O(n) and the space complexity is O(n).





Benchmark
=========
1. I found that the lower the load factor, the faster the program went due to the constant resizing of the list making it easier to find keys in the table to insert. However, as load factor increased, the program took up less space. The time did increase though as space went slower. I thought that both space and time would decrease as the load factor increased and I was suprised that with the program taking up less space, it went slower. I just assumed less space meant less places to sort through. However, it seems that this is actualyl a disadvantage with a map as the more buckets, the easier it is to locate data in a quick and efficient manner. 

2. The hash table has a little bit slower of a time complexity than the treap as the treap will always bee balanced, a hash may not be. The treap is very easy to implement compared to the hash table. The time complexity of the treap is always guaranteed. Therefore, they could be very useful in situations where a steady time constant is needed. I would most likely use a hash in the future instead of a treap because I do not like the randomness of the treap. I like the format of the hash and its layout makes a lot of sense to me.
