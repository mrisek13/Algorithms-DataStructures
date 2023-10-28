#include <iostream>
#include <string>
using namespace std;

int main() {
	
  string food = "Pizza"; // instanciramo varijablu tipa string pri čemu zapisujemo vrijednost u tu varijablu
  string* ptr; // deklaracija pokazivača koji je tipa string
  //string* ptr = &food; // deklaracija + instanciranje pokazivača na memorijsku lokaciju u istom redu
  ptr = &food; // instanciramo pokazivač na memorijsku lokaciju varijable food

  cout << "1. Output the value of food: " << food << "\n";

  cout << "2. Output the memory address of food: " << &food << "\n";  // &identifikator se odnosi na memorijsku adresu

  cout << "3. Access the memory address of food and output its value: " << *ptr << "\n"; // *identifikator pristupa vrijednosti zapisanoj na toj adresi
  
  cout << "4. Change the value of the food!" << "\n";
  *ptr = "Hamburger"; // *identifikator može promjeniti vrijednost na toj adresi operatorom jednako (=)
  
  cout << "5. Output the new value of the pointer: " << *ptr << "\n";  // *identifikator pristupa vrijednosti zapisanoj na toj adresi
  
  cout << "6. Output the new value of the food variable: " << food << "\n";
  
  return 0;
}

/*
1. Output the value of food: Pizza
2. Output the memory address of food: 0x7ffd963a4700
3. Access the memory address of food and output its value: Pizza
4. Change the value of the pointer!
5. Output the new value of the pointer: Hamburger
6. Output the new value of the food variable: Hamburger
*/
