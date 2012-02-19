/*
CS371p: Quiz #3 (5 pts)
*/

/* -----------------------------------------------------------------------
1. Given positive integers, b and e, let m = e / 2. If b <= m, then
   max_cycle_length(b, e) = max_cycle_length(m, e). True or False?
   [Collatz]
   (2 pts)

True

Consider b = 10, e = 100.
Then m = 50.
max_cycle_length(10, 100) = max_cycle_length(50, 100)
All the numbers between 10 and 50 can be mapped to numbers between 50 and
and 100 by one or more doublings, so none of those numbers could have a
larger cycle length.
*/

/* -----------------------------------------------------------------------
2. Describe the difference between a unit test and an acceptance test.
   (2 pts)

a unit test tests the return value and the side effects of an individual
function or method
an acceptance test tests the input output behavior of the whole program
*/
