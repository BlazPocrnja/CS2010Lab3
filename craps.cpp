#include <iostream>
#include <stdlib.h>
using namespace std;

/*
	Author : Blaz Pocrnja
	Lab #3 
	Purpose : This program simulates the game of Craps. The rules are as follows:
			
		  Two dice are rolled. If the sum is 7 or 11 on the first throw, the player wins. If the sum 				
		  is 2, 3 or 12 on the first throw, the player loses. If the sum is 4, 5, 6, 8, 9, or 10 on 				
		  the first throw, then the sum becomes the player's "point." To win, you must continue 				
		  rolling the dice until you "make the point." The player loses by rolling a 7 before making 				
		  the point.
*/

int die(void);
void playGame(void);

//calls the playGame function and asks user if they wish to continue
int main() {								
  char ans;								
  bool done = false;
  while ( ! done ) {
         playGame();   
         cout << "Play again (y/n) ? ";
         cin >> ans;
         if ( ans == 'y' || ans == 'Y') done = false;
             else done = true;
  }
  return 0;
}

//calls die function twice and sums the values. Continues to "roll" the dice until the player wins or loses
void playGame(void){
  int point;
  int die1 = die();
  int die2 = die();
  int sum = die1 + die2;
  cout << endl;
  if ((sum == 7)||(sum == 11)){
  	cout << "player rolled " << die1 << " + " << die2 <<" = " << sum << endl;
	cout <<"player wins"<< endl << endl;
  }
  else{
  	if((sum == 2)||(sum == 3)||(sum == 12)){
		cout << "player rolled " << die1 << " + " << die2 << " = " << sum << endl;
		cout <<"player loses"<<endl;
	}
	else{	
		point = sum;
		cout << "player rolled " << die1 << " + " << die2 << " = " << sum << endl;
		cout << "point is " << point << endl;
		sum = -1;
		while(sum != point){
			die1 = die();
  			die2 = die();
  			sum = die1 + die2;
			cout << "player rolled " << die1 << " + " << die2 <<" = " << sum << endl;
			if (sum == 7){
				cout << "player loses" << endl << endl;
				
				return;
			} 
		}
		cout << "player wins" << endl << endl;
	}
  }
  
  
}

int die(void){								//returns a random number between 1 and 6
  return rand() % 6+1;
} 






