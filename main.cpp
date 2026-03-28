// IoT Smart Bin: Ultrasonic Level Sensing Logic
// Calculates distance to trigger 'Full' notification

void loop() {
  // 1. Trigger the Ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // 2. Measure the time for the echo
  duration = pulseIn(echoPin, HIGH);
  
  // 3. Calculate Distance in cm
  distance = duration * 0.034 / 2;

  // 4. Logic: If trash is closer than 5cm, it's FULL
  if (distance < 5) {
    sendNotification("Warning: Trash Bin is 100% Full!");
    Serial.println("Bin Capacity Reached.");
  }
  
  delay(2000); // Check every 2 seconds
}
