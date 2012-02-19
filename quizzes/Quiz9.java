/*
CS371p: Quiz #9 (5 pts)
*/

/* -----------------------------------------------------------------------
1. In C++, list four things that you can do wrong with manual memory
   management.
   (1 pt)

never delete
delete the wrong address
delete too many times
delete too early
*/

/* -----------------------------------------------------------------------
2. Why is a memory checker like Valgrind only of limited use even if
   perfect?
   (1 pt)

it can only check a small number of execution paths
*/

/* -----------------------------------------------------------------------
3. What is the output of the following program?
   (2 pts)

true
false
*/

class Quiz9 {
    public static void main (String[] args) {
        String s = "abc";
        String t = "abc";
        System.out.println(s == t);
        s += "de";
        System.out.println(s == t);}}
