
# quickersorting

**quickersorting** is the fastest solution for the sorting problem using merge sort and multi-threading.

## What is Merge Sort & Why we use it? 

[Merge Sort](https://www.youtube.com/watch?v=ZRPoEKHXTJg) is a sorting algorithm based on **``Divide et Impera``**, which is basically **dividing** the array/list/std::vector into small pieces, sorting them and then reuniting them. This algorithm's computational complexity is **``O(n*log(n))``** which makes him one of **the most efficient algorithms** for sorting data.

Dividing the vector in smaller pieces allows us to use multi-threading in order to **speed up the solution** of the problem. Merge Sort is the perfect algorithm to be matched with multi-threading because of its **dividing behaviour** and this way we can prevent any of the concurrent computing problems *(i.e. race conditions, deadlocks and so on..)*
## Usage/Examples

```C++
#include "quicker_sorting.hpp"

size_t size = 1000000;
std::vector<int> large_array = generate_large_array<int>(size);

MergeSort<int>::sort(large_array, true, [](int a, int b) -> bool {
    return a > b;
});

```

## Disabled Multi-Threading Analysis

| Test Number | std::vector size | Time Elapsed |  
| :-:  | :-: | :-: |
| 1 | 1000000 |  257ms  |
| 2 | 1000000 |  256ms  | 
| 3 | 1000000 |  260ms  |
| 4 | 1000000 |  256ms  |
| 5 | 1000000 |  255ms  |
 
 **Average time elapsed: 256ms**

 ## Enabled Multi-Threading Analysis

| Test Number | std::vector size | Time Elapsed |  
| :-:  | :-: | :-: |
| 1 | 1000000 |  53ms  |
| 2 | 1000000 |  67ms  | 
| 3 | 1000000 |  56ms  |
| 4 | 1000000 |  57ms  |
| 5 | 1000000 |  61ms  |
 
 **Average time elapsed: 58ms**

## Notes & Conclusions

As you can see, multi-threading drastically changed the speed of resolving the algorithm without occurring in memory problems. 

I tried to make the program even faster creating as much threads as I could but 4 or 5 threads are optimal for the speed because threads are expensive and creating more than 5 can eventually slow down the process even more so in some cases could be kinda conunterproductive.

## Contributions 

- [Andrea Spasojevic](https://github.com/AndreaSpasojevic) - Gave me the idea and some tips for the implementation
