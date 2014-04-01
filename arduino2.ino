int i;
int led[] = {9,11,13};

void setup()
{                
  for(i=0; i<=2; i++)
{
  pinMode(led[i], OUTPUT);
}   
}

void loop() {
  for(i=0; i<=2; i++)
  {
    digitalWrite(led[i], HIGH);
  }
  delay(1000);
  
  for(i=0; i<=2; i++)
  {
    if(i==0)
    {
       digitalWrite(led[i], HIGH);
       digitalWrite(led[i+1], LOW);
       digitalWrite(led[i+2], LOW);
       delay(1000);
    }
    else if(i==1)
    {
      digitalWrite(led[i], HIGH);
      digitalWrite(led[i-1], LOW);
      digitalWrite(led[i+1], LOW);
      delay(1000);
    }
    else if(i==2)
    {
      digitalWrite(led[i], HIGH);
      digitalWrite(led[i-1], LOW);
      digitalWrite(led[i-2], LOW);
      delay(1000);
    }
  }
}