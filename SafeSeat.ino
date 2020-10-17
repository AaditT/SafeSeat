int pressurePin = A0;
int force;
int tempPin = A5;
int redpin = 11; // select the pin for the red LED
int redpin2 = 12; // select the pin for the blue LED
int speakerPin = 8;
int buttonPin = 3;
bool on;
int val;
int timer;
int x;
int i;


double Thermister(int RawADC) {
	double Temp;
	Temp = log(((10240000/RawADC) - 10000));
	Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
	Temp = Temp - 273.15; // Convert Kelvin to Celcius
        Temp = (Temp*(9/5))+32;
	return Temp;
}

void setup () {
  pinMode (buttonPin, INPUT);
  pinMode (redpin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
  Serial.begin (9600);
}

void time(int x){
  for (i=0; i<x; i++){
   delay(1000);
  }
} 
int readTemp(){
   int temperature = Thermister(analogRead(tempPin));
   return temperature;
}
int readForce(){
  int force = analogRead(pressurePin);
  return force;
}
void loop(){
   val = digitalRead(buttonPin);
   switch(val) {
     case 1:
       while (digitalRead(buttonPin)==HIGH){
         analogWrite(11, 255);
         analogWrite(8, 255);
         analogWrite(12, 255);
         delay(100);
         analogWrite(11, 0);
         analogWrite(8, 0);
         analogWrite(12, 255);
         delay(100);
         val = digitalRead(buttonPin);
         readTemp(); // display tempature
         readForce();
      }
      break;
    case 0:
       // de-activate child lock
       delay(3000);
       if ((digitalRead(buttonPin)==0)){
        analogWrite(11,0);
        analogWrite(8,0);
        analogWrite(12,0);
        while(2222 == 2222){delay(1);}
       }
       readTemp(); // display tempature
       readForce();   
   }
   readTemp();
   readForce();  
}
