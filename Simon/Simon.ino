//These pins will trigger the lights (more lights = higher difficulty)
int pin[] = {2,3,5,7,9,11};
//This variable will control how fast the lights will blink during the sequence (decreases as lvls increase)
int blinkSpeed = 600;
//This variable will control how long the game will pause in between levels. MAY BE STRICTLY FOR TESTING PURPOSES. 
//Full game will halt until it receives and checks users input
int wait = 1000;
//Random value will be used to to trigger lights at random
int randNum;
//levels (start, max) will help dictate how long the light sequence gets and what lvl the player has reached
int startingLvl = 0;
int maxLvl = 6;
//Array to hold the pin numbers (dictates the light sequence the user will repeat) 
int lightSeq[5];
int testSeq[] = {1, 3, 1, 4, 1, 5};
//Boolean: Use to check if the user has entered the sequence correctly
bool correctInput = true;
//This variable will be used to set the difficulty
String difficulty;

void setup() {
  // put your setup code here, to run once:
  //set up pins and ready for OUTPUT
  for(int i = 0; i < 5; i++){
    pinMode(pin[i], OUTPUT);
  }
}

void loop() {
  //main code here,runs repeatedly:
  int currLvl = startingLvl;
  //initialize array with random numbers from 0-5. 
  //These numbers determine the sequence of lights that will be triggered
  //these numbers directly correspond to the lights
  for(int i = 0; i < (sizeof(lightSeq) / sizeof(lightSeq[0])); i++){
    randNum = random(0,6);
    lightSeq[i] = randNum; 
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
    }
    delay(wait);
      
    
  }
   
    

}
