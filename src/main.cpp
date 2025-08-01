#include <iostream>
using namespace std;


enum tempType{
	Fahrenheit = 1,
	Celsius = 2,
	Kelvin = 3
};

enum ConversionType{
	FtoC, CtoF, CtoK, KtoC, FtoK, KtoF
};

int selectTemp(){
	char input;
	
	cout << "Temperature types: F = Fahrenheit, C = Celsius, K = Kelvin, X = Exit" << endl;
	cin >> input;

	switch(input){
	
	case 'F':
		cout << "Selected Fahrenheit." << endl;
		return 1;
	case 'C':
		cout << "Selected Celsius." << endl;
		return 2;
	case 'K':
		cout << "Selected Kelvin." << endl;
		return 3;
	case 'X':
		
		return 0;
	default:
		cout << "Invalid Input" << endl;
		return 10;
	}

}

float convertTemp(int conversionType){
	float convertedTemp = 0.0f;
	float temperature = 0.0f;
	cout << "Input Temperature to Convert." << endl;
	cin >> temperature;
	
	switch(conversionType){
	// F > C
	case FtoC:
		convertedTemp = (5.0 / 9.0) * (temperature - 32);
		return convertedTemp;
	// C > F
	case CtoF:
		convertedTemp = ((9.0 / 5.0) * temperature) + 32;
		return convertedTemp;
	// C > K
	case CtoK:
		convertedTemp = temperature + 273.15f;
		return convertedTemp;
	// K > C
	case KtoC:
		convertedTemp = temperature - 273.15f;
		return convertedTemp;
	// F > K
	case FtoK:
		convertedTemp = ((5.0 / 9.0) * (temperature - 32)) + 273.15;
		return convertedTemp;
	// K > F
	case KtoF:
		convertedTemp = ((temperature - 273.15) * (9.0 / 5.0)) + 32;
		return convertedTemp;
	default:
		cout << "Error" << endl;
		return 0.0;
	}
	return 0.0;
}


int main(){
	int input = -1;
	int input2 = -1;
		
	
	while (true){
		cout << "Select Beginning Temperature" << endl;
		input = selectTemp();

		if(input == 0) return 0;

		switch(input){
		case Fahrenheit:
		{
			cout << "Select Ending Temperature" << endl;
			input2 = selectTemp();
			if(input2 == 0) return 0;
			
			switch(input2){
			case Fahrenheit:
				cout << "You've selected Fahrenheit twice, no conversion needed." << endl;
				break;
			case Celsius:
				cout << convertTemp(FtoC) << " Degrees Celsius." << endl;
				break;
			case Kelvin:
				cout << convertTemp(FtoK) << " Degrees Kelvin." << endl;
				break;
			}
			break;
		}
		case Celsius:
		{
			cout << "Select Ending Temperature" << endl;
			input2 = selectTemp();
			if(input2 == 0) return 0;

			switch(input2){
			case Fahrenheit:
				cout << convertTemp(CtoF) << " Degrees Fahrenheit." << endl;
				break;
			case Celsius:
				cout << "You've selected Celsius twice, no conversion needed." << endl;
				break;
				
			case Kelvin:
				cout << convertTemp(CtoK) << " Degrees Kelvin." << endl;
				break;
			}
			break;

		}
		case Kelvin:
		{
			cout << "Select Ending Temperature" << endl;
			input2 = selectTemp();
			if(input2 == 0) return 0;

			switch(input2){
			case Fahrenheit:
				cout << convertTemp(KtoF) << " Degrees Fahrenheit." << endl;
				break;
			case Celsius:
				cout << convertTemp(KtoC) << " Degrees Celsius." << endl;
				break;
			case Kelvin:
				
				cout << "You've selected Kelvin twice, no conversion needed." << endl;
				break;
			}
			break;

		}

		}

	}

	return 0;

}







