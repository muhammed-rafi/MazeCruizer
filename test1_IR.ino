// Define the IR sensor pins
const int irSensor1 = 5;// Motor control pins
const int in1 = 6;
const int in2 = 7;
const int in3 = 8;
const int in4 = 9;
const int ena = 5; // PWM pin for Motor 1
const int enb = 10; // PWM pin for Motor 2

// Encoder pins
const int encoder1A = 2; // Motor 1 Encoder A (Interrupt)
const int encoder1B = 3; // Motor 1 Encoder B
const int encoder2A = 12; // Motor 2 Encoder A
const int encoder2B = 13; // Motor 2 Encoder B

// Encoder counts
volatile long encoder1Count = 0;
volatile long encoder2Count = 0;

// ISR for encoder 1
void encoder1ISR() {
  if (digitalRead(encoder1A) == digitalRead(encoder1B)) {
    encoder1Count++;
  } else {
    encoder1Count--;
  }
}

// ISR for encoder 2
void encoder2ISR() {
  if (digitalRead(encoder2A) == digitalRead(encoder2B)) {
    encoder2Count++;
  } else {
    encoder2Count--;
  }
}

void setup() {
  // Set motor control pins as outputs
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);

  // Set encoder pins as inputs
  pinMode(encoder1A, INPUT);
  pinMode(encoder1B, INPUT);
  pinMode(encoder2A, INPUT);
  pinMode(encoder2B, INPUT);

  // Attach interrupts for encoders
  attachInterrupt(digitalPinToInterrupt(encoder1A), encoder1ISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoder2A), encoder2ISR, CHANGE);

  // Initialize Serial Monitor
  Serial.begin(9600);
}

void loop() {
  // Set motor 1 forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(ena, 150); // Speed control (0-255)

  // Set motor 2 forward
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enb, 150); // Speed control (0-255)

  // Print encoder counts
  Serial.print("Motor 1 Encoder Count: ");
  Serial.print(encoder1Count);
  Serial.print("\t");

  Serial.print("Motor 2 Encoder Count: ");
  Serial.println(encoder2Count);

  // Delay to observe changes in the Serial Monitor
  delay(1000);

  // Change direction after some time
  if (millis() > 5000) {
    // Reverse motor 1
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);

    // Reverse motor 2
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
}

const int irSensor2 = 6;
const int irSensor3 = 9;

void setup() {
  // Initialize the serial monitor
  Serial.begin(9600);

  // Set IR sensor pins as input
  pinMode(irSensor1, INPUT);
  pinMode(irSensor2, INPUT);
  pinMode(irSensor3, INPUT);
}

void loop() {
  // Read the values from the IR sensors
  int value1 = digitalRead(irSensor1);
  int value2 = digitalRead(irSensor2);
  int value3 = digitalRead(irSensor3);

  // Display the values on the serial monitor
  Serial.print("IR RIGHT: ");
  Serial.print(value1);
  Serial.print("\t");
  Serial.print("Hello im under the water");
//
//  Serial.print("IR LEFT: ");
//  Serial.print(value2);
//  Serial.print("\t");
//
//  Serial.print("IR FRONT: ");
//  Serial.println(value3);

  // Delay for stability
  delay(500);
}
