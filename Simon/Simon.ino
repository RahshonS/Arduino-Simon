//These pins will trigger the lights (more lights = higher difficulty)
int pin[] = {2,3,5,7,9,11};
//This variable (pause) will control how fast the lights will blink (decreases as lvls increase)
int pause = 200;
//Random value will be used to to trigger lights at random
int randNum;
//levels (start, max) will help dictate how long the light sequence gets and what lvl the player has reached
int startLvl = 0;
int maxLvl = 5;
//Array to hold the pin numbers (dictates the light sequence the user will repeat) 
int lightSeq[5];
//Boolean: Use to check if the user has entered the sequence correctly
bool correctInput = true;

void setup() {
  // put your setup code here, to run once:
  //set up pins and ready for OUTPUT
  for(int i = 0; i < 5; i++){
    pinMode(pin[i], OUTPUT);
  }
}

void loop() {
  //main code here,runs repeatedly:
  int currLvl = startLvl;
  //initialize array with random numbers
  for(int i = 0; i < (sizeof(lightSeq) / sizeof(lightSeq[0])); i++){
    randNum = random(0,6);
    lightSeq[i] = randNum; 
  }
  
  //while players current level < max level
  currLvl++; 
  for(; currLvl < maxLvl; currLvl++){
    //iterate through the array (according to the current level)
    for(int j = 0; j < currLvl; j++){
      //trigger the corresponding lights
      digitalWrite(pin[lightSeq[j]], HIGH);
    }
      
    
  }
   
    

    //wait

}
