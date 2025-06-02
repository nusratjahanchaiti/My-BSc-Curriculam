abstract class Student {
    private String name;

    public Student(String name) {
        this.name = name;
    }

    public abstract void motivation();

    public void displayMotivation() {
        System.out.println(name + "'s motivation level: " + motivation());
    }
}

class FirstYear extends Student {
    public FirstYear(String name) {
        super(name);
    }

   
    public String motivation() {
        return "High";
    }
}

class FinalYear extends Student {
    public FinalYear(String name) {
        super(name);
    }

    
    public String motivation() {
        return "Very High";
    }
}

public class TestStudent {
    public static void main(String[] args) {
        FirstYear firstYearStudent = new FirstYear("Chaiti");
        FinalYear finalYearStudent = new FinalYear("Nusrat");

        firstYearStudent.displayMotivation(); 
        finalYearStudent.displayMotivation();
    }
}

