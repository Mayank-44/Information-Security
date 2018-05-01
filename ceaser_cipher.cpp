#include <iostream>
#include<string>
#include<cstdio>
using namespace std;
int keya=3;
void adecode(char output[],int s,char init[])
{
	for(int i=0;output[i]!='\0';i++)
	{
		if(output[i]==' ')
		init[i]=output[i];
		else
		init[i]=((output[i]-97+(26-keya))%26)+97;
	}
	init[s]='\0';
	cout<<endl<<endl;
	cout<<"The original code was:  "<<init<<endl;
}

void aencode(char init[],int s,char output[])
{
	for(int i=0;i<s;i++)
	{
		if(init[i]==' ')
		output[i]=init[i];
		else
		output[i]=((init[i]-97+keya)%26)+97;
	}
	output[s]='\0';
	cout<<"The encoded text is:";
	cout<<output;
	cout<<endl;
	adecode(output,s,init);	                //calling the decoding func. automatically
}

int main()
{
	string text;
	cout<<"Enter the line:  ";
	getline(cin,text);
	int s=text.length();
	
	char ar[s],output[s];
		
	for(int i=0;i<s;i++)
	ar[i]=text.at(i);
	ar[s]='\0';
	cout<<endl;
	
	aencode(ar,s,output);
	
	return 0;
}
