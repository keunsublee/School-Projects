depth d = 2^d leaves

c log N 
log^2 N
N
N log N
N^2
2^N


N LOG N
Heapsort
Introsort = STD Sort = QuickSort + HeapSort + InsertionSort
MergeSort


N^2
Insertion
Selection
Bubble


QuickSort
SelectionSort
BubbleSort
InsertionSort
CountingSort



N
buildheap
heapify
insert


O(1)    Insert Delete Find Lookup
Hashmap
UnorderedMap
Map
Set
UnorderedSet
Multimap
Multiset




2)Implement the following function that "partitions" a list of integers so that all integers less than or equal to x are before all integers greater than x. Do this by iterating through the list and moving all integers greater than x to the back of the list: [20 pts]
void Partition(std::list<int> &nums, const int x) {
    auto it = nums.begin();

    while (it != nums.end()) {
        if (*it > x) {
            // Move the element to the end of the list
            nums.push_back(*it);
            // Erase the element from its current position
            it = nums.erase(it);
        } else {
            ++it;
        }
    }
}



 
Multimaps use trees, typically self-balancing (BST, AVL tree, red-black tree, or just tree all OK)

 
Priority queues use vector implementation of binary heaps (heap, vector, array, deque all OK)
 
Sets use trees, typically self-balancing (BST, AVL tree, red-black tree, or tree  )
 
Unordered maps use hash maps (hash table or  hash )


insertion sort ADV
Simple / no overhead, no recursive calls, no memory allocation, no setup, faster than other "simple" sorts, in-place, stable.

open addressing
No extra memory required, better cache efficiency, quicker to iterate through



STEP 1)
Optimal way to store names in file: hash-based data structure for O(1) lookup. Do this BEFORE they start joining. Map is not needed - only unordered set of names.
 
Good description and analysis of how you store and search names from file using hash correctly. Key must be names, not join order.
 
Partial credit for storing and searching names.
 
STEP 2)
Optimal way to store ordered list of admitted guests as they join: array/vector, or other method with O(1) insert and O(1) random access.
 
Good description and analysis of how you store and retrieve ordered list of guests who attended.
 
Partial credit for storing ordered list of guests.
 
ALT)
Acceptable alternative approach for one of the steps
 
Suboptimal alternative approach for one of the steps
 
ANALYSIS)
Correct and thorough overall analysis: O(1) lookup in hash for O(n) total to check all guests who come in. O(1) push_back on vector for O(n) total to build ordered list of guests. O(1) to access each 100th element for O(n) to print out each 100th guest. Total O(n) + O(n) + O(n) = O(n).
  