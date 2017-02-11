#include <iostream>
#include <string>
#include <bitset>

using namespace std;
	
main() {

	string word1, word2;
	cout << "Ingrese la palabra clave." << endl;
	cin >> word1;
	cout << "Ingrese el texto a cifrar." << endl;
	cin >> word2;
	//Metodo 1
	


	//-------------------------

	//metodo 2

	cout<<"\n Cifrado de Cesar Rot13"<<endl;
	int cont=0;
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
		cout<<"bits "<<bincifrado[i].to_ulong()<<endl;
	}

return 0;
}//fin main
