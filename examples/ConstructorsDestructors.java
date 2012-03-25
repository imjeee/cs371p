// ----------------------------
// ConstructorsDestructors.java
// ----------------------------

class A {
    int _i;

    public A (int i) {
        _i = i;
        System.out.println("A.A(int)");}

    public A (A that) {
        _i = that._i;
        System.out.println("A.A(int)");}

    public void finalize () {
        System.out.println("A.finalize()");}}

class B {
    A _x;

    public B (int i) {
        _x = new A(i);
        System.out.println("B.B(int)");}

    public B (A x) {
        _x = new A(x);
        System.out.println("B.B(A)");}

    public void finalize () {
        System.out.println("B.finalize()");
        _x.finalize();}}

final class ConstructorsDestructors {
    public static void main (String[] args) {
        System.out.println("ConstructorsDestructors.java");

        A x = new A(2);
        x.finalize();
        System.out.println();

        B y = new B(2);
        y.finalize();
        System.out.println();

        B z = new B(x);
        y.finalize();

        System.out.println("Done.");}}

/*
ConstructorsDestructors.java
A.A(int)
A.finalize()

A.A(int)
B.B(int)
B.finalize()
A.finalize()

A.A(int)
B.B(A)
B.finalize()
A.finalize()
Done.
*/
