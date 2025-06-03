public class Robot {
    private String name;
    private char direction;
    private int xLoc, yLoc;

    public Robot(String name, char dir, int x, int y) {
        this.name = name;
        direction = dir;
        xLoc = x;
        yLoc = y;
    }

    public String toString() {
        return (name + " is standing at (" + xLoc + "," + yLoc + ") and facing " + direction);
    }

    public void turnClockwise() {
        if (direction == 'N') direction = 'E';
        else if (direction == 'E') direction = 'S';
    }

    public void turnCounterClockwise() {
        if (direction == 'N') direction = 'W';
        else if (direction == 'W') direction = 'S';
 }       
  public void takeSteps(int numSteps) {
xLoc= xLoc + numSteps;
yLoc=yLoc + numSteps;
}
  public static void main(String args[]) {
        Robot robby = new Robot("Robby", 'N', 20, 25);
      for (int i = 0; i <5; i++) {
            if (i % 2 == 0) {
                robby.turnClockwise();
            } else {
                robby.turnCounterClockwise();
            }

        robby.takeSteps(2);
        System.out.println(robby);
    }
}
}