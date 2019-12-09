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

// Register containing:
// value (int) and name (string)
struct reg {
	int val;
	string name;
	vector<string> value_memory;
};

vector<reg> registers_vector;
vector<int> output;


int findOp(const string op)
{
	if (op == "add" || op == "ADD")
		return 1;
	if (op == "subtract" || op == "SUBTRACT")
		return 2;
	if (op == "multiply" || op == "MULTIPLY")
		return 3;
}

void math_operation(string register_name, int value, char operation)
{
	for (size_t i = 0; i < registers_vector.size(); i++)
	{
		if (register_name == registers_vector.at(i).name)
		{
			// If register already in vector
			if (operation == '+')
				registers_vector.at(i).val += value;
			else if (operation == '-')
				registers_vector.at(i).val -= value;
			else if (operation == '*')
				registers_vector.at(i).val *= value;
			return;
		}
	}

	// Put new register in vector (if not in vector)
	reg temp;
	temp.val = value;
	temp.name = register_name;
	registers_vector.push_back(temp);
}



void print_output()
{
	cout << "\n\nOutput: " << endl;

	for (size_t i = 0; i < output.size(); i++)
	{
		cout << output.at(i) << endl;
	}
}

bool is_number(const string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it))
		++it;
	return !s.empty() && it == s.end();
}

// Checks if the value is a register (string)
bool check_if_value(const string value_register, const string Operation)
{
	if (!is_number(value_register))
	{
		stringstream tmp;
		tmp << Operation << ' ' << value_register;

		for (size_t i = 0; i < registers_vector.size(); i++)
		{
			if (value_register == registers_vector.at(i).name)
			{
				// Add this value to the registers memory
				registers_vector.at(i).value_memory.push_back(tmp.str());
				cout << "Found such value!\n"; // DEBUG
				return true;
			}
		}
		// If the value-register doesn't already exist, create one
		reg temp;
		temp.val = 0;
		temp.name = value_register;
		registers_vector.push_back(temp);
		cout << "Added a new register as value in vector!\n"; // DEBUG
		return true;
	}
	return false;
}


int main(int argc, char* argv[])
{
	string Line;
	bool file_as_input = false;
	ifstream input_file;

	if (argc > 1)
	{
		//cout << "vi har en fil!\n"; // DEBUG
		file_as_input = true;
		input_file.open(argv[1], ifstream::in);
	}

	while (true)
	{
		if (!file_as_input)
			getline(cin, Line);
		else
		{
			if (input_file.is_open())
				getline(input_file, Line);
			else
			{
				cout << "Could not find file!\n";
				return -1;
			}
		}
			

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

		// If its not a number, reference to the register.
		if (check_if_value(Value, Operation))
			continue;


		// cout << Register << Operation << Value; // DEBUG

		switch (findOp(Operation))
		{
			// ADD
		case 1:
			math_operation(Register, stoi(Value), '+');
			break;

			// SUB
		case 2:
			math_operation(Register, stoi(Value), '-');
			break;

			// MULT
		case 3:
			math_operation(Register, stoi(Value), '*');
			break;

		default:
			cout << "Unknown operation!\n";
		}
	}

	print_output();

	return 0;
}