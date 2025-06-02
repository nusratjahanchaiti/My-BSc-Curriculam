import java.util.ArrayList;
import java.util.Collections;

public class Person implements Comparable<Person> {

    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public int compareTo(Person other) {

        return Integer.compare(this.age, other.age);
    }

    public static void main(String[] args) {
        ArrayList<Person> persons = new ArrayList<>();
        persons.add(new Person("Alice", 25));
        persons.add(new Person("Bob", 30));
        persons.add(new Person("Charlie", 20));
        persons.add(new Person("David", 35));

        Collections.sort(persons);
		
        System.out.println("Sorted list of persons based on age:");
        for (Person person : persons) {
            System.out.println(person.getName() + " - Age: " + person.getAge());
        }
    }
}
