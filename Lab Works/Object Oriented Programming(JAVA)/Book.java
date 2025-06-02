import java.util.Arrays;
import java.util.Comparator;

public class Book implements Comparable<Book> {

    private String title;
    private String author;
    private int year;

    public Book(String title, String author, int year) {
        this.title = title;
        this.author = author;
        this.year = year;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public int compareTo(Book other) {

        return this.title.compareTo(other.title);
    }

    public static Comparator<Book> yearComparator = new Comparator<Book>() {
        @Override
        public int compare(Book book1, Book book2) {

            return Integer.compare(book1.year, book2.year);
        }
    };

    public static Comparator<Book> authorComparator = new Comparator<Book>() {
        public int compare(Book book1, Book book2) {
     
            return book1.author.compareTo(book2.author);
        }
    };

    public static void main(String[] args) {
       
        Book[] books = {
                new Book("Title3", "Author2", 2000),
                new Book("Title1", "Author3", 1995),
                new Book("Title2", "Author1", 2010),
                new Book("Title4", "Author3", 1995)
        };

 
        Arrays.sort(books); 
        System.out.println("Sorted array of books based on title:");
        printBooks(books);

        Arrays.sort(books, Book.yearComparator); 
        System.out.println("\nSorted array of books based on publication year:");
        printBooks(books);

        Arrays.sort(books, Book.authorComparator);
        System.out.println("\nSorted array of books based on author's name:");
        printBooks(books);
    }

    private static void printBooks(Book[] books) {
        for (Book book : books) {
            System.out.println(book.getTitle() + " by " + book.getAuthor() + " - Year: " + book.getYear());
        }
    }
}
