#include<iostream>
using namespace std;

int main()
{
	int A = 0; //���W 
 int B = 0; //���W 
 int C = 0; //�k�W 
 int D = 0; //���� 
 int E = 0; //���� 
 int F = 0;	//�k�� 
 int G = 0; //���U 
 int H = 0; //���U 
 int I = 0; //�k�U
 int Place_1 = 0; //�Ĥ@�ӤH�諸��m 
 int Place_2 = 0; //�ĤG�ӤH�諸��m 
 int Round = 0; //�^�X�� 
 int Winner = 0; //�Ӫ̬O~~ 
 int Round_1 = 0; //�ӧQ�^�X 
 int Garbage = 0; //�R�P���U���� 
 
while ( cin )
{
  A = 0; //���W 
  B = 0; //���W 
  C = 0; //�k�W 
  D = 0; //���� 
  E = 0; //���� 
  F = 0; //�k�� 
  G = 0; //���U 
  H = 0; //���U 
  I = 0; //�k�U

 while(Round <= 9)
 { Round ++ ; 
   if (Round % 2 == 1)
   {
   cin >> Place_1;
   if (Place_1 == 1)
   A = 1;
   if (Place_1 == 2)
   B = 1;
   if (Place_1 == 3)
   C = 1;
   if (Place_1 == 4)
   D = 1;
   if (Place_1 == 5)
   E = 1;
   if (Place_1 == 6)
   F = 1;
   if (Place_1 == 7)
   G = 1;
   if (Place_1 == 8)
   H = 1;
   if (Place_1 == 9)
   I = 1;
   } 
   else
   {
   cin >> Place_2;
   if (Place_2 == 1)
   A = 2;
   if (Place_2 == 2)
   B = 2;
   if (Place_2 == 3)
   C = 2;
   if (Place_2 == 4)
   D = 2;
   if (Place_2 == 5)
   E = 2;
   if (Place_2 == 6)
   F = 2;
   if (Place_2 == 7)
   G = 2;
   if (Place_2 == 8)
   H = 2;
   if (Place_2 == 9)
   I = 2;
   } ;
   
   if (Round < 9 &&
       A * B * C == 1 || 
       A * B * C == 8 || 
	   D * E * F == 1 || 
	   D * E * F == 8 || 
	   G * H * I == 1 || 
	   G * H * I == 8 ||
	   A * D * G == 1 ||
	   A * D * G == 8 ||
	   B * E * H == 1 ||
	   B * E * H == 8 ||
	   C * F * I == 1 ||
	   C * F * I == 8 ||
	   A * E * I == 1 ||
	   A * E * I == 8 ||
	   C * E * G == 1 ||
	   C * E * G == 8 )
	   {Winner = (Round-1) % 2 + 1;
	    break; } 
	   if (Round >= 9)/* &&
	   A * B * C != 1 && 
       A * B * C != 8 && 
	   D * E * F != 1 && 
	   D * E * F != 8 && 
	   G * H * I != 1 && 
	   G * H * I != 8 &&
	   A * D * G != 1 &&
	   A * D * G != 8 &&
	   B * E * H != 1 &&
	   B * E * H != 8 &&
	   C * F * I != 1 &&
	   C * F * I != 8 &&
	   A * E * I != 1 &&
	   A * E * I != 8 &&
	   C * E * G != 1 &&
	   C * E * G != 8 )*/ 
	   {Winner = 0;
	    break;} 	    
 }
        
       cout << Winner << " " << Round << endl;
       while ( (9 - Round) > 0 )
       {
       	cin >> Garbage;
       	Round++;
       }
       
       Round = 0;
       
}
	return 0;
}
