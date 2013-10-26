# Sorting Algorithms in C++

To compile:  
> g++ sorts.cpp 

To run:
> ./a.out  

## Common Sorts
__Merge sort__:  
* Advantages: suitable for linked list, suitable for external sort.
* Disadvantages: need extra buffer holding the merged data.  

__Insertion/Selection sort__:  
* Advantages: easy to implement.
* Disadvantages: too slow and become impractical when data is huge.

__Heap sort__:  
* Advantages: don't need recursion. Suitable for large data.
* Disadvantages: usually slower than merge sort and quick sort.
 
__Quick sort__: 
* Advantages: practical fastest.
* Disadvantages: recursive, worst case too slow.
