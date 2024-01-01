<h1 style="font-size: 15;"> Formulation of the problem </h1>
Sort a numeric array using the following methods: selection sort and bubble sort. At the end of sorting, display: the sorted array, the number of comparisons made, permutations of elements. Compare the performance of algorithms, which is determined by the number of comparisons and permutations, for the original unsorted array and for the original array sorted in forward and reverse order. Investigate the dependence of performance on array size.
<h1 style="font-size: 15;">Algorithm development </h1>
It is necessary to implement 2 sorting methods:

• The working principle of bubble sorting can be described in three points:
1. Walking through the entire array;
2. Comparison of pairs of neighboring cells;
3. If during comparison it turns out that the value of a cell is greater than the value of the next cell, then we swap the values of these cells;
4. Creating a flag that shows that if there were no exchanges when executing this method, then the array is already sorted and other passes are not needed.

• Method for selecting the maximum (minimum) element:
1. Consistently compare the elements with each other;
2. If we find a maximum/minimum among the elements being compared, we move it to the beginning/end and exclude it from subsequent comparisons.

*Data Description
1. N (int type) –const, the number of elements in a static array.
2. a[N], b[N],c[N],d[N] – static arrays of integers.
3. i (int type) – counter of array members.
4. s,p (int type) – counters for the number of pins.
5. e,w,arr,carr,coarr,coparr (int* type) – dynamic arrays of integers.
6. sr (int type) – number of comparisons.
7. pere (int type) – number of permutations.
8. f (int type) – a flag indicating whether there have been permutations in the array
9. obmen, mest (int type) - a variable for swapping the other two.
