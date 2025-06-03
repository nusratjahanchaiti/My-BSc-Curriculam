import javax.swing.*;  
public class FirstSwingExample {  
public static void main(String[] args) {  
JFrame f=new JFrame();  
          
JButton b=new JButton("click");  
b.setBounds(130,100,100, 40); 

JButton a =new JButton("Play Now");  
a.setBounds(200,200,100, 50);
f.add(b);
f.add(a); 
          
f.setSize(400,500);  
f.setLayout(null);  
f.setVisible(true);  
}  
} 