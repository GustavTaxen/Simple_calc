/*
	Simple Calculator
	by Fadi

*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

struct reg {
	int val;
	string name;
};

vector<reg> registers_vector = {};
vector<int> output;


int findOp(string op)
{
	if (op == "add" || op == "ADD")
		return 1;
	if (op == "subtract" || op == "SUBTRACT")
		return 2;
	if (op == "multiply" || op == "MULTIPLY")
		return 3;
	if (op == "print" || op == "PRINT")
		return 4;
}

void add(string register_name, int value)
{
	for (size_t i = 0; i < registers_vector.size(); i++)
	{
		if (register_name == registers_vector.at(i).name)
		{
			// If register already in vector
			registers_vector.at(i).val += value;
			return;
		}
	}

	// Put new register in vector (if not in vector)
	reg temp;
	temp.val = value;
	temp.name = register_name;
	registers_vector.push_back(temp);
}

void sub()
{

}

void mult()
{

}



int main(int argc, char** argv)
{
	cout << "<register> <operation> <value> \n";

	string Line;
	getline(cin, Line);

	stringstream ss;
	ss << Line;
	string Register, Operation, Value;
	ss >> Register >> Operation >> Value;


	switch (findOp(Operation))
	{
		// ADD
	case 1:
		add(Register, stoi(Value));
		break;
		// SUB
	case 2:
		break;
		// MULT
	case 3:
		break;
		// PRINT
	case 4:
		cout << "hej";
		break;
	default:
		cout << "Unknown operation!\n";
	}

	return 0;
}

//void debug()
//{
//	cout << "Register: " << Register << endl;
//	cout << "Operation: " << Operation << endl;
//	cout << "Value: " << Value << endl;
//}