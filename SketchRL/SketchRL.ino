
#define POWER_RATIO 230

int power_ratio_mode = 230;
const int ledPin =  9;// the number of the LED pin
const int ledPin2 =  10;// the number of the LED pin

// Variables will change:
int ledState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 1000; // interval at which to blink (milliseconds)

int mode = 0; // C'est plus évolutif qu'un booléan

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(10);

  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);

}


void loop() {
  if (Serial.available()) { // Il y a un caractère dans le buffer de reception
    String msg = Serial.readString();
    if (msg == "blink") {
      mode = 1;
      Serial.println("Blink mode");
    } else if (msg == "off") {
      Serial.println("Blink off");
      mode = 0;
    } else if(msg = "blinkM"){
      mode = 1;
      power_ratio_mode = 240;
    }else if(msg = "blinkm"){
      mode = 1;
      power_ratio_mode = 210;
    }else if(msg = "blinkp"){
      mode = 1;
      power_ratio_mode = 200;
    }
  }

  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval && mode == 1) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
      analogWrite(ledPin, power_ratio_mode);
      analogWrite(ledPin2, power_ratio_mode);
    } else {
      ledState = LOW;
      analogWrite(ledPin, 0);
      analogWrite(ledPin2, 0);
    }
  } else if (mode == 0) {
    analogWrite(ledPin, 0);
    analogWrite(ledPin2, 0);
  }

  // set the LED with the ledState of the variable:


}
