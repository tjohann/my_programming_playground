/**
 * simpla java program to calculate a square
 * @version 0.01
 * @author tjohann
 */

public class hello_01
{
    static int square(int n)
    {
	return n * n;
    }

    static void gen_output(int n)
    {
	for (int i = 1; i <= n; i = i + 1) {
	    String s = "The square value of " + i + " is: " + square(i);
	    System.out.println(s);
	}
    }

    public static void main(String[] args)
    {
	gen_output(10);
    }
}
