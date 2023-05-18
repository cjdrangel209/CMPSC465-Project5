# CMPSC465-Project5
Takes an array of numbers and determines how many inversions are to take place to get an ordered array

Inversion Count for an array indicates – how far (or close) the array is from being sorted. If array is already
sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum.
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j .

Requirement
Design should be based on divide and conquer.
Running time should NOT be worse than Theta(n log n).
Must use recursion to solve the subproblems.

Input Specification
Your program should read from an input file, which starts with a line indicating the number of test cases.
Each of the following lines indicates a test case, and each test case includes a sequence of numbers
(separated by spaces) for which you need to count inversions.

Output Specification
For each test case, print one line with a format of "The sequence has ? inversions" in console.
