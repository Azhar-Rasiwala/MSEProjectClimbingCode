//testing

const int frontMotorA = 15;
const int frontMotorB = 23;
const int push = 27;
const int interval = 15000;
unsigned long intervalStartTime;
unsigned long currentTime;
boolean motorRun = false;
double dForwardSpeed;
int iButtonState;
int iLastButtonState = HIGH;

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

  int iButtonValue = digitalRead(push);
  if (iButtonValue != iLastButtonState) {
    startMotion();
    intervalStartTime = currentTime;
  }
}

void startMotion() {
  ledcWrite(5, dForwardSpeed);
  ledcWrite(6, 0);
  motorRun = true;
}
void stopMotion() {
  ledcWrite(5, 0);
  ledcWrite(6, 0);
  motorRun = false;
}
