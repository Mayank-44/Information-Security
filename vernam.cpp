#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

static const char alphanum[] =
"abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;

char genRandom()  // Random string generator function.
{

    return alphanum[rand() % stringLength];
}


void encryptDecrypt(string toEncrypt,int ts,char key[]) 
{
   
    string output = toEncrypt;
    
    for (int i = 0; i < ts; i++)
        output[i] = toEncrypt[i] ^ key[i];
    
    cout<<"the encrypted text is:"<<output<<endl;

	for (int i = 0; i < ts; i++)
        toEncrypt[i] = output[i]^key[i];
    
    cout<<"the decrypted text is:"<<toEncrypt<<endl;
}

int main()
{
	string text;
	cout<<"enter the text:";
	getline(cin,text);
	int ts=text.length();
	srand(time(0));
	char key[ts];
	int z;
    for(z=0; z < ts; z++)
    {
        key[z]=genRandom();

    }
    key[z]='\0';
    cout<<key<<endl;
    encryptDecrypt(text,ts,key) ;
    return 0;

}
