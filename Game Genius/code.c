/*
 - Documentation
 - Arduino GENIUS
 - @author Amir Brito
 - Circuit Information:
 	- Cables:
    	- Blue: Digital Inputs;
        - Purple: Digital Outputs;
        - Red: Supply 5V;
        - Black: GND;
    - Components:
    	- (04) Leds; 
        - (04) Resistors 500 Ohms; // Leds - Current protection; 
        - (04) Resistors 10K Ohms; // Buttons - Pulldown current to ground;
        - (01) Buzzer;
        - (04) Buttons;
        - (01) Protoboard;
        - (01) Arduino model Uno R3;
*/

// Global variables



const int arrayLength = 32;
const int arrayLengthComponents = 4;

int arraySequence[arrayLength] = {};
int arrayButtons[arrayLengthComponents] = {2,3,4,5};
int arrayLeds[arrayLengthComponents] = {8,9,10,11};
int arraySounds[arrayLengthComponents] = {262,294,330,349};

int roundGame = 0;
int roundPlayer = 0; // Compare the player's round with the round Game;
int buttonStatus = 0;
bool gameOver = false; // Player game's status



// Functions;

void nextRound(){ // Sorting the next round
  
  	if(roundGame < arrayLength){ // Array size;
  		int draw = random(arrayLengthComponents); // Sorting 1-4 Leds;
  		arraySequence[roundGame] = draw;
  		roundGame++; 
    }
}

void startSequence(){ //starting the sequence and turning ON/OFF sounds and leds;
	  
  	for(int iCount = 0; iCount < roundGame; iCount++){
  		tone(12, arraySounds[arraySequence[iCount]]); // SoundOn;
      	delay(250);
      	noTone(12); // SoundOff;
    	digitalWrite(arrayLeds[arraySequence[iCount]], HIGH); // LedOn;
    	delay(300);    	
    	digitalWrite(arrayLeds[arraySequence[iCount]], LOW); // LedOff;
	delay(100);
  	}
}

void standByPlayer(){ 
  	
  	for(int iCount = 0; iCount < roundGame; iCount++){
      	bool movePlayer = false;
      	while(!movePlayer){
          	for(int jCount = 0; jCount < arrayLengthComponents; jCount++){
              	if(digitalRead(arrayButtons[jCount]) == HIGH){
                	buttonStatus = jCount;
                  	tone(12, arraySounds[jCount]);
                  	delay(250);
                  	noTone(12);
                  	digitalWrite(arrayLeds[jCount], HIGH);
                  	delay(250);
                  	digitalWrite(arrayLeds[jCount], LOW);                  	
                  	movePlayer = true;
                }
          	}
        }
      	// checking the player's move;
      	if(arraySequence[roundPlayer] != buttonStatus){
      		// Show error to the player;
        	for(int kCount = 0; kCount < 4; kCount++){
            	tone(12, 70);
              	digitalWrite(arrayLeds[kCount], HIGH);
              	delay(100);
              	digitalWrite(arrayLeds[kCount], LOW);
              	noTone(12);
        	}
          	gameOver = true;
          	delay(5000);
          	break;
      	}
      	roundPlayer++;
    }
  	roundPlayer = 0;
}	


void resetGame(){ // If the game is over, reset all variables to start a new game;
  	if(gameOver == true){      
  		arraySequence[arrayLength] = {};
      	roundGame = 0;
      	roundPlayer = 0;
      	gameOver = false;
    }
}

void arrayFull(){ // Checking if the game reach the limite to reset a new game;
  	if(roundGame == arrayLength){
    	arraySequence[arrayLength] = {};
      	roundGame = 0;
      	roundPlayer = 0;
    }
}

// Inputs and Outputs;

void setup()
{
  // Leds
  	pinMode(8, INPUT);
  	pinMode(9, INPUT);
  	pinMode(10, INPUT);
  	pinMode(11, INPUT);
  
  // Buzzer
  	pinMode(12, OUTPUT);
  
  // Buttons  	
  	pinMode(2, OUTPUT);
  	pinMode(3, OUTPUT);
  	pinMode(4, OUTPUT);
  	pinMode(5, OUTPUT);
  
}

// Main function;

void loop()
{
  	nextRound(); // Sorting;
  	startSequence(); // Reproduce the sequence;
  	standByPlayer(); // Interacting with player;
  	resetGame();	 // Checking conditions to reset the game;
  	arrayFull();	 // Checking if array reach the limit;
  	delay(500);
  
}

 
