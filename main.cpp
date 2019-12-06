/*
	Simple Calculator
	by Fadi. 

	Syntax:
		<register> <operation> <value>
		print <register>
		quit
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

	if (op == "quit" || op == "QUIT")
		return 5;
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

void sub(string register_name, int value)
{
	for (size_t i = 0; i < registers_vector.size(); i++)
	{
		if (register_name == registers_vector.at(i).name)
		{
			// If register already in vector
			registers_vector.at(i).val -= value;
			return;
		}
	}

	// Put new register in vector (if not in vector)
	reg temp;
	temp.val = value;
	temp.name = register_name;
	registers_vector.push_back(temp);
}

void mult()
{

}


void print_output()
{
	cout << "\n\nOutput: " << endl;

	for (size_t i = 0; i < output.size(); i++)
	{
		cout << output.at(i) << endl;
	}
}


int main(int argc, char** argv)
{
	string Line;

	while (true)
	{
		getline(cin, Line);

		stringstream ss;
		ss << Line;
		string Register, Operation, Value;
		ss >> Register >> Operation >> Value;

		if (Register == "print" || Register == "PRINT")
		{
			for (int i = 0; i < registers_vector.size(); i++)
			{
				if (Operation == registers_vector.at(i).name)
				{
					// If register already in register-vector add value to output
					output.push_back(registers_vector.at(i).val);
					//cout << registers_vector.at(i).val << " \n"; //DEBUG
					break;
				}
			}
			continue;
		}

		if (Register == "quit" || Register == "QUIT")
			break;

		switch (findOp(Operation))
		{
			// ADD
		case 1:
			add(Register, stoi(Value));
			break;

			// SUB
		case 2:
			sub(Register, stoi(Value));
			break;

			// MULT
		case 3:
			break;

		default:
			cout << "Unknown operation!\n";
		}
	}

	print_output();

	return 0;
}