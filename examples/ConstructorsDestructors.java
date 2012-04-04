// ----------------------------
// ConstructorsDestructors.java
// ----------------------------

class A {
    int _i;

    public A (int i) {
        _i = i;
        System.out.println("A(int)");}

    public A (A that) {
        _i = that._i;
        System.out.println("A(A)");}

    public void finalize () {
        System.out.println("A.finalize()");}}

class B {
    A _x;

    public B (int i) {
        _x = new A(i);
        System.out.println("B(int)");}

    public B (A x) {
        _x = new A(x);
        System.out.println("B(A)");}

    public void finalize () {
        System.out.println("B.finalize()");
        _x.finalize();}}

final class ConstructorsDestructors {
    public static void main (String[] args) {
        System.out.println("ConstructorsDestructors.java");

        A x = new A(2);
        System.out.println();

        B y = new B(2);
        System.out.println();

        B z = new B(x);

        System.out.println("Done.");}}

/*
ConstructorsDestructors.java
A(int)

A(int)
B(int)

A(A)
B(A)
Done.
*/
