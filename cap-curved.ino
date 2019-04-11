int start=millis();
double volt=0.0;

double top = 2.65; //set this unreasonably high while gnd of cap is unplugged to see what it maxes at

int i=1;
int n;

void setup() {

  // open serial connection
    Serial.begin(9600);
    pinMode(A0, OUTPUT);
    pinMode(5, OUTPUT);


    //discharge
    Serial.println("Discharging before any measurements.");
    digitalWrite(5,false);
    volt=0.0048828125*analogRead(A0);
    while(volt>.1)
    {
      Serial.print("Discharging: ");
      Serial.print(100*volt/top);
      Serial.println("%");
      volt=0.0048828125*analogRead(A0);
    }
}

void loop() {
    //charge and record
    digitalWrite(5,true);
    Serial.println("Begining cap charge.");
    volt=0.0048828125*analogRead(A0);
    start=millis();
    while(volt<top-.05)
    {
      volt=0.0048828125*analogRead(A0);
      Serial.print(millis());
      Serial.print(",");
      Serial.println(volt);
    }


    //discharge before rerun
    digitalWrite(5,false);
    volt=0.0048828125*analogRead(A0);
    while(volt>.05)
    {
      volt=0.0048828125*analogRead(A0);
      Serial.print("Discharging: ");
      Serial.print(100*volt/top);
      Serial.println("%");
    }
    delay(5000);
}
