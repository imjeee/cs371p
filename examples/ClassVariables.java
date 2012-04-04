// -------------------
// ClassVariables.java
// -------------------

final class A<T> {     // extends Object
//  public static T v; // error: non-static class T cannot be referenced from a static context

    public static int v0;
    public static int v1 = v0 + 1;
    public static int v2;

//  public static final T   cv; // error: non-static class T cannot be referenced from a static context
//  public static final int cv; // error: variable cv might not have been initialized

    public static final int cv0 = 0;
    public static final int cv1 = cv0 + 1;
    public static final int cv2;

    static
        {
        v2  = v1  + 1;
        cv2 = cv1 + 1;
        }}

final class ClassVariables {
    public static void main (String[] args) {
        System.out.println("ClassVariables.java");

        assert A.v0 == 0;
        assert A.v1 == 1;
        assert A.v2 == 2;

        assert A.cv0 == 0;
        assert A.cv1 == 1;
        assert A.cv2 == 2;

        A<Integer> x = new A<Integer>();
        A<Double>  y = new A<Double>();
        assert(x.v0 == y.v0);

        System.out.println("Done.");}}
