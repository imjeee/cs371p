// --------------------
// FormattedOutput.java
// --------------------

import java.util.IllegalFormatConversionException;

final class FormattedOutput {
    public static void main (String[] args) {
        System.out.println("FormattedOutput.java");

        final double pi = 3.14159;

        {
        final String s = String.format("%7.2f, %7.3f", pi, pi);
        assert(s.equals("   3.14,   3.142"));
        }

        {
        final String s = String.format("%7.2f, %-7.3f", pi, pi);
        assert(s.equals("   3.14, 3.142  "));
        }

        {
        final String s = String.format("%7.2f, %10.6f", pi, pi);
        assert(s.equals("   3.14,   3.141590"));
        }

        try {
            final String s = String.format("%7.2f", "abc");
            assert(false);}
        catch (IllegalFormatConversionException e) {
            assert e.toString().equals("java.util.IllegalFormatConversionException: f != java.lang.String");}

        System.out.println("Done.");}}
