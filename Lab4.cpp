#include <iostream>
#include <string>
using namespace std;
	
char* cambio(char*);
void imprimir(char**);
main() {

	string word1, word2;
	cout << "Ingrese la primera palabra." << endl;
	cin >> word1;
	cout << "Ingrese la segunda palabra." << endl;
	cin >> word2;
	//Metodo 1
	int num1, num2, cont = 0;
	num1 = word1.length();
	num2 = word2.length();
	char arr2[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        char* arr1 = arr2;
	char** mat = new char*[26];
	for(int i = 0; i < 26; i++) {
        	mat[i] = new char[26];
        }
	for(int i = 0; i < 26; i++) {
		cont = 0;
		while (cont < 26) {
                	mat[i][cont] = arr1[cont];
			cont++;
		}
		arr1 = cambio(arr1);
        }
	
	


	//-------------------------



	return 0;
}

char* cambio(char* arr) {
        char temp2 = arr[0];
        for (int j = 0; j < 26; j++) {
                //if(j != 26) {
                        temp2 = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp2;
                //}
        }
        arr[25] = temp2;
        return arr;
}
void imprimir(char**){
for (int i = 0; i < 26; i++) u{
                for(int j = 0; j < 26; j++) {
                        cout << "[" << mat[i][j] << "] ";
                }
        cout << endl;
        }
}
