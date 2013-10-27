# Sorting Algorithms in C++

To compile:  
> g++ sorts.cpp 

To run:
> ./a.out  

##Implemented Sorting Algorithms
- Insertion sort: O(n<sup>2</sup>)
- Selection sort: O(n<sup>2</sup>)
- Bubble sort: O(n<sup>2</sup>)
- Merge sort: O(n log n)
- Quick sort: O(n log n)
- Counting sort: O(3n + k)
- Radix sort: O (pn + pk )

## Common Sort Advantages and Disadvantages
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

## Resources
[Mastering Algorithms in C by Kyle Loudon](http://www.das.ufsc.br/~romulo/discipli/cad-fei/Mastering-Algorithms-with-C-Loudon.pdf)    
The Algorithm Design Manual by Steven S. Skiena