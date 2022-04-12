
void runForward() {
  if (digitalRead(leftEngineForward) == 0) { 
    digitalWrite(leftEngineForward, HIGH);
    digitalWrite(rightEngineForward, HIGH);
    delay(50);
  }
}


void runBack() {
  if (digitalRead(leftEnginerBack) == 0) { 
    digitalWrite(leftEnginerBack, HIGH);
    digitalWrite(rightEngineBack, HIGH);
    delay(100);
  }
}

void runBack(int runTime) {
  runBack();
  delay(runTime);
  stopEngine();
}

void stopEngine() {
  digitalWrite(leftEnginerBack, LOW);
  digitalWrite(rightEngineBack, LOW);
  digitalWrite(leftEngineForward, LOW);
  digitalWrite(rightEngineForward, LOW);
}

void turnLeft() {
  digitalWrite(leftEnginerBack, HIGH);
  digitalWrite(rightEngineForward, HIGH);
  delay(700);
  digitalWrite(leftEnginerBack, LOW);
  digitalWrite(rightEngineForward, LOW);
}

void turnRight() {
  digitalWrite(rightEngineBack, HIGH);
  digitalWrite(leftEngineForward, HIGH);
  delay(700);
  digitalWrite(rightEngineBack, LOW);
  digitalWrite(leftEngineForward, LOW);
}
