#include <iostream>
#include <string>
#include <vector>
/*terminal (simple) calculator project*/
enum OPERATIONS
{
	ADD = 43,
	REST = 45,
	MULTIPLY = 42,
	DEVIDE = 47
};

class Calculator 
{
private:
	bool m_bIsStartingNumber = true;
	std::string m_sInput;
	double m_dOutput;
	std::vector<double> m_vOperands;
	std::vector<double> m_vOperators;

	void takeInput()
	{
		std::cin >> m_sInput;
	}
	void parseInput()
	{
		int prevToken = 48;
		for (int n = 0; n < m_sInput.size(); n++)
		{
			int token = m_sInput[n];
			if(n>0)
				prevToken = m_sInput[n-1];

			switch (token)
			{
			case OPERATIONS::ADD:
				if (prevToken >= 48 || prevToken <= 57)
					m_vOperators.push_back(token);
				break;
			case OPERATIONS::MULTIPLY:
				if (prevToken >= 48 || prevToken <= 57)
					m_vOperators.push_back(token);
				break;
			case OPERATIONS::DEVIDE:
				if (prevToken >= 48 || prevToken <= 57)
					m_vOperators.push_back(token);
				break;
			case	OPERATIONS::REST:
				if (prevToken >= 48 || prevToken <= 57)
					m_vOperators.push_back(token);
				break;
			default:
					if(token >= 48 || token <= 57)
						if(n > 0)
							if (prevToken >= 48 && prevToken <= 57)
								m_vOperands[m_vOperands.size() - 1] = m_vOperands[m_vOperands.size() - 1] * 10 + token - 48;
							else
								m_vOperands.push_back(token - 48);
						else
							m_vOperands.push_back(token - 48);
				break;
			}
		}
			
	}

	int calculate()
	{
		m_dOutput = m_vOperands[0];
		for (int i = 1; i < m_vOperands.size(); ++i)
		{
			double operand = m_vOperands[i];
				int token = m_vOperators[i-1];
				switch (token)
				{
				case OPERATIONS::ADD:
					m_dOutput = m_dOutput + operand;
					break;
				case OPERATIONS::REST:
					m_dOutput = m_dOutput - operand;
					break;
				case OPERATIONS::MULTIPLY:
					m_dOutput = m_dOutput * operand;
					break;
				case OPERATIONS::DEVIDE:
					m_dOutput = m_dOutput / operand;
					break;
			/*	m_dOutput = m_dOutput + operand */
			}
		}
		return m_dOutput;
	}

	void printResults()
	{
		std::cout << m_dOutput << std::endl;
	}

	void clean()
	{
		m_dOutput = 0;
		m_sInput.clear();
		m_vOperands.clear();
		m_vOperators.clear();
	}

public:
	void run()
	{
		while (true)
		{
			takeInput();
			parseInput();
			calculate();
			printResults();
			clean();

		}
	}
};

int main()
{
	/*
		TODO:
		take inputs from user;
		allow operations of + or - or * or /
		it will output the result of the math operation of the input
		calculator will work with arithmetics rules e.g * before +, and ( or [ are acceptable grouping symbols
	*/
	Calculator calculator = {};
	calculator.run();
	

	return 0;
}