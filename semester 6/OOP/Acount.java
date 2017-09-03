class Account {
	private String name;
	private int balance;

	Account() {
		name = "Unsigned";
		balance = 0;
	}

	Account(String pName, int pBalance) {
		name = pName;
		balance = pBalance;
	}

	public void setName(String pName) {
		name = pName;
	}

	public String getName(){ 
		return name;
	}

	public String getBalance(){ 
		return balance;
	}

	public void deposit(int amount) {
		balance += amount;
	}

	public boolean debit(int amount) {
		if(amount > balance) {
			return false;
		} 
		else {
			balance -= amount;
			return true;
		}

	}







}
