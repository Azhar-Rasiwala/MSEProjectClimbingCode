const int frontMotorA = 15;
const int frontMotorB = 23;
const int push = 27; //PB1
const int interval = 1000;
unsigned long intervalStartTime;
unsigned long currentTime;
boolean motorRun = false;
double dForwardSpeed;

void setup() {
  ledcAttachPin(frontMotorA, 5);
  ledcAttachPin(frontMotorB, 6);
  ledcSetup(5, 300, 8);       // only value found to work for now. Can be changed from 300
  ledcSetup(6, 300, 8);

  dForwardSpeed = 250;        //250 is max speed (determined through testing
  pinMode(push, INPUT_PULLUP);
}

void loop()
{
  currentTime = millis();

  if (digitalRead(push) == true) {//PB1 is pressed
    startMotion(); //spool starts spinning
    intervalStartTime = currentTime;
  }

  if (currentTime - intervalStartTime >= interval) {
    stopMotion(); //stop spinning spool
  }

}

void startMotion() {
  ledcWrite(1, dForwardSpeed);
  ledcWrite(2, 0);
  motorRun = true;
}
void stopMotion() {
  ledcWrite(5, 0);
  ledcWrite(6, 0);
  motorRun = false;
}
