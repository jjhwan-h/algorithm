#define C4 262 //도(4옥타브)
#define C4s 277 //도#
#define D4 294 //레
#define D4s 311 //레#
#define E4 330
#define F4 349
#define F4s 370
#define G4 392
#define G4s 415
#define A4 440
#define A4s 466
#define B4 494
#define C5 523 //도(5옥타브)

int pin_Passive = 10;

int LED_C4 = 11;
int LED_D4 = 12;
int LED_E4 = 13;
int LED_F4 = 9;

int melody[] = {C4,D4,E4,C4,E4,C4,E4,D4,E4,F4,F4,E4,D4,F4,0};  //음높이
double duration_s[] = {1.5,0.5,1.5,0.5,1,1,2,1.5,0.5,0.5,0.5,0.5,0.5,2.5,1.5}; //음길이
int LED_s[] = {LED_C4,LED_D4,LED_E4,LED_F4};   //LED

void setup(){
  pinMode(pin_Passive, OUTPUT);
  pinMode(LED_C4,OUTPUT);
  pinMode(LED_D4,OUTPUT);
  pinMode(LED_E4,OUTPUT);
  pinMode(LED_F4,OUTPUT);
}
void loop(){
  for(int sounds=0;sounds<15;sounds++){
   		int led;
       double Duration = 200*duration_s[sounds]; 
       int tmp = melody[sounds];
      if(melody[sounds]!=0){
          tone(pin_Passive,tmp);
        if(tmp == C4){
         	led = LED_s[0];
        	digitalWrite(led,HIGH);
        }	
        else if(melody[sounds] == D4){
          	led = LED_s[1];
        	digitalWrite(led, HIGH);
        }
        else if(melody[sounds] == E4){
          	led = LED_s[2];
        	digitalWrite(led, HIGH);
        }
        else if(melody[sounds] == F4){
          	led = LED_s[3];
        	digitalWrite(led, HIGH);
        }       	
     }
      delay(Duration);
      digitalWrite(led,LOW);
      float pauseSound = Duration * 1.3; //1.3을 곱한 임의의숫자만큼 쉰다.
      noTone(pin_Passive);
      delay(pauseSound);
  }
}