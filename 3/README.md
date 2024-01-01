<h1 style="font-size: 15;"> Formulation of the problem </h1>
1. Find the root of the equation x−cos(x)=0 by simple iteration (method No. 1), half division (method No. 2) and Newton’s method (method No. 3) with an error of eps<0.000001 and for each of the three methods determine the number of steps algorithm.
2. Follow step 1 for eps<0.00000001.
3. Perform step 1 for the equation x−k∗cos(x)=0 for k=5 and k=10 and explain the results.
4. Present the result in the form of a table (without frames), which contains three columns Method No., x and N, where N is the number of iterations.


<h1 style="font-size: 15;"> Algorithm development </h1>

*Description of algorithms

Simple iteration method:
First we set the initial value x0. For x = cos(x), calculate the next x using the formula: x = cos(x0). As soon as the difference between x and x0 falls within the specified accuracy (eps), x is the desired root. Works if the derivative of the expression is less than 1.
Half division method:
First, we determine the left (xl) and right (xr) boundaries of the segment on which we will look for the root, then we set the value of the variable x using the formula x = (xl+xr)/2 (the middle of the segment). We check whether the variable has the same sign; if so, then we assign the value x to the end of the segment, otherwise we assign x to the beginning of the segment. As soon as the difference between the two boundaries does not exceed the specified accuracy (eps), x is the desired root.
Newton's method:
First we set the value of the variable x0. Next, we look for the next x using the formula: x = (x0 – f(x0)) / f ‘(x0). As soon as the difference between x and x0 falls within the specified accuracy, x is the desired root.

*Data Description

1. eps (double type) – specified accuracy.
2. x (double type) - a variable to search for a value.
3. x0 (double type) – a variable used to calculate the subsequent x value (current x value).
4. k (int type) – coefficient of cos(x).
5. Nmax (int type) – iteration counter.
6. xl (double type) – the left border of the range of x values.
7. xr (double type) – the right boundary of the range of x values.
8. fx (double type) – the value of the function at point x.
9. fl (double type) – the value of the function at point xl.
10. fr (double type) – function value at point xr.
11. fx (double type) – function value at point x0.
12. px (double type) – the value of the derivative at point x0.
    
*Functions:
1. iteraz – calculation of the root by simple iteration.
2. poldel – calculation of the root using the half division method.
3. nuton – root calculations using Newton’s method.
