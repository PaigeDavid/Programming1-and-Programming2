//FILE	:	SavingsAccount.h
//PROG	:	Paige Peck
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
		SavingsAccount();		//Prototype for constructor
		string getAccountNumber();
		double getBalance();
		double getInterestRate();
		void subtractFromBalance(double);
		void addToBalance(double);
};	//(Be careful: this semicolon is very easy to forget!)

//Methods implementation
//This is the constructor
SavingsAccount::SavingsAccount()
{
	accountNumber = "Z1234A";
	balance = 4000.0;
	rate = .004;
}

string SavingsAccount::getAccountNumber()
{
	return accountNumber;
}

double SavingsAccount::getBalance()
{
	return balance;
}

double SavingsAccount::getInterestRate()
{
	return rate;
}

void SavingsAccount::subtractFromBalance(double amount)
{
	balance -= amount;
}

void SavingsAccount::addToBalance(double amount)
{
	balance += amount;
}
//END OF CLASS SavingsAccount
