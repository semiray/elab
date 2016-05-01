int Sensvalue=0;

int Senspin=A0;

void setup()
{
    Serial.begin(9600);
}

void loop()
{

    Sensvalue=analogRead(Senspin);

    Serial.println(Sensvalue);

    delay(1000);
}
