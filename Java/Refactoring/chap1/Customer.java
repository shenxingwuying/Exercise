import java.util.*;
import java.io.*;

public class Customer
{
    private String _name;
    //private Vector _rentals = new Vector();
    private ArrayList<Rental> _rentals = new ArrayList<Rental>();
    
    public Customer(String name)
    {
        _name = name;
    }
    
    public void addRental(Rental arg)
    {
        //_rentals.addElement(arg);
        _rentals.add(arg);
    }

    public String getName()
    {
        return _name;
    }

    public static void main(String args[])
    {
        System.out.println("hello wold!");
    }
}

