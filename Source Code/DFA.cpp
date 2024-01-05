#include <iostream>
#include<map>
#include<vector>
#include <algorithm>

using namespace std;

class DFA {

private:
	int numOfStates;
	vector<int>states;
	char alphabet1, alphabet2;
	int startState;
	int numOfAcceptStates;
	vector<int>acceptStates;
	map<pair<int, char>, int>transitionsOfStates;
	int flag = 0;

public:
	// get states method
	void getState()
	{
		for (int i = 0; i < getNumOfStates(); i++)
		{
			states.push_back(i);
			cout << i << " ";
		}
	}

	//
	//accepted states method
	void AcceptStates()
	{
		for (int i = 1; i <= getNumOfAcceptStates(); i++)
		{
			cout << " Enter " << i << " accept state : " << endl;

			int acceptState;
			cin >> acceptState;
			if (std::find(states.begin(), states.end(), acceptState) != states.end())
				acceptStates.push_back(acceptState);
		}
	}

	//
	//transitions method
	void Transitions()
	{
		for (int i = 0; i < states.size(); i++)
		{
			int trans1, trans2;
			cout << " Enter the transitions of state " << states[i] << endl;
			cout << "State " << i << " at alphabet " << getAlphabet1() << ":\n";
			cin >> trans1; // next state when alphabet ...
			if (std::find(states.begin(), states.end(), trans1) != states.end())
			transitionsOfStates[{ i, getAlphabet1() }] = trans1;
			else
			{
				cout << "Error" << endl;
				flag = 1;
				break;
				
			}
			cout << "State " << i << " at alphabet " << getAlphabet2() << ":\n";
			cin >> trans2;
			if (std::find(states.begin(), states.end(), trans2) != states.end())
			   transitionsOfStates[{ i, getAlphabet2() }] = trans2;
			else
			{
				cout << "Error"<< endl;
				flag = 1;
				break;
			}
		}
	}

	// check if it is a valid string or not
	bool IsValid(string str) {
		int currentState = getStartState();

		for (int i = 0; i < str.size(); i++) {
			if (str[i] != getAlphabet1()) {
			
				if (str[i] != getAlphabet2()) {
					
					return false;
				}
			}
			currentState = transitionsOfStates[{ currentState, str[i] }];
		}

		if (std::find(acceptStates.begin(), acceptStates.end(), currentState) != acceptStates.end())
			return true;
		return false;
	}

	//setters and getters

	//setter and getter for  number of states
	void setNumOfStates(int numOfStates) {
		this->numOfStates = numOfStates;
	}
	int getNumOfStates() {
		return this->numOfStates;
	}

	int getFlag() {
		return this->flag;
	}

	//setter and getter for alphabet
	void setAlphabets(char alpha1, char alpha2)
	{
		this->alphabet1 = alpha1;
		this->alphabet2 = alpha2;
	}
	char getAlphabet1()
	{
		return this->alphabet1;
	}
	char getAlphabet2()
	{
		return this->alphabet2;
	}

	//setter and getter for  start state
	void setStartState(int startState)
	{
		this->startState = startState;
	}
	int getStartState()
	{
		return this->startState;
	}

	//setter and getter for  accept state
	void setNumOfAcceptStates(int noAcceptStates)
	{
		this->numOfAcceptStates = noAcceptStates;
	}
	int getNumOfAcceptStates()
	{
		return this->numOfAcceptStates;
	}

};

int main()
{
	DFA dfa;

	int numOfStates;

	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";

	cout << "Enter the number of states in your DFA design : \n";
	cin >> numOfStates;
	if (numOfStates > 0)
		dfa.setNumOfStates(numOfStates);
	else {
		cout << "Error\n";
		return 0;
	}
	cout << "The created States are: \n";
	dfa.getState();

	cout << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";

	char alphabet1, alphabet2;
	cout << "Enter the two Alphabets of your DFA : \n";
	cout << "First alphabet of your DFA : ";
	cin >> alphabet1;
	cout << "Second alphabet of your DFA : ";
	cin >> alphabet2;
	dfa.setAlphabets(alphabet1, alphabet2);

	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";

	int start_state;
	cout << "What is the start state in your DFA : \n";
	cin >> start_state;
	if(start_state>=0&&start_state< dfa.getNumOfStates())	
	 dfa.setStartState(start_state);
	else
	{
		cout << "Error.\n";
		return 0;
	}

	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";

	int num_of_accept_states;
	cout << "What is the number of accept states in your DFA : \n";
	cin >> num_of_accept_states;
	if (num_of_accept_states <= dfa.getNumOfStates() && num_of_accept_states >= 0)
		dfa.setNumOfAcceptStates(num_of_accept_states);
	else {
		cout << "Error.\n";
		return 0;
	}

	dfa.AcceptStates();

	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";

	dfa.Transitions();
	if (dfa.getFlag())
	{
		return 0;
	}

	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
	cout << endl;

	while (true) {
		cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
		string s, x;
		cout << "If you want to exit enter x: ";
		cin >> x;
		if (x[0] == 'x')
			break;
		cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n";
		cout << "Enter the string: \n";
		cin >> s;
		if (dfa.IsValid(s) == true)
			cout << " The string "<<s<<" is Accepted.\n";
		else
			cout << " The string "<< s <<" is Rejected.\n";
	}
	cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";

	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
	return 0;
}

