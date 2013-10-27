/* *
 * Computer Science fundamentals: Sorting
 * Common sorting algorithms in C++
 *
 * @Author: Alyssa Quek 2013
 *
 */

#ifndef SORTS_H
#define SORTS_H
 
#include <vector>

class Sorter {
 public:
  /* Insertion sort: O(n^2)
  Start from the beginning and in each iteration,
  find the location the current element belongs within the sorted array.
  The elements to the left are kept sorted.
  */
  void insertionSort(std::vector<int> &items);

  /* Selection sort: O(n^2)
  Keep finding the min item O(n)
  push it into a sorted array and delete.
  Heapsort: Use a prioirity queue and speed it to O(n log n)
  Find and delete takes O(log n) instead of O(n) 
  Its best application is for incremental sorting on small sets of data.
  */
  void selectionSort(std::vector<int> &items);

  /* Bubble sort: O(n^2)
  Repeatedly traverse through the list, comparing each pair of 
  adjacent items and swapping them if they are in the wrong order.
  */
  void bubbleSort(std::vector<int> &items);

  /* Merge sort: O(n log n). Space: 2 arrays: O(n)
  Twice the storage of quick sort.
  1) Divide the unsorted list into n sublists, 
     each containing 1 element (a list of 1 element is considered sorted).
  2) Repeatedly merge sublists to produce new sublists until 
     there is only 1 sublist remaining. This will be the sorted list.
  Best application is for very large sets of data because it inherently
  facilitates working with divisions of the original unsorted set.
  */
  void mergeSort(std::vector<int> &items);

  /* Quick sort: O(n log n). Space: 1 array: O(n)
  Select a random item from n items to sort.
  Separate n-1 other items into two piles: 
  A left pile before rand in sorted order
  A right pile after rand in sorted order.
  Its best application is for medium to large sets of data.
  */
  void quickSort(std::vector<int> &items);

  /* Counting sort: O(3n + k). Space: 3 arrays: O(2n + k)
  where k is the largest integer value in the set + 1
  A stable, linear-time sorting algorithm that works 
  with integers for which we know the largest value. 
  Its primary use is in implementing radix sort.
  */
  void countingSort(std::vector<int> &items, int exp, int k);

  /* Radix sort: O (pn + pk). Space: 3 arrays: O(2n + k)
  where p = num digit positions and k = the radix
  A linear-time sorting algorithm that sorts elements digit by digit.
  Suited to elements of a fixed size that can be conveniently 
  broken into pieces, expressible as integers.
  */
  void radixSort(std::vector<int> &items);
};

#endif