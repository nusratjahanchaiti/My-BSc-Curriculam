abstract class Student {
   
    public abstract void motivation();
	
    public void displayMotivation() {
        System.out.print("Student's motivation: ");
        motivation();
    }
}

class FirstYear extends Student {
  
    public void motivation() {
        System.out.println("Excited about the new learning experience."); 
    }
}

class FinalYear extends Student {
   
    public void motivation() {
        System.out.println("Motivated to excel and graduate successfully.");
    }
}

public class TestStudent {
    public static void main(String[] args) {
        Student firstYearStudent = new FirstYear();
        Student finalYearStudent = new FinalYear();

        firstYearStudent.displayMotivation(); 
        finalYearStudent.displayMotivation();
    }
}
