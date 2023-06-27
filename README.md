# TableClass Implementation and Query Operations

## Objective:
In this project, you will learn about reading data from input files and store and play with dynamic arrays with sorting algorithms.

## Description:
When given n numbers as input, there are many operations/questions/queries that you can perform/ask about the n numbers. The time to answer these queries or perform the operations varies depending on how the numbers are spread out in the given order – the pattern in which they are given. One way to speed up the query time is to vary the pattern of these given numbers to an orderly fashion – increasing or decreasing order.

Given a sequence of n numbers as input in no particular order, the goal is to reorder the numbers for an output where the numbers are all in increasing or decreasing order. This is the definition of sorting a set of n numbers.

Once we sort the given numbers into an order, the queries or operations that we can perform can be faster (at least for a specific set of them if not all operations/queries). For example, once we sort, finding the median of the n numbers can and will be faster, but the time to find the mean will not change.

You will be comparing the time taken for performing queries and operations between an unsorted set of random numbers and performing the same query/operation on a sorted version of the same set of numbers.

You are given a set of randomly generated numbers that is first stored in a dynamic array (A). Once this is stored, you will have to sort this array and store the sorted array in a different array (B). You can use any sorting algorithm to sort (we will be providing you with a sorting algorithm as well).

### Queries:
- Find/search the given element in both the sorted and unsorted arrays.
  - In array B (sorted array), you can use binary search to find the value.
  - In array A, you must do a linear search.
- SumPairs: Given an integer target, return the two numbers such that they add up to the target.

### Operations:
- Remove the given element from both the arrays A and B.
  - Once you remove the element, you must left shift the values to the right of the empty space so that the empty spaces as we remove more elements are maintained to the right end of the array.
- Insertion: Insert the given element into both the arrays A and B.
  - In array B (sorted array), you must insert the value into the right position.
  - In array A, you may insert it at the end of the array.

## Assumptions:
- Number of removals will always be less than the number of insertions. So there is no need to reallocate the arrays.
- There will not be any duplicates in the given set of random numbers.
- Keep up with the FAQ discussion board for project 1 on Canvas as more assumptions and conversations will be continued there.

## Input explanation:
The input file given is in the following format:

        9
        40
        30
        50
        10
        20
        60
        80
        90
        70
        F 5
        20 30 50 60 45
        A 3
        30 70 120
        R 4

- The first line represents the size of the array.
- The next lines represent the randomly generated numbers.
- After this, we provide a list of commands/options for the operations and queries that go until the end of the input file. Each of these commands is followed by the number of commands for each of the operations/queries.
