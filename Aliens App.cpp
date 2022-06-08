#include <iostream>
#include <vector>
using namespace std;

class Alien {

protected:

	int Height;
	int Weight;
	char Gender;

	Alien(int height, int weight, char gender) {
		Height = height;
		Weight = weight;
		Gender = gender;
	}

	friend void createAlien(vector<Alien>& alienVector);
	friend void offspringFunction(vector<Alien>& alienVector);

public:

	void print() {
		cout << "\t\t" << Height << "\t" << Weight << "\t" << Gender << endl;
	}

	int getPrestige() {
		int prestige;
		prestige = Height * Weight * 2;
		if (Gender = 'M') {
			prestige = Height * Weight * 2;
			return prestige;
		}

		else {
			prestige = Height * Weight * 3;
			return prestige;
		}
	}

	Alien operator +(const Alien& obj) const
	{
		srand(time(NULL));
		char genderMale = 'M';
		char genderFemale = 'F';
		int random = rand() % 2 + 1;
		if (random == 1) {
			return Alien((Height + obj.Height) / 2, (Weight + obj.Weight) / 2, genderMale);
		}

		else if (random == 2) {
			return Alien((Height + obj.Height) / 2, (Weight + obj.Weight) / 2, genderFemale);
		}
	};

	//Alien operator =(const Alien& obj) const
	//{

	//};
};


void createAlien(vector<Alien>& alienVector) {
	int height;
	int weight;
	char gender;
	cout << "\nPlease enter alien height: ";
	cin >> height;
	cout << "Please enter alien weight: ";
	cin >> weight;
	cout << "Please enter alien gender: ";
	cin >> gender;
	Alien alien(int height, int weight, char gender);
	alienVector.push_back(Alien(height, weight, gender));
	cout << endl;
}

void displayAlien(vector<Alien>& alienVector) {
	int j = 0;
	cout << endl;
	cout << "\t      Height  Weight  Gender\n";
	for (int i = 0; i < alienVector.size(); i++) {
		cout << "Alien " << j + 1;
		alienVector[i].print();
		j++;
	}
	cout << endl;
}

void offspringFunction(vector<Alien>& alienVector) {
	int selection1;
	int selection2;
	cout << "\nWhich two aliens would you like to breed?\n\n";
	cout << "Selection 1: ";
	cin >> selection1;
	cout << "Selection 2: ";
	cin >> selection2;
	cout << "\nYou selected: \n\n";
	cout << "\t      Height  Weight  Gender\n";
	cout << "Alien " << selection1;
	Alien alien1(alienVector[selection1 - 1]);
	alien1.print();
	cout << "Alien " << selection2;
	Alien alien2(alienVector[selection2 - 1]);
	alien2.print();
	Alien alien3(0, 0, 'X');
	alien3 = alien1 + alien2;
	cout << "\nAlien offspring created:\n\n";
	cout << "\t      Height  Weight  Gender\n";
	cout << "Alien " << alienVector.size() + 1;
	alien3.print();
	alienVector.push_back(alien3);
	cout << endl;
}

void prestigeFunction(vector<Alien>& alienVector) {
	int selection1;
	int selection2;
	bool compare;
	cout << "\nWhich two aliens would you like to compare?\n\n";
	cout << "Selection 1: ";
	cin >> selection1;
	cout << "Selection 2: ";
	cin >> selection2;
	cout << "\nYou selected: \n\n";
	cout << "\t      Height  Weight  Gender\n";
	cout << "Alien " << selection1;
	Alien alien1(alienVector[selection1 - 1]);
	alien1.print();
	cout << "Alien " << selection2;
	Alien alien2(alienVector[selection2 - 1]);
	alien2.print();
	cout << "\nPrestige Comparison:\n";
	compare = alien1.getPrestige() == alien2.getPrestige();
	cout << "\nAlien " << selection1 << " == " << "Alien " << selection2 << " is ";
	cout << boolalpha << compare << endl;
	compare = alien1.getPrestige() != alien2.getPrestige();
	cout << "Alien " << selection1 << " != " << "Alien " << selection2 << " is ";
	cout << compare << endl;
	compare = alien1.getPrestige() >= alien2.getPrestige();
	cout << "Alien " << selection1 << " >= " << "Alien " << selection2 << " is ";
	cout << compare << endl;
	compare = alien1.getPrestige() < alien2.getPrestige();
	cout << "Alien " << selection1 << " < " << "Alien " << selection2 << " is ";
	cout << compare << endl;
	compare = alien1.getPrestige() <= alien2.getPrestige();
	cout << "Alien " << selection1 << " <= " << "Alien " << selection2 << " is ";
	cout << compare << endl << endl;
}

void assignFunction(vector<Alien>& alienVector) {

}

int main()
{
	bool loop = true;
	int input;
	vector<Alien> alienVector;

	while (loop) {

		cout << "Main Menu: \n\n";
		cout << "1. Create alien\n";
		cout << "2. See available aliens\n";
		cout << "3. Create offsprings\n";
		cout << "4. Compare prestige\n";
		cout << "5. Assign alien\n";
		cout << "6. Exit\n\n";
		cout << "Please enter your option: ";
		cin >> input;

		if (cin.fail())
		{
			cout << "\nIncorrect input, please try again\n\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		else if (input == 1) {
			createAlien(alienVector);
			continue;
		}

		else if (input == 2) {
			displayAlien(alienVector);
			continue;
		}

		else if (input == 3) {
			offspringFunction(alienVector);
			continue;
		}

		else if (input == 4) {
			prestigeFunction(alienVector);
			continue;
		}

		else if (input == 5) {
			assignFunction(alienVector);
			continue;
		}

		else if (input == 6) {
			cout << "\nExiting Application...\n";
			return 0;
		}

		else {
			cout << "\nIncorrect input, please try again\n";
			continue;
		}
	}
}