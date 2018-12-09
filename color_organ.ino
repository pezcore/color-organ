int analogPin=0;
int strobePin=2;
int resetPin=3;
int redPin = 9;
int bluePin= 10;
int greenPin = 11;
int spectrumValue[7];
int filter = 80;

void setup(){
    Serial.begin(9600);
    pinMode(analogPin, INPUT);
    pinMode(strobePin, OUTPUT);
    pinMode(resetPin, OUTPUT);
    pinMode(redPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    digitalWrite(resetPin,LOW);
    digitalWrite(strobePin, HIGH);
}

void loop(){
    digitalWrite(resetPin,HIGH);
    digitalWrite(resetPin,LOW);
    for(int i=0;i<7;i++){
        digitalWrite(strobePin,LOW);
        delay(30);
        spectrumValue[i] = analogRead(analogPin);
        spectrumValue[i] = constrain(spectrumValue[i], filter, 0x3ff);
        spectrumValue[i] = map(spectrumValue[i], filter, 0x3ff, 0, 0xff);
        Serial.print(spectrumValue[i]);
        Serial.print("     ");
        digitalWrite(strobePin,HIGH);
    }

    Serial.println();
    analogWrite(redPin,spectrumValue[0]);
    analogWrite(redPin,spectrumValue[1]);
    analogWrite(bluePin,spectrumValue[3]);
    analogWrite(bluePin,spectrumValue[4]);
    analogWrite(greenPin,spectrumValue[5]);
    analogWrite(greenPin,spectrumValue[6]);
}


