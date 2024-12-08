#define trigPin 9   // Trig pin connected to pin 9
#define echoPin 10  // Echo pin connected to pin 10
#define soundSpeed 0.0344  // Speed of sound in cm/us (at 20°C)

long duration; // Time for the pulse to return
int distance;  // Calculated distance

void setup() {
  Serial.begin(9600); // Start serial communication
  pinMode(trigPin, OUTPUT); // Set the trigPin as an output
  pinMode(echoPin, INPUT);  // Set the echoPin as an input
}

void loop() {
  // Send a pulse to the Trig Pin
  digitalWrite(trigPin, LOW); // Ensure the trigPin is low initially
  delayMicroseconds(2);       // Small delay to ensure clean signal
  digitalWrite(trigPin, HIGH); // Send a HIGH signal
  delayMicroseconds(10);      // Keep HIGH for 10 microseconds
  digitalWrite(trigPin, LOW); // End the HIGH signal

  // Measure the duration of the pulse on the Echo Pin
  duration = pulseIn(echoPin, HIGH); // Measure the time the Echo Pin stays HIGH

  // Calculate distance (in cm)
  distance = duration * soundSpeed / 2; // Divide by 2 for round trip
  
  // Output the distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500); // Wait 0.5 seconds before the next reading
}
