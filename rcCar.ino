
#define motor1IN1 04
#define motor1IN2 05
#define motor2IN1 06
#define motor2IN2 07


#include<SoftwareSerial.h>
SoftwareSerial BT(10, 11);
char c;
int sspeed;


void setup() {
  Serial.begin(9600);
  BT.begin(9600);
}

void loop() {
  while (BT.available())
  {
    delay(10);
    c = BT.read();

    Serial.println(c);
    switch (c)
    {
      case 'F':
        forward();
        break;
      case 'B':
        backward();
        break;
      case 'L':
        right();
        break;
      case 'R':
        left();
        break;

      case 'G':
        hardleft();
        break;
      case 'I':
        hardright();
        break;
      case 'J':
        backright();
        break;
      case 'H':
        backleft();
        break;
      case 'S':
        brake();
        break;
    }
  }
}
void brake()
{

  digitalWrite(motor1IN1, LOW);
  digitalWrite(motor1IN2, LOW);

  digitalWrite(motor2IN1, LOW);
  digitalWrite(motor2IN2, LOW);

  BT.println("/n Brake");

}

void backward()
{

  digitalWrite(motor1IN1, LOW);
  digitalWrite(motor1IN2, HIGH);

  digitalWrite(motor2IN1, LOW);
  digitalWrite(motor2IN2, HIGH);

  BT.println("/n backward");
}


void forward()
{

  digitalWrite(motor1IN1, HIGH);
  digitalWrite(motor1IN2, LOW);

  digitalWrite(motor2IN1, HIGH);
  digitalWrite(motor2IN2, LOW);

  BT.println("/n forward");
}




void right()//forward right
{

  digitalWrite(motor1IN1, HIGH);
  digitalWrite(motor1IN2, LOW);

  digitalWrite(motor2IN1, LOW);
  digitalWrite(motor2IN2, HIGH);

  BT.println("/n hardright");
}





void left()//forward left
{
  digitalWrite(motor1IN1, LOW);
  digitalWrite(motor1IN2, HIGH);

  digitalWrite(motor2IN1, HIGH);
  digitalWrite(motor2IN2, LOW);

  BT.println("/n hardleft");

}


void hardleft()
{
  digitalWrite(motor1IN1, LOW);
  digitalWrite(motor1IN2, LOW);

  digitalWrite(motor2IN1, HIGH);
  digitalWrite(motor2IN2, LOW);

  BT.println("/n left");
}


void hardright()
{
  digitalWrite(motor1IN1, HIGH);
  digitalWrite(motor1IN2, LOW);

  digitalWrite(motor2IN1, LOW);
  digitalWrite(motor2IN2, LOW);

}


void backright()
{

  digitalWrite(motor1IN1, 0);
  digitalWrite(motor1IN2, 1);

  digitalWrite(motor2IN1, 0);
  digitalWrite(motor2IN2, 0);

}


void backleft()
{

  digitalWrite(motor1IN1, LOW);
  digitalWrite(motor1IN2, LOW);

  digitalWrite(motor2IN1, 0);
  digitalWrite(motor2IN2, 1);

}


