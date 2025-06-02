class BankAccount {
    private double balance;

    public BankAccount(double balance) {
        this.balance = balance;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }
	
    public void calculateInterest() {
        System.out.println("Calculating interest for a generic bank account");
    }
}

class SavingsAccount extends BankAccount {
    private double interestRate;

    public SavingsAccount(double balance, double interestRate) {
        super(balance);
        this.interestRate = interestRate;
    }

    public void calculateInterest() {
        double interest = getBalance() * interestRate / 100;
        System.out.println("Calculating interest for savings account: $" + interest);
    }
}

class CheckingAccount extends BankAccount {
    private double overdraftLimit;

    public CheckingAccount(double balance, double overdraftLimit) {
        super(balance);
        this.overdraftLimit = overdraftLimit;
    }

    public void calculateInterest() {
        System.out.println("No interest for checking account");
    }
}

public class TestBankAccount {
    public static void main(String[] args) {
        SavingsAccount savingsAccount = new SavingsAccount(1000, 5); 
        CheckingAccount checkingAccount = new CheckingAccount(800, 200);
        savingsAccount.calculateInterest();
        checkingAccount.calculateInterest();
    }
}
