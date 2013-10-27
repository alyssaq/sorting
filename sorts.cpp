/**
    Sorting Algorithms in C++
    @Author: Alyssa Quek 2013
*/
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream> //stringstream
#include <string>
#include <assert.h>
#include <math.h>       /* pow */

#include "sorts.h"
using namespace std;
typedef std::vector<int>::iterator vecIter;

static int COUNTER = 1;

// print a vector
void printVector(const vector<int>& v) {
  copy(v.begin(), v.end() - 1, ostream_iterator<int>(cout, ", "));
  cout << *(v.end() - 1) << endl;
}

//concatenate vector into a string
string vector2string(const vector<int>& v) {
  ostringstream sstream;
  copy(v.begin(), v.end() - 1, ostream_iterator<int>(sstream, ", "));
  sstream << *(v.end() - 1);
  
  return sstream.str();
}

void assertAndPrint(const vector<int>& v, const string &s, string sortType) {
  string result = (vector2string(v) == s) ? "PASSED" : "FAILED";
  cout << COUNTER++ << ") " << sortType << " " << result << ": " << vector2string(v) << "\n";
}

void Sorter::insertionSort(vector<int>& items) {
  for(int i = 1; i < items.size(); i++) {
    int temp = items[i], j = i - 1;
    while (j >= 0 && (items[j] > temp)) {
      items[j+1] = items[j];
      j--;
    }
    items[j+1] = temp;
  }
}

void insertionSort_alternate(vector<int>& items) {
  int temp;
  for(int i = 1; i < items.size(); i++) {
    for (int j = 0; j < i; j++) {
      if (items[i] < items[j]) {
        swap(items[i], items[j]);
        continue;
      }
    }
  }
}

/* Used by selection sort */
int findAndDeleteMinItem(vector<int> &items) {
  vecIter min_iter = min_element(items.begin(), items.end());
  int min = *min_iter;
  items.erase(min_iter);

  return min;
}

void Sorter::selectionSort(vector<int> &items) {
  vector<int> sortedItems;
  for(int i = 0, size = items.size(); i < size; i++) {
    sortedItems.push_back(findAndDeleteMinItem(items));
  }

  items = sortedItems;
}

void Sorter::bubbleSort(vector<int> &items) {
  vecIter iterA, iterB;
  bool hasSwapped = true;

  while (hasSwapped) {
    hasSwapped = false;
    iterA = items.begin(), iterB = iterA + 1;
    for(; iterB != items.end(); iterA++, iterB++) {
      if (*iterA > *iterB) {
        swap(*iterA, *iterB);
        hasSwapped = true;
      }
    }
  }
}

/*
  Used by Merge sort: O(n log n)
  Using a temp vector to avoid recreating temp arrays during the split
 */
void mergeHelper(vector<int> &items, int start, int end, vector<int> &temp) {
  if (start + 1 == end) return; //base case: one item

  int i = 0;
  int len = (end - start);
  int mid = start + len / 2;
  //pointer index to the start of the left and right subarrays
  int lidx = start, ridx = mid;

  mergeHelper(items, start, mid, temp); //mergeSort first half
  mergeHelper(items, mid, end, temp);   //mergeSort second half

  for (i = 0; i < len; i++) {
    /* Check if there are items in the left to compare.
    If there are, compare the left with right.
    If there is nothing to compare in the right, just add the left
    */
    if (lidx < mid && (ridx == end || items[lidx] < items[ridx])) {
      temp[i] = items[lidx++];
    } else {
      temp[i] = items[ridx++];
    }
  }

  //Copy the temp sorted array back to the original items
  copy(temp.begin(), temp.begin() + len, items.begin() + start);
}

/*
  As per mergeHelper above but using C++ iterators
 */
void mergeHelperIterators(vector<int> &items, vecIter start, vecIter end, vector<int> &temp) {
  if (start + 1 == end) return; //base case: one item

  vecIter mid = start + (end - start) / 2;
  //pointer index to the start of the left and right subarrays
  vecIter liter = start, riter = mid;

  mergeHelperIterators(items, start, mid, temp); //mergeSort first half
  mergeHelperIterators(items, mid, end, temp);   //mergeSort second half

  temp.clear();
  for (vecIter iter = start; iter != end; iter++) {
    /* Check if there are items in the left to compare.
    If there are, compare the left with right.
    If there is nothing to compare in the right, just add the left */
    if (liter < mid && (riter == end || *(liter) < *(riter) )) {
      temp.push_back(*(liter++));
    } else {
      temp.push_back(*(riter++));
    }
  }

  //Copy the temp sorted array back to the original items
  copy(temp.begin(), temp.end(), start);
}

void Sorter::mergeSort(vector<int> &items) {
  vector<int> temp;
  // Uncomment 2 lines below for array implementation
  //temp.resize(items.size());
  //mergeHelper(items, 0, items.size(), temp);

  // Mergesort using iterators
  temp.reserve(items.size());
  mergeHelperIterators(items, items.begin(), items.end(), temp);
}

// Used by Quicksort
vecIter partition(vector<int> &items, vecIter start, vecIter rand) {
  vecIter divider = start; // divider iterator for the rand pivot element

  for (vecIter iter = start; iter < rand; iter++) {
    if (*iter < *rand) {
      swap(*iter, *divider);
      divider++;
    }
  }
  swap(*rand, *divider);

  return divider;
}

void quickSortHelper(vector<int> &items, vecIter start, vecIter rand) {
  if (start > rand) return; //base case: nothing to partition

  vecIter pivot = partition(items, start, rand);
  quickSortHelper(items, start,     pivot - 1);
  quickSortHelper(items, pivot + 1, rand     );
}

void Sorter::quickSort(vector<int> &items) {
  quickSortHelper(items, items.begin(), items.end() - 1);
}

void Sorter::countingSort(vector<int> &items, int exp = 1, int k = 100) {
  vector<int> sorted, counts; //size = largest value in items + 1
  counts.resize(k); //O(n)
  sorted.resize(items.size());

  //count occurrence of each integer in items: O(n)
  vecIter iter = items.begin();
  for (; iter != items.end(); iter++) {
    ++counts[(*iter/exp) % k];
  }
  //perform cumulative sum: O(k)
  for (iter = counts.begin() + 1; iter != counts.end(); iter++) {
    *iter += *(iter - 1);
  }
  //Each iter, decrement counts & insert into sorted using counts val: O(n)
  for (iter = items.begin() + 1; iter != items.end(); iter++) {
    sorted[--counts[(*iter/exp) % k]] = *iter;
  }

  items = sorted;
}

void Sorter::radixSort(std::vector<int> &items) {
  vector<int> sorted, buckets; //size = radix
  int maxElem = *max_element(items.begin(), items.end());
  int pval = pow(100, items.size());

  for (int exp = 1; maxElem/exp > 0; exp *=10)
    countingSort(items, exp, 100);

  printVector(items);
}

int main() {
  int myints[] = {16,277,3,-2,24,-54,-1,0,56,87,7,-7};
  vector<int> items (myints, myints + sizeof(myints) / sizeof(int));
  const string sortedStr = "-54, -7, -2, -1, 0, 3, 7, 16, 24, 56, 87, 277";
  int myints2[] = {0,4,1,3,6,2,8,4,3,1};
  vector<int> items2 (myints2, myints2 + sizeof(myints2) / sizeof(int));
  const string sortedStr2 = "0, 1, 1, 2, 3, 3, 4, 4, 6, 8";
  int myints3[] = {0,4,111,3,6,2,85,44,3,991,1};
  vector<int> items3 (myints3, myints3 + sizeof(myints3) / sizeof(int));
  const string sortedStr3 = "0, 1, 2, 3, 3, 4, 6, 44, 85, 111, 991";
  cout << "Input: " << vector2string(items) << endl;
  cout << "Input: " << vector2string(items2) << endl;

  Sorter sorter;
  vector<int> sortedItems(items);
  sorter.insertionSort(sortedItems);
  assertAndPrint(sortedItems, sortedStr, "insertionSort");

  sortedItems = items;
  sorter.selectionSort(sortedItems);
  assertAndPrint(sortedItems, sortedStr, "selectionSort");

  sortedItems = items;
  sorter.bubbleSort(sortedItems);
  assertAndPrint(sortedItems, sortedStr, "bubbleSort");

  sortedItems = items;
  sorter.mergeSort(sortedItems);
  assertAndPrint(sortedItems, sortedStr, "mergeSort");

  sortedItems = items;
  sorter.quickSort(sortedItems);
  assertAndPrint(sortedItems, sortedStr, "quickSort");

  sortedItems = items2;
  sorter.countingSort(sortedItems);
  assertAndPrint(sortedItems, sortedStr2, "countingSort");

  sortedItems = items3;
  sorter.radixSort(sortedItems);
  assertAndPrint(sortedItems, sortedStr3, "radixSort");

}
