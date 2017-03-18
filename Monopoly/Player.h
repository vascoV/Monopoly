class CPlayer {
private:
	string name;
	int money;
	int position;
	bool passedGO;

public:
	CPlayer(string name) {
		this->name = name;
		money = 1500;
	}
	CPlayer(string name, int money) {
		this->name = name;
		this->money = money;
	}
	~CPlayer() {}

	void SetPosition(int pos) //set the CPlayer position
	{
		position = pos;
	}
	void MovePosition(int pos)
	{
		position += pos; // move CPlayer position according ot the dice roll
	}
	void ResetPosition() //reset the palyer position when the player passes GO
	{
		position = position - 26;
		money += 200;
	}
	void SetPassedGo(bool GOsquare) //Set bool of passedGO
	{
		passedGO = GOsquare;
	}
	void addMoney(int value) //increase money value
	{
		money += value;
	}
	void reduceMoney(int value) // decrease money value
	{
		money -= value;
	}
	string getName() // return the player Name  
	{
		return name;
	}
	int getMoney() // return the player amount of money  
	{
		return money;
	}
	int GetPosition() //return the playe position
	{
		return position;
	}
	bool PassedGo() // return true/false if the user passed GO square or not
	{
		return passedGO;
	}
};
