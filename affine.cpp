#include<iostream>
#include<cstdio>

using namespace std;

int keym=0,c=0;				//multiplicative cypher key


int keya=0;					//additive cipher key

void mdecode(char init[],int s,char output[],int pkey[])
{
	
	int k_inv=0;
	for(int i=0;i<12;i++)
	{
			if((keym*pkey[i])%26==1)
			{
				k_inv=pkey[i];
				break;
			}	
			
	}
	cout<<endl;
	for(int i=0;i<s;i++)
	{
		if(init[i]==' ')
		output[i]=init[i];
		else
		output[i]=(((init[i]-97)*k_inv)%26)+97;
	}
	output[s]='\0';
	cout<<endl<<endl;
	cout<<"The original code after multiplicative decode:  "<<output<<endl;
	
}

void adecode(char init[],int s,char output[],int pkey[])
{
	for(int i=0;i<s;i++)
	{
		if(init[i]==' ')
		output[i]=init[i];
		else
		output[i]=((init[i]-97+(26-keya))%26)+97;
	}
	output[s]='\0';
	cout<<endl<<endl;
	cout<<"The text after additive decode was:  "<<output<<endl;
	mdecode(output,s,init,pkey);	     //calling the decoding func. automatically
}


void aencode(char init[],int s,char output[],int pkey[])
{
	for(int i=0;i<s;i++)
	{
		if(init[i]==' ')
		output[i]=init[i];
		else
		output[i]=((init[i]-97+keya)%26)+97;
	}
	output[s]='\0';
	cout<<"The encoded text after additive encode is:";
	cout<<output;
	cout<<endl;
	adecode(output,s,init,pkey);	     //calling the decoding func. automatically
//	adecode(output,s,init);	                //calling the decoding func. automatically
}

void possible_keys(int pkey[])          //calculating the set of possible keys
{
	for(int i=1;i<26;i++)
	{
		for(int j=i;j>=1;j--)
		{
			if(i%j==0 && 26%j==0)
			{
				if(j==1)
				pkey[c++]=i;
				break;
			}
		}
	}
}


void mencode(char init[],int s,char output[],int pkey[])
{
	for(int i=0;i<s;i++)
	{
		if(init[i]==' ')		//keeping white spaces without encoding
		output[i]=init[i];
		else
		output[i]=(((init[i]-97)*keym)%26)+97;
	}
	output[s]='\0';
	cout<<"the encoded text after multiplicative is:";
	cout<<output;
	cout<<endl;
	
	cout<<"calling additive cipher....."<<endl;
	aencode(output,s,init,pkey);

}


int main()
{

	string text;
	int pkey[12];
	cout<<"Enter the line:";
	getline(cin,text);
	
	int s=text.length();
	char ar[s],output[s];
	
	for(int i=0;i<s;i++)
	ar[i]=text.at(i);
	ar[s]='\0';
	possible_keys(pkey);            //calling function to caluculate all possible keys
	
	K:
	cout<<endl;
	cout<<"Enter the multiplicative key: ";
	cin>>keym;
	
	cout<<"Enter the keya b/w 1-26:  ";
	cin>>keya;
	
	for(int i=0;i<12;i++)
	{
			if(keym==pkey[i])
			break;
			else if(i==11)
			{
					cout<<endl<<"Wrong key, enter key from the given set."<<endl;
					for(int k=0;k<12;k++)
					cout<<pkey[k]<<" ";
					goto K;
					cout<<endl;
			}
	}
	cout<<endl;
	mencode(ar,s,output,pkey);	      //calling the encoding function
	
	return 0;
}
