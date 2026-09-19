#define TRIGGER_PIN 9
#define ECHO_PIN 8

#define SPEED 343 // Meters per second
#define K ( SPEED * 100.0f )/( 2.0f * 1000000.0f )


float dist = 0.0f;
float tof = 0.0f;


void setup(){
    Serial.begin(9600); //Baud-rate adjusted to 9600 symbols per second (Baud-rate relates symbols per second)
    
    //  Setup read and write pins
    pinMode(TRIGGER_PIN, OUTPUT);
    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);
    pinMode(ECHO_PIN, INPUT);
    delay(6000);
    Serial.println("Distance:");
}

void loop(){
    // Sends init input stream to start the sensor's reading
    digitalWrite(TRIGGER_PIN,HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN,LOW);

    tof = pulseIn(ECHO_PIN,HIGH); // reads in microseconds [us] (10E-6)
    dist = K*tof; // result in [cm]

    Serial.print(" == ");
    Serial.print(dist);
    Serial.print(" == \n");

    delay(1000);
}