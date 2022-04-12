
int distLeft;
int distRight;

boolean checkRoad() {
  myservo.write(0);
  delay(1000); 
  distRight = distanceSensor.measureDistanceCm(); 
  delay(100);  
  myservo.write(168);
  delay(1000);
  distLeft = distanceSensor.measureDistanceCm(); 
  delay(100);
  myservo.write(80); 
  delay(1000);
  return selectWay(); 
}

boolean selectWay() {
  if (distLeft == -1) {
     return false;
  }
  if (distRight == -1) {
    return true;
  }
  if (distLeft > distRight){
    return false;
  } 
  if (distLeft < distRight){
    return true;
  } 
  if (distLeft == distRight) {
    return false;
  }
}
