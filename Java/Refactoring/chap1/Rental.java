import java.util.*;
import java.io.*;

public class Rental
{
    private Movie _movie;
    private int _daysRented;

    public Rental(Movie movie, int daysRented)
    {
        _movie = movie;
        _daysRented = daysRented;
    }

    public Movie getMovie()
    {
        return _movie;
    }
    public int getDaysRented()
    {
        return _daysRented;
    }

    public static void main(String args[])
    {
        System.out.println("hello wold!");
    
    }
}

