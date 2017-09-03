package com.company;

// import java.swing.*;

public class BankAccount  {
    String owner;
    double balance;
    boolean debit(double amount) {
        if(amount > balance) {
            return false;
        } else {
            balance -= amount; 
            return true;
        }
    }
    void credit(double amount) {
        balance += amount;
    }
}


