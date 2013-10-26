/* *
 * Computer Science fundamentals: Sorting
 * Common sorting algorithms in C++
 *
 * @Author: Alyssa Quek 2013
 *
 */

#ifndef SORTS_H
#define SORTS_H

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream> //stringstream
#include <string>
#include <assert.h>

class Sorter {
 public:
  /* Insertion sort: O(n^2)
  Start from the beginning and in each iteration,
  find the location the current element belongs within the sorted array.
  The elements to the left are kept sorted.
  */
  void insertionSort(std::vector<int>& items);

  /* Selection sort: O(n^2)
  Keep finding the min item O(n)
  push it into a sorted array and delete.
  Heapsort: Use a prioirity queue and speed it to O(n log n)
  Find and delete takes O(log n) instead of O(n) 
  */
  void selectionSort(std::vector<int> &items);

  /* Bubble sort: O(n^2)
  Repeatedly traverse through the list, comparing each pair of 
  adjacent items and swapping them if they are in the wrong order.
  */
  void bubbleSort(std::vector<int> &items);

  /* Merge sort: O(n log n)
  1) Divide the unsorted list into n sublists, 
     each containing 1 element (a list of 1 element is considered sorted).
  2) Repeatedly merge sublists to produce new sublists until 
     there is only 1 sublist remaining. This will be the sorted list.
  */
  void mergeSort(std::vector<int> &items);

  /* Quick Sort: O(n log n)
  Select a random item from n items to sort.
  Separate n-1 other items into two piles: 
  A left pile before rand in sorted order
  A right pile after rand in sorted order.
  */
  void quickSort(std::vector<int> &item);
};

#endif