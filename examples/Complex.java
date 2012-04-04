// ------------
// Complex.java
// ------------

class MyComplex {
    private int _r;
    private int _i;

    public static MyComplex conjugate (MyComplex other) {
        return new MyComplex(other._r, other._i).conjugate();}

    public MyComplex () {
        this(0, 0);}

    public MyComplex (int r) {
        this(r, 0);}

    public MyComplex (int r, int i) {
        _r = r;
        _i = i;}

    public MyComplex conjugate () {
        _i = -_i;
        return this;}

    public boolean equals (Object rhs) {
        if (!(rhs instanceof MyComplex))
            return false;
        MyComplex that = (MyComplex) rhs;
        return (_r == that._r) && (_i == that._i);}

    public String toString () {
        return "(" + _r + ", " + _i + ")";}}

final class Complex {
    public static void main (String[] args) {
        System.out.println("Complex.java");

        final MyComplex x = new MyComplex();
        final MyComplex y = new MyComplex(2);
        final MyComplex z = new MyComplex(2, 3);

        assert z.toString().equals("(2, 3)");

        final MyComplex t = z.conjugate();
        assert z.equals(new MyComplex(2, -3));
        assert t == z;

        final MyComplex u = MyComplex.conjugate(z);
        assert z.equals(new MyComplex(2, -3));
        assert u.equals(new MyComplex(2,  3));

        System.out.println("Done.");}}
