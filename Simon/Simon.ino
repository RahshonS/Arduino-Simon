//These pins will trigger the lights (more lights = higher difficulty)
int pin[] = {2,3,5,7,9,11};
//This variable will control how fast the lights will blink during the sequence (decreases as lvls increase)
int startingSpeed = 900;
int blinkSpeed;
int maxSpeed = 10;
//This variable will control how long the game will pause in between levels. MAY BE STRICTLY FOR TESTING PURPOSES. 
//Full game will halt until it receives and checks users input
int wait = 1000;
//Random value will be used to to trigger lights at random
int randNum;
//levels (start, max) will help dictate how long the light sequence gets and what lvl the player has reached
//NOTE: Max level should be one more than the length of the light sequence
int startingLvl = 0;
int maxLvl = 11;
//Array to hold the pin numbers (dictates the light sequence the user will repeat
//LIGHT SEQ SHOULD BE ONE LESS THAN THE MAX LEVEL
int lightSeq[10];
int testSeq[] = {0, 1, 0, 2, 0, 3, 0, 3, 0, 5};
//Boolean: Use to check if the user has entered the sequence correctly
bool correctInput = true;
//These variable will be used to set the difficulty
int easy = 1;
int classic = 2;
int hard = 3;
int extreme = 4;
//This array will hold the difficulties. Difficulty will be select by the player
int diffMode[4] = {easy, classic, hard, extreme};


//Button Setup 
int readPin = 12;     //designated read pin for the time being 
int valRead;


void setup() {
  // put your setup code here, to run once:
  //set up pins and ready for OUTPUT
  for(int i = 0; i < 5; i++){
    pinMode(pin[i], OUTPUT);
  }

  //Setup for the button(s) 
  pinMode(readPin, INPUT);
}

void loop() {
  /*
  //main code here,runs repeatedly:
  int currLvl = startingLvl;
  blinkSpeed = startingSpeed;
  int diffMode = extreme;
  
  //initialize array with random numbers (dependent upon the level). 
  //These numbers determine the sequence of lights that will be triggered
  //these random numbers directly correspond to the lights
  if(diffMode == easy){
    for(int i = 0; i < (sizeof(lightSeq) / sizeof(lightSeq[0])); i++){
      randNum = random(0,3);
      lightSeq[i] = randNum; 
    }
  }
  else if(diffMode == classic){
    for(int i = 0; i < (sizeof(lightSeq) / sizeof(lightSeq[0])); i++){
      randNum = random(0,4);
      lightSeq[i] = randNum; 
    }
  }
  else if(diffMode == hard){
    for(int i = 0; i < (sizeof(lightSeq) / sizeof(lightSeq[0])); i++){
      randNum = random(0,5);
      lightSeq[i] = randNum; 
    }
  }
  else if(diffMode == extreme){
    for(int i = 0; i < (sizeof(lightSeq) / sizeof(lightSeq[0])); i++){
      randNum = random(0,6);
      lightSeq[i] = randNum; 
    }
  }

  
  //while players current level < max level
  //increment currLvl to start the game at level 1
  currLvl++; 
  //while we haven't reached the last level in the game
  for(; currLvl < maxLvl; currLvl++){
    //iterate through the lightSeq array containing the sequence 
    for(int j = 0; j < currLvl; j++){
      //trigger the corresponding lights up to the number of lights applicable for the level
      //1 additional light is added at each level
      digitalWrite(pin[lightSeq[j]], HIGH);
      delay(blinkSpeed);
      digitalWrite(pin[lightSeq[j]], LOW);
      blinkSpeed -= 5;
    }
    delay(wait);
    */

    //BUTTON CODE
    valRead = digitalRead(readPin);
    //Case: circuit is open, no current flow, 1 is returned by digital read
    if(valRead == 1){ 
      //basically awaiting output
      digitalWrite(pin[3], LOW);
    }
    //Case: cicuit is short (closed), current is flowing, 0 is returned by digital read
    else if(valRead == 0){
      //if the player is pressing, then input needs to be read and stored
      //lights need to be triggered each time a button is pressed
      digitalWrite(pin[3], HIGH);
    }
    
      
    
  }
   
