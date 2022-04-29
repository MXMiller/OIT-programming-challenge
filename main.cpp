#include <iostream>
#include <vector>

using namespace std;

int RomToDec(vector<char> input){
	//convert from roman to decimal
	int dec = 0;
	int next = 0;

	//go through each letter in the roman numeral
	
	for(int i = input.size() - 1; i >= 0; i--){
				
		if(i - 1 >= 0){
			next = i - 1;
		}

		if(input.at(i) == 'I' || input.at(i) == 'i'){
			
			dec += 1;
		}
		else if(input.at(i) == 'V' || input.at(i) == 'v'){
			
			dec += 5;
			if(input.at(next) == 'I' || input.at(next) == 'i'){
				dec -= 1;
				i--;
			}
		}
		else if(input.at(i) == 'X' || input.at(i) == 'x'){
			
			dec += 10;
			if(input.at(next) == 'I' || input.at(next) == 'i'){
				dec -= 1;
				i--;
			}
		}
		else if(input.at(i) == 'L' || input.at(i) == 'l'){
			
			dec += 50;
			if(input.at(next) == 'X' || input.at(next) == 'x'){
				dec -= 10;
				i--;
			}
		}
		else if(input.at(i) == 'C' || input.at(i) == 'c'){
			
			dec += 100;
			if(input.at(next) == 'X' || input.at(next) == 'x'){
				dec -= 10;
				i--;
			}
		}
		else if(input.at(i) == 'D' || input.at(i) == 'd'){
			
			dec += 500;
			if(input.at(next) == 'C' || input.at(next) == 'c'){
				dec -= 100;
				i--;
			}
		}
		else if(input.at(i) == 'M' || input.at(i) == 'm'){
			
			dec += 1000;
			if(input.at(next) == 'C' || input.at(next) == 'c'){
				dec -= 100;
				i--;
			}
		}
	}	

	return dec;
}

string DecToRom(vector<char> input){
	//convert from decimal to roman
	string rom;
	int i = 0;

	for(int i = input.size() - 1; i >= 0; i--){

		//cout << i << ": " << input.at(i) << endl;

		int j = input.size() - 1 - i;
		
		int curr;

		//get current value		
		if(input.at(i) == '1'){
			curr = 1;
		}
		else if(input.at(i) == '2'){
			curr = 2;
		}
		else if(input.at(i) == '3'){
			curr = 3;
		}
		else if(input.at(i) == '4'){
			curr = 4;
		}
		else if(input.at(i) == '5'){
			curr = 5;
		}
		else if(input.at(i) == '6'){
			curr = 6;
		}
		else if(input.at(i) == '7'){
			curr = 7;
		}
		else if(input.at(i) == '8'){
			curr = 8;
		}
		else if(input.at(i) == '9'){
			curr = 9;
		}
		else if(input.at(i) == '0'){
			curr = 0;
		}

		//convert to roman numeral
		if(curr == 1){
			if(j == 3){
				rom = "M" + rom;
			}else if(j == 2){
				rom = "C" + rom;
			}else if(j == 1){
				rom = "X" + rom;
			}else if(j == 0){
				rom = "I" + rom;
			}
		}
		else if(curr == 2){
			if(j == 3){
				rom = "MM" + rom;
			}else if(j == 2){
				rom = "CC" + rom;
			}else if(j == 1){
				rom = "XX" + rom;
			}else if(j == 0){
				rom = "II" + rom;
			}
		}
		else if(curr == 3){
			if(j == 3){
				rom = "MMM" + rom;
			}else if(j == 2){
				rom = "CCC" + rom;
			}else if(j == 1){
				rom = "XXX" + rom;
			}else if(j == 0){
				rom = "III" + rom;
			}
		}
		else if(curr == 4){
			if(j == 2){
				rom = "CD" + rom;
			}else if(j == 1){
				rom = "XL" + rom;
			}else if(j == 0){
				rom = "IV" + rom;
			}
		}
		else if(curr == 5){
			if(j == 2){
				rom = "D" + rom;
			}else if(j == 1){
				rom = "L" + rom;
			}else if(j == 0){
				rom = "V" + rom;
			}
		}
		else if(curr == 6){
			if(j == 2){
				rom = "DC" + rom;
			}else if(j == 1){
				rom = "LX" + rom;
			}else if(j == 0){
				rom = "VI" + rom;
			}
		}
		else if(curr == 7){
			if(j == 2){
				rom = "DCC" + rom;
			}else if(j == 1){
				rom = "LXX" + rom;
			}else if(j == 0){
				rom = "VII" + rom;
			}
		}
		else if(curr == 8){
			if(j == 2){
				rom = "DCCC" + rom;
			}else if(j == 1){
				rom = "LXXX" + rom;
			}else if(j == 0){
				rom = "VIII" + rom;
			}
		}
		else if(curr == 9){
			if(j == 2){
				rom = "CM" + rom;
			}else if(j == 1){
				rom = "XC" + rom;
			}else if(j == 0){
				rom = "IX" + rom;
			}
		}
	}	
	
	return rom;
}

int main() {

	string input;
	bool roman;
	string rom;
	int dec;	

	//get input
  cout << "Please input number: \n";
	cin >> input;
	
	vector<char> inputAsChars(input.begin(), input.end());

	char f = inputAsChars.at(0);

	//determine if it's decimal to roman or roman to decimal
	if(f == '1' || f == '2' || f == '3' || f == '4' || f == '5' || f == '6' || f == '7' || f == '8' || f == '9'){
		roman = false;
	}
	else{
		roman = true;
	}

	/*
	for(int i = 0; i < inputAsChars.size(); i++){
		cout << i << ": " << inputAsChars.at(i) << endl;
	}
	*/

	//call functions
	if(roman == true){
		
		cout << "Converting from Roman to Decimal...\n";
		dec = RomToDec(inputAsChars);
		
		//output the converted int
		cout << "Converted number: " << dec << endl;
	}
	else if(roman == false){
		
		cout << "Converting from Decimal to Roman...\n";
		rom = DecToRom(inputAsChars);

		//output the converted string
		cout << "Converted number: " << rom << endl;		
	}
	
}