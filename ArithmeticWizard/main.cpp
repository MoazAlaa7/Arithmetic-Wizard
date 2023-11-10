#include <iostream>
#include <random>

void setupProgram(int&, int&);
int generateProblem(int, int);
int adjustDifficultyLevel(int);
int adjustProblemType(int, int, int);
bool validateAnswer(int, int);

int main() {
	// Program Loop
	while (true) {
		int problemType;
		int diffLvl;
		setupProgram(problemType, diffLvl);
		int userAns = 0;
		bool answerValid;
		while (userAns != -1) {
			int problemAns = generateProblem(problemType, diffLvl);
			answerValid = 0;
			while (!answerValid && userAns != -1) {
				std::cin >> userAns;
				answerValid = validateAnswer(problemAns, userAns);
				std::cout << '\n';
			}
		}
	}
	return 0;
}

void setupProgram(int& problemType, int& diffLvl) {
	srand(time(NULL));
	std::cout << "Welcome to ArithmeticWizard!\n"
		"a place to practice your arithmetic skills. \n\n";
	std::cout << "Choose the type of arithmetic problems to study:\n"
		"(1) for addition\n(2) for subtraction\n(3) for multiplication\n"
		"(4) for division (Please, Floor your asnwer to an integer number)\n(5) for a mixture of all types\n\n";
	std::cin >> problemType;
	while (std::cin.fail() || problemType > 5 || problemType < 1) {
		std::cout << "Please enter a valid option\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> problemType;
	}

	std::cout << "\nEnter a difficulty level. At a difficulty level of (1), \n"
		"the program uses only single-digit numbers in the problems;\n"
		"at a difficulty level of (2), numbers as large as two digits, and so on.\n"
		"(Maximum difficulty level is 4)\n\n";
	std::cin >> diffLvl;
	while (std::cin.fail() || diffLvl > 4 || diffLvl < 1) {
		std::cout << "Please enter a valid option\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> diffLvl;
	}

	std::cout << "\nTo go back to options: Enter (-1).\n";
	std::cout << "\nReady to master arithmetics?\nLet's go!\n";
}

int generateProblem(int problemType, int diffLvl) {
	int maxNum = adjustDifficultyLevel(diffLvl);
	int num1 = rand() % maxNum + 1;
	int num2 = rand() % maxNum + 1;
	int ans = adjustProblemType(problemType, num1, num2);
	return ans;
}

int adjustDifficultyLevel(int diffLvl) {
	// Maximum number composed of (diffLvl) digits
	int maxNum = pow(10, diffLvl) - 1;
	return maxNum;
}

int adjustProblemType(int problemType, int num1, int num2) {
	int ans;
	int mixType = rand() % 4 + 1;
	int mx = std::max(num1, num2);
	int mn = std::min(num1, num2);
	if (problemType == 1 || (problemType == 5 && mixType == 1)) {
		ans = num1 + num2;
		std::cout << "\nHow much is " << num1 << " + " << num2 << "?\n";
	}
	else if (problemType == 2 || (problemType == 5 && mixType == 2)) {
		ans = mx - mn;
		std::cout << "\nHow much is " << mx << " - " << mn << "?\n";
	}
	else if (problemType == 3 || (problemType == 5 && mixType == 3)) {
		ans = num1 * num2;
		std::cout << "\nHow much is " << num1 << " * " << num2 << "?\n";
	}
	else if (problemType == 4 || (problemType == 5 && mixType == 4)) {
		ans = mx / mn;
		std::cout << "\nHow much is " << mx << " / " << mn << "?\n";
	}
	return ans;
}

bool validateAnswer(int problemAns, int userAns) {
	// Program response to user answer
	int response = rand() % 4 + 1;
	if (userAns == -1) return 0;
	while (userAns != problemAns) {
		response = rand() % 4 + 1;
		switch (response) {
			case 1:
				std::cout << "No. Please try again";
				break;
			case 2:
				std::cout << "Wrong. Try once more.";
				break;
			case 3:
				std::cout << "Nope. Don't give up!";
				break;
			case 4:
				std::cout << "No. Keep trying";
				break;
		}
		return 0;
	}
	switch (response) {
		case 1:
			std::cout << "Very good!";
			break;
		case 2:
			std::cout << "Excellent!";
			break;
		case 3:
			std::cout << "Nice work!";
			break;
		case 4:
			std::cout << "Keep up the good work!";
			break;
	}
	return 1;
}