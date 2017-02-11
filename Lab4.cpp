#include <iostream>
#include <string>
#include <bitset>



using namespace std;
	
char* cambio(char*);
void imprimir(char**);
main() {

	string word1, word2;

	cout << "Ingrese la palabra clave." << endl;
	cin >> word1;
	cout << "Ingrese el texto a cifrar." << endl;
	cin >> word2;
	//Metodo 1
	int num1, num2, cont = 0, X, Y;
	num1 = word1.length();
	char arr2[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        char arr3[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
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
	//arr1 = cambio(arr1);
	char temp, temp1;
	int cont1 = 0, cont2 = 0;
	for(int i = 0; i < word2.length(); i++) {
		if (word1[i] != ' ') {
			temp = word1[cont1];
			temp1 = word2[cont2];
			for (int j = 0; j < 26; j++) {
				if (temp == arr2[j]) {
					X = j;	
				}
				if (temp1 == arr2[j]) {
					Y = j;
				}
			}
			word2[i] = mat[X][Y];
		}
		cont1++;
		cont2++;
		if (cont1 == num1) {
			cont1 = 0;
		}
	}
	
	cout << word2 << endl;
	//-------------------------

	//metodo 2

	cout<<"\n Cifrado de Cesar Rot13"<<endl;
	cont=0;
	for(int i=0;i<word2.length();i++)
	{
		if(word2[i]+13<=122)
		{

			cout<<char(word2[i]+13)<< endl;
			word2[i]=char(word2[i]+13);
		}else 
		{
			cont=(word2[i]+13)-122;
			cout<<char(97+cont)<<endl;
			word2[i]=char(97+cont);
		}

	}

	

	cout<<"----------------"<< endl;

	 
	

	//----------------------------------------

	//metodo3
	
	cout<<"\n Cifrado de XOR"<<endl;
	int* arreglo=new int[word1.length()];	
	int* arreglo2=new int[word2.length()];
	bitset<8> bin[word1.length()];
	bitset<8> bin2[word2.length()];
	bitset<8> bincifrado[word1.length()];

	for(int i=0;i<word1.length();i++)
	{
		int t=word1.at(i);
		arreglo[i]=t;

	}


	for(int i=0;i<word2.length();i++)
	{
		int t=word2.at(i);
		arreglo2[i]=t;
	}

	for(int i=0;i<word1.length();i++)
	{
		bin[i]=arreglo[i];
	}
	for(int i=0;i<word2.length();i++)
	{
		bin2[i]=arreglo2[i];
	}

	int a=0;
	for(int i=0;i<word2.length();i++)
	{
		cout<<"cifrado "<<(bin[i]^bin2[i])<<endl;

	bincifrado[i]=bin[a]^bin2[i];
	a++;
		if(a<=word1.length())
		{
			a=0;
		}
	}
	
	for(int i=0;i<word2.length();i++)
	{
		cout<<"Numeros: "<<bincifrado[i].to_ulong()<<endl;
	}

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
void imprimir(char** mat){
	for (int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                        cout << "[" << mat[i][j] << "] ";
                }
        cout << endl;
        }
}

