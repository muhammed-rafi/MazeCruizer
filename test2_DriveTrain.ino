// Motor control pins for L298N
const int in1 = 6;
const int in2 = 7;
const int in3 = 8;
const int in4 = 9;
const int ena = 5;  // PWM pin for Motor 1 speed
const int enb = 10; // PWM pin for Motor 2 speed

void setup() {
  // Set motor control pins as outputs
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);

  // Initialize motors at a low speed
  analogWrite(ena, 150); // Set initial speed for Motor 1 (0-255)
  analogWrite(enb, 150); // Set initial speed for Motor 2 (0-255)
  
  // Set initial direction for both motors
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  // Motor 1 forward
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);  // Motor 2 forward
}

void loop() {
  // Run the motors forward for 3 seconds
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  // Motor 1 forward
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);  // Motor 2 forward
  
  delay(3000);  // Run motors for 3 seconds

  // Stop the motors for 1 second
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  // Stop Motor 1
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);  // Stop Motor 2
  
  delay(1000);  // Stop for 1 second

  // Reverse the motors for 3 seconds
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  // Motor 1 reverse
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);  // Motor 2 reverse
  
  delay(3000);  // Run motors in reverse for 3 seconds

  // Stop the motors for 1 second
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  // Stop Motor 1
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);  // Stop Motor 2
  
  delay(1000);  // Stop for 1 second
}
