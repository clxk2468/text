int datapin =2; //DS
int clockPin =3; //SHCP
int latchpin =4; //STCP

byte data = 0;

void setup() {                
  
  pinMode(datapin, OUTPUT); 
  pinMode(clockPin, OUTPUT);
  pinMode(latchpin, OUTPUT);  
   
  
}

void shiftWrite(int desiredPin, boolean desiredState)
{
  bitWrite(data, desiredPin,desiredState);				// data는 위에서 정의함, desiredPin은 0부터 ??까지, desiredState는 boolean으로 정의되어 0101010101만 가능(HIGH, LOW)
  shiftOut(datapin, clockPin, MSBFIRST ,data);				// datapin과 clockpin의 숫자가 0이면 1로바뀌고 1이면 0으로바뀌는 방향이 최하위부터 최상위로 바꿈 *MSBFIRST가 최하위부터 최상으로 바꾸는 역활
  digitalWrite(latchpin, HIGH); 
  digitalWrite(latchpin, LOW);
}


void loop() {
  for(int i=0; i<=3; i++)
  {
    shiftWrite(i, HIGH);
    delay(500);
  }
  for(int i=3; i>=0; i--)
  {
    shiftWrite(i, LOW);
    delay(500);
  }
