//  Refactoring, a First Example, step2, (~p11)

import java.util.*;

public class Movie {
  public static final int CHILDRENS = 2;
  public static final int REGULAR = 0;
  public static final int NEW_RELEASE = 1;

  private String _title;        //
  private int _priceCode;       // ????

  public Movie(String title, int priceCode){
      _title = title;
      _priceCode = priceCode;
  }

   public int getPriceCode(){
      return _priceCode;
  }

  public void setPriceCode(int arg){
      _priceCode = arg;
  }

  public String getTitle(){
      return _title;
  }

  // jjhou add
  public static void main(String[] args) {
      System.out.println("Refactoring, a First Example, step2");
  }

}

class Rental {
  private Movie _movie;         // ?v??
  private int _daysRented;      // ????

  public Rental(Movie movie, int daysRented) {
    _movie = movie;
    _daysRented = daysRented;
  }

  public int getDaysRented() {
    return _daysRented;
  }

  public Movie getMovie() {
    return _movie;
  }
}

class Customer {
  private String _name;                                 // ?m?W
  private Vector _rentals = new Vector();               // ???ɰO??

  public Customer(String name) {
      _name = name;
  }

  public void addRental(Rental arg) {
      _rentals.addElement(arg);
  }

  public String getName() {
      return _name;
  }

  public String statement() {
    double totalAmount = 0;             // ?`???O???B
    int frequentRenterPoints = 0;       // ?`?ȿn?I
    Enumeration rentals = _rentals.elements();
    String result = "Rental Record for " + getName() + "\n";

    while(rentals.hasMoreElements()) {
      double thisAmount = 0;
      Rental each = (Rental) rentals.nextElement(); // ???o?@?????ɰO??

      thisAmount = amountFor(each);        // ?p???@???????O??

      // add frequent renter points?]?֥[ ?`?ȿn?I?^
      frequentRenterPoints ++;
      // add bonus for a two day new release rental
      if ((each.getMovie().getPriceCode() == Movie.NEW_RELEASE) &&
         each.getDaysRented() > 1)
        frequentRenterPoints ++;

      // show figures for this rental?]???ܦ??????ɸ??ơ^
      result += "\t" + each.getMovie().getTitle() + "\t" +
          String.valueOf(thisAmount) + "\n";
      totalAmount += thisAmount;
    }

