#define ENA 5    // Enable/speed motors Right    GPIO5 (D1)
#define IN_1 0   // L298N in1 motors Right       GPIO0 (D3)
#define IN_2 2   // L298N in2 motors Right       GPIO2 (D4)
#define IN_3 12  // L298N in3 motors Left        GPIO12 (D6)
#define IN_4 13  // L298N in4 motors Left        GPIO13 (D7)
#define ENB 4    // Enable/speed motors Left     GPIO4 (D2)

int speedCar = 140;  // 0 to 255
int speed_0 = 0;
int sensor_L, sensor_R;    //optical sensor values
int pin_L = 16 , pin_R = 14;  //Pin sensor values 
// L = GPI16 (D0) R = GPI14 (D5)
String tmp;

void setup() {
  Serial.begin(115200);
  pinMode(ENA, OUTPUT);
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(pin_L, INPUT);
  pinMode(pin_R, INPUT);
}

void loop() {

  sensor_L = digitalRead(pin_L);
  sensor_R = digitalRead(pin_R);

  // 1 = detected 0 = non
  if ((sensor_L == 0) && (sensor_R == 0)) {
    goForword();
    delay(1);
  } else if ((sensor_L == 1) && (sensor_R == 0)) {
    goLeft();
    delay(10);
  } else if ((sensor_L == 0) && (sensor_R == 1)) {
    goRight();
    delay(10);
  } else if ((sensor_L == 1) && (sensor_R == 1)) {
    stopRobot();
    delay(1000);
  }

  tmp = "L=" + String(sensor_L) + " R=" + String(sensor_R);
  Serial.println(tmp);
}

void goForword() {

  digitalWrite(IN_1, 1);
  digitalWrite(IN_2, 0);
  analogWrite(ENA, speedCar);

  digitalWrite(IN_3, 0);
  digitalWrite(IN_4, 1);
  analogWrite(ENB, speedCar);
}

void goBack() {

  digitalWrite(IN_1, 0);
  digitalWrite(IN_2, 1);
  analogWrite(ENA, speedCar);

  digitalWrite(IN_3, 1);
  digitalWrite(IN_4, 0);
  analogWrite(ENB, speedCar);
}

void goRight() {

  digitalWrite(IN_1, 0);
  digitalWrite(IN_2, 1);
  analogWrite(ENA, speedCar);

  digitalWrite(IN_3, 0);
  digitalWrite(IN_4, 1);
  analogWrite(ENB, speedCar);
}

void goLeft() {

  digitalWrite(IN_1, 1);
  digitalWrite(IN_2, 0);
  analogWrite(ENA, speedCar);

  digitalWrite(IN_3, 1);
  digitalWrite(IN_4, 0);
  analogWrite(ENB, speedCar);
}

void stopRobot() {

  digitalWrite(IN_1, 0);
  digitalWrite(IN_2, 0);
  analogWrite(ENA, speedCar);

  digitalWrite(IN_3, 0);
  digitalWrite(IN_4, 0);
  analogWrite(ENB, speedCar);
}