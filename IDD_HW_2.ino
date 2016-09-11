/* Author: Caitlin Gruis
 *  Class: Interactive Device Design
 *  Assignment: HW #2
 *  Date: 9/11/16
 *  Description: The purpose of this code is to implement a Morse code text entry device using only momentary switches.
 */

#if defined(ARDUINO) 
SYSTEM_MODE(MANUAL); 
#endif

// the three pushbuttons are connected to D2, D3, and D4
const int button1 = D2;  // dot button   
const int button2 = D3; //dash button
const int button3 = D4; //submit button
int morseArray[4] = {0, 0, 0, 0}; // array with morse values from push buttons
int n = 0;
char returnChar;

// variables for reading the pushbutton status
int buttonState1 = 0;         
int buttonState2 = 0;
int buttonState3 = 0;

//previous state of buttons
int previousState1;
int previousState2;
int previousState3;


void setup() {
  Serial.begin(9600);
  // initialize the pushbutton pin as an inputs with the pull down resistors
  pinMode(button1, INPUT_PULLDOWN);
  pinMode(button2, INPUT_PULLDOWN);
  pinMode(button3, INPUT_PULLDOWN);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);
  buttonState3 = digitalRead(button3);

  if ((buttonState1 == HIGH) && (buttonState1 != previousState1)){
    morseArray[n] = 1;
    n++;
  }
  if ((buttonState2 == HIGH) && (buttonState2 != previousState2)){
    morseArray[n] = 2;
    n++;
  }
  if ((buttonState3 == HIGH) && (buttonState3 != previousState3)){
    returnChar = morseDecoder(morseArray);
    Serial.print(returnChar);
    n=0;
    morseArray[0] = 0;
    morseArray[1] = 0;
    morseArray[2] = 0;
    morseArray[3] = 0;
  }
  
  previousState1 = buttonState1;
  previousState2 = buttonState2;
  previousState3 = buttonState3;
  delay(100);
}

//function to decode morse array
char morseDecoder( int morse[]){
  char charToPrint;

  if (morse[0] == 0){
          charToPrint = ' ';
    
  }else if (morse[0] == 1){
      if (morse[1] == 0){
        if (morse[2] == 0){
          if (morse[3] == 0) {
          charToPrint = 'e';
        }else{}
        }
    }else if (morse[1] ==1){
        if (morse[2] == 0){
          if (morse[3] == 0) {
            charToPrint = 'i';
          }else{}
      }else if (morse[2] == 1){
        if (morse[3] == 0) {
          charToPrint = 's';
        }else if (morse[3] == 1){
          charToPrint = 'h';
        }else if (morse[3] == 2){
          charToPrint = 'v';
        }else{}
        
      }else if (morse[2] == 2){
        if (morse[3] == 0) {
          charToPrint = 'u';
        }else if (morse[3] == 1){
          charToPrint = 'f';
        }else if (morse[3] == 2){
          charToPrint == '.';
        }else{}
        
      }else{}
      
    }else if (morse[1] == 2){
        if (morse[2] == 0){
        if (morse[3] == 0) {
          charToPrint = 'a';
        }else{}
      }else if (morse[2] == 1){
        if (morse[3] == 0) {
          charToPrint = 'r';
        }else if (morse[3] == 1){
          charToPrint = 'l';
        }else if (morse[3] == 2){
          charToPrint = '!';
        }else{}
        
      }else if (morse[2] == 2){
        if (morse[3] == 0) {
          charToPrint = 'w';
        }else if (morse[3] == 1){
          charToPrint = 'p';
        }else if (morse[3] == 2){
          charToPrint = 'j';
        }else{}
        
      }else{}
      
    }else{}
    
  }else if (morse[0] == 2){
      if (morse[1] == 0){
      if (morse[2] == 0){
        if (morse[3] == 0) {
          charToPrint = 't';
        }
      }else{}
    }else if (morse[1] ==1){
        if (morse[2] == 0){
          if (morse[3] == 0) {
            charToPrint = 'n';
        }else{}
      }else if (morse[2] == 1){
        if (morse[3] == 0) {
          charToPrint = 'd';
        }else if (morse[3] == 1){
          charToPrint = 'b';
        }else if (morse[3] == 2){
          charToPrint = 'x';
        }else{}
        
      }else if (morse[2] == 2){
        if (morse[3] == 0) {
          charToPrint = 'k';
        }else if (morse[3] == 1){
          charToPrint = 'c';
        }else if (morse[3] == 2){
          charToPrint = 'y';
        }else{}
        
      }else{}
      
    }else if (morse[1] == 2){
        if (morse[2] == 0){
          if (morse[3] == 0) {
            charToPrint = 'm';
          }else{}
        }else if (morse[2] == 1){
          if (morse[3] == 0){
            charToPrint = 'g';
          }else if (morse[3] == 1){
           charToPrint = 'z'; 
          }else if (morse[3] == 2){
            charToPrint = 'q';
        }else{}
        
      }else if (morse[2] == 2){
        if (morse[3] == 0){
          charToPrint = 'o';
        } else if (morse[3] == 2){
          charToPrint = '?';
        }else{}
        
      }else{}
      
    }else{}
    
  }else{
  }
  
    return charToPrint;
}

