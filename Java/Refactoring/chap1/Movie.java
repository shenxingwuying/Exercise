import java.util.*;
import java.io.*;


public class Movie
{
    private String _title;
    private int _priceCode;

    public static final int CHILDRENS = 2;
    public static final int REGULAR = 0;
    public static final int NEW_RELEASE = 1;

    public Movie(String title, int priceCode)
    {
        this._title = title;
        this._priceCode = priceCode;
    }

    public String getTitle()
    {
        return _title;
    }
    public int getPriceCode()
    {
        return _priceCode;
    }
    public void setPriceCode(int priceCode)
    {
        this._priceCode = priceCode;
    }

    public static void main(String args[])
    {
        System.out.println("hello wold!");
    }
}
