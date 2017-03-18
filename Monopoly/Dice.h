using namespace std;

class CDice
{
public:
	CDice()
	{
		srand(static_cast<unsigned int> (time(0)));
		ifstream seedFile; //read the seed file
		int seed;
		seedFile.open("seed.txt");
		seedFile >> seed;
		seedFile.close();
		srand(seed);
	}

	int roll()
	{
		return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
	}
};
