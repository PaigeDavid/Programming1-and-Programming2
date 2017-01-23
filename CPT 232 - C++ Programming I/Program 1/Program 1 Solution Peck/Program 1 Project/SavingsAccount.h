//FILE	:	SavingsAccount.h
//PROG	:	Dave Jones
//PURP	:	Header for a bank savings account

class SavingsAccount
{
	//Data declarations
	private:
		string accountNumber;
		double balance;
		double rate;

	//Methods declarations
	public:
		SavingsAccount();
		double getBalance();
		void addToBalance(double);
};	//(Be careful: this semicolon is very easy to forget!)

//Methods implementation
//This is the constructor
SavingsAccount::SavingsAccount()
{
	balance = 1000.0;
}


double SavingsAccount::getBalance()
{
	return balance;
}

void SavingsAccount::addToBalance(double amount)
{
	balance += amount;
}
//END OF CLASS SavingsAccount
