<h1 style="font-size:15;"> Formulation of the problem </h1>
1. Numerical integration of a function with a given accuracy using the rectangle method.
Calculate the definite integral from a to b for the four functions f1 = x, f2 = sin( 22 * x), f3 = x4 and f4 = arctan(x).
Calculate the integral in the form of the IntRect function.
Perform calculations for five precision values: 0.01, 0.001, 0.0001, 0.00001 and 0.000001.
Investigate the performance of the algorithm depending on the integrand and the required accuracy (the performance of the algorithm can be estimated by the number of elementary rectangles n).
The results are presented in the form of 5 tables, one table for each accuracy value. In each table, display data for all four functions.
2. Complete step 1 using the trapezoidal method for integration. Calculate the integral in the form of the IntTrap function.
To print result tables, use the same function as in the rectangle method.

<h1 style="font-size:15;"> Algorithm development </h1>

*Description of the algorithm

Using the reference material given for this laboratory work, we implement functions for calculating the approximate value of the integral using the methods of rectangles and trapezoids with a certain accuracy.
We will also calculate the exact values of the integral using the formulas attached to the laboratory work.
Using two nested for loops in the main function, referring to the function of printing data in the form of a table, we will fill the columns of the table based on the received data (the approximate value of the integral and the number of rectangles/trapezoids).
Rectangle method - the approximate value of the integral is defined as the area of a rectangle, one of the sides of which is the length of the integration segment, and the other is the approximating constant. To improve the accuracy of integration, the segment [a,b] is divided into n-parts, and the rectangle formula is applied to each of them.
The trapezoidal method consists in dividing the integration interval into n-parts, with the integral being approximately equal to the product of the length of the interval and the arithmetic mean of the integrand at the beginning and end of this segment.


*Data Description

1. data (structure):
   
o name (const char* type) – function name.

o value (double type) – the amount obtained by integration.

o full_value (type double) – exact value of the integral.

o binary_division (int type) - number of iterations.


2. Functions get_trapezoid_result and get_rectangle_result:
   
o dx (double type) – the size of one segment.

o newSum, OldSum (double type) - necessary when calculating the amount

o bn (int type) – step counter

o x (int type (only in the get_rectangle_result function)) – copy of the value of the left border of the segment


3. main function:
   
o a (type int) – left boundary of integration.

o b (type) – right boundary of integration.

o precisions [](double type) – array of eps values.

o f[] (type double*) – array of function names.

o bns[] (long long type) – array of counters.

o n (int type) – counter for beautiful output.
