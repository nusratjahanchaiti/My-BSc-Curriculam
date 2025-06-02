public class Shape {
    
    public double calculateArea() {
        return 0; 
    }
}

public class Circle extends Shape {
    private double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    public double calculateArea() {
        return Math.PI * radius * radius;
    }
}

public class Rectangle extends Shape {
    private double width;  
    private double height;

   
    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }

    public double calculateArea() {
        return width * height; 
    }
}

public class Test {
    public static void main(String[] args) {
     
        Circle circle = new Circle(5);
        System.out.println("Area of the circle: " + circle.calculateArea());

        Rectangle rectangle = new Rectangle(4, 6);
        System.out.println("Area of the rectangle: " + rectangle.calculateArea());
    }
}
