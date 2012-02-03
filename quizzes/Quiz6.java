/*
CS371p: Quiz #6 (5 pts)
*/

/* -----------------------------------------------------------------------
1. What is the output of the following program?
   You MUST get the newlines right to get full credit.
   Write the word "blank" to indicate a blank line.
   (4 pts)

m1
f1
f2
m2
m4

m1
f1
m3
m4
*/

class Quiz6 {
    static void f (boolean b) {
        System.out.println("f1");
        if (b)
            throw new RuntimeException("abc");
        System.out.println("f2");}

    public static void main (String[] args) {
        try {
            System.out.println("m1");
            f(false);
            System.out.println("m2");}
        catch (RuntimeException e) {
            System.out.println("m3");}
        System.out.println("m4");
        System.out.println();

        try {
            System.out.println("m1");
            f(true);
            System.out.println("m2");}
        catch (RuntimeException e) {
            System.out.println("m3");}
        System.out.println("m4");}}
