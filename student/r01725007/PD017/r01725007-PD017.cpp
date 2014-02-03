#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
	string input;
	while(cin)
	{
		getline(cin,input);
		int spaceNum=0;
		for(int i=0;i<input.size();i++) //���ťժ��Ӽ� 
		{
			if(input[i]==' ')
			spaceNum++;
		}
		int* space=new int[spaceNum];
		for(int i=0,j=0;i<input.size() && j<spaceNum;i++)//�x�s�ťժ���m 
		{
		 	if(input[i]==' ')
		 	{
		 		space[j]=i;
		 		j++;
		 	}
		}
		string* sSplit= new string [spaceNum+1];
		
		for(int i=0;i<spaceNum+1;i++) //��r����� 
		{
		    if(i==0)
			sSplit[i]=sSplit[i].assign(input,0,space[i]);
			else if(i==spaceNum)
			sSplit[i]=sSplit[i].assign(input,space[i-1]+1,input.size()-space[i-1]-1);
			else
			sSplit[i]=sSplit[i].assign(input,space[i-1]+1,space[i]-space[i-1]-1);
		}
		int* relation=new int [spaceNum+1];
		char* cStr=new char [10];  
		for (int i=0;i<spaceNum+1;i++)
		{
			strcpy(cStr,sSplit[i].c_str()); //���N�l�r���ରc string 
			relation[i]=atoi(cStr); //�A�Nc string �ন���
		}
		
		int peopleNum=0;
		for(int i=0;i<spaceNum+1;i++) //�H�ƴN�O��J�Ȫ��̤j�� 
		{
			if(relation[i]>peopleNum)
			peopleNum=relation[i];
		}
	
		int* score=new int [peopleNum];
		for(int i=0;i<peopleNum;i++)
		{
			score[i]=0;
		}
		for(int i=0;i<spaceNum+1;i=i+2)
		{
			int know=0,beKnown=0;
			know=relation[i];
			beKnown=relation[i+1];
			score[know-1]--;
			score[beKnown-1]++;
		}
		
		int max=score[0];
		for(int i=1;i<peopleNum;i++)
		{
			if(score[i]>max)
			{
				max=score[i];
			}
		}
		for(int i=0;i<peopleNum;i++)
		{
			if(score[i]==max)
			cout<<i+1<<" "; 
		}
		cout<<endl;
		delete [] space;
		delete [] sSplit;
		delete [] relation;
		delete [] score;
	}
	
	return 0;
}
