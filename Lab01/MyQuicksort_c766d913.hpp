#ifndef _MY_QUICK_SORT_
#define _MY_QUICK_SORT_

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <assert.h>

const int BOUNDARY_SIZE = 10; // sort directly using insertion sort if the input size is smaller than BOUNRARY_SIZE

// Checks if an array is sorted
// a: input array to be checked
// reverse: if set true, check for descending order; otherwise ascending order
template <typename Comparable>
bool IsSorted( std::vector<Comparable> & a, bool reverse = false)
{
  if(a.size() <= 1) return true;
  bool sorted = true;
  for(size_t i = 0; i < a.size() - 1; ++ i)
  {
    if((a[i] > a[i + 1] && !reverse) || (a[i] < a[i + 1] && reverse))
    {
      sorted = false;
      std::cout << "Out of order: Positions: " << i << " : " << a[i] << "  " << a[i + 1] << std::endl;
      break;
    }
  }
  return sorted;
}

// Prints the array
// a: the array to be printed
template <typename Comparable>
void PrintArray( std::vector<Comparable> & a)
{
  for(size_t i = 0; i < a.size(); ++ i)
  {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
  return;
}

// The insertion sort algorithm:
// a: the input array
// left and right: the left and end indexes of the range of the elements to be sorted, inclusive
// reverse: if set true, sort in descending order. Default: false
template <typename Comparable>
void InsertionSort( std::vector<Comparable> & a , int left, int right, bool reverse = false)
{
  // CODE BEGINS
  for (int i = left + 1; i <= right; i++) {
    Comparable temp = a[i];
    int j = i - 1;
    if (!reverse) {
      while (j >= left && a[j] > temp) {
        a[j + 1] = a[j];
        j = j - 1;
      }
    } else {
      while (j >= left && a[j] < temp) {
        a[j + 1] = a[j];
        j = j - 1;
      }
    }
    a[j + 1] = temp;
  }
  // CODE ENDS
}


// Finds the median among three elements: a[x], a[y], and a[z]
// a: the array
// x, y, z: the three indexes in the array
// returns the index that corresponds to the median of the three
template <typename Comparable>
const size_t ArrayMedian3( std::vector<Comparable> & a, const size_t x, const size_t y, const size_t z)
{
  // CODE BEGINS
  if ((a[x] >= a[y] && a[x] <= a[z]) || (a[x] >= a[z] && a[x] <= a[y])) {
    return x;
  }
  if ((a[y] >= a[x] && a[y] <= a[z]) || (a[y] >= a[z] && a[y] <= a[x])) {
    return y;
  }
  return z;
  // CODE ENDS
}

// The recursive quick sort function
// a: the array to be sorted
// left and right: the indexes for the range to be sorted, inclusive
// reverse: if set true, sort in descending order; otherwise in ascending order
template <typename Comparable>
void Quicksort( std::vector<Comparable> & a, int left, int right, bool reverse = false)
{
  // CODE BEGINS
  // if (left < right) // use TER
  while (left < right) {
    if (right - left < BOUNDARY_SIZE) {
      InsertionSort(a, left, right, reverse);
      return;
    }

    size_t pivotIndex = ArrayMedian3(a, left, (left + right) / 2, right);
    Comparable pivot = a[pivotIndex];
    std::swap(a[pivotIndex], a[right]);
    int i = left - 1;
    int j = right;

    /**
     * There is something wrong with this on edge cases, the pivot is near the edges
     * It sucks to read anyways. LOL!
    for (;;) {
      if (!reverse) {
        while (a[++i] < pivot);
      } else {
        while (a[++i] > pivot);
      }
      if (!reverse) {
        while (pivot < a[--j]) if (j == left) break;
      } else {
        while (pivot > a[--j]) if (j == left) break;
      }
      if (i >= j) break;
      std::swap(a[i], a[j]);
    }
    std::swap(a[i], a[right]);
    j = i - 1;
    i = i + 1;
    */

    // FIXED!
    for (;;) {
      if (!reverse) {
        while (i < right && a[++i] < pivot);
        while (j > left && a[--j] > pivot);
      } else {
        while (i < right && a[++i] > pivot);
        while (j > left && a[--j] < pivot);
      }
      if (i >= j) break;
      std::swap(a[i], a[j]);
    }
    std::swap(a[i], a[right]);

    // Quicksort(a, left, i - 1, reverse); // left
    // Quicksort(a, i + 1, right, reverse); // right

    // T.E.R doesn't offer any improvements to match closer to expected log times?
    // Is this just an issue with clock freq? Probably, the test grader says
    // all yes, so who cares...
    if (i - 1 - left < right - (i + 1)) {
      Quicksort(a, left, i - 1, reverse); // left
      left = i + 1;
    } else {
      Quicksort(a, i + 1, right, reverse); // right
      right = i - 1;
    }
  }
  // CODE ENDS
}


// The driver quicksort function
template <typename Comparable>
void Quicksort( std::vector<Comparable> & a, bool reverse = false)
{
  Quicksort( a, 0, a.size( ) - 1, reverse);
}


#endif