#include <HCSR04.h>
#include <Servo.h>

int leftEngineForward = 6;
int leftEnginerBack = 7;

int rightEngineForward = 4;
int rightEngineBack = 5;

int state = 0;

UltraSonicDistanceSensor distanceSensor(9,8);

Servo myservo; 

void setup() {
  // put your setup code here, to run once:
  pinMode(leftEngineForward, OUTPUT);
  pinMode(leftEnginerBack, OUTPUT);

  pinMode(rightEngineForward, OUTPUT);
  pinMode(rightEngineBack, OUTPUT);

  myservo.attach(12);
  myservo.write(80);
  
  Serial.begin(9600);
  delay(2000);
}

void loop() {
//  state = 2;
  if (distanceSensor.measureDistanceCm() > 30.0 && state == 1) { 
    state = 0;
  }
  if (state == 0) { 
    runForward();
    if (distanceSensor.measureDistanceCm() <= 30.0) { 
       state = 1;
    }
  }
  if (state == 1) {
    stopEngine();
    delay(200);
    runBack(300); 
    state = 2;
  }
  if (state == 2) { 
     boolean turn = checkRoad();
     if (turn) state = 3;
     if (!turn) state = 4;
  }
  if (state == 3) {
    turnRight();
    state = 0;
  }
  if (state == 4) {
    turnLeft();
    state = 0;
  }
}
