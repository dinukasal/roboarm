#include <Servo.h>                           // include server library
Servo gripper_handle, gripper, elbow, wrist; // create servo object to control a servo
int poser = 0;                               // initial position of servo
int gripper_pose = 0;
int girpper_handle_pose = 0;
int elbow_pose = 0;
int wrist_pose = 0;

int step_count = 20;

int val; // initial value of input

void setup()
{
  Serial.begin(115200);     // Serial comm begin at 115200bpsd
  gripper_handle.attach(9); // server is connected at pin 9
  gripper.attach(10);
  elbow.attach(11);
  wrist.attach(6);
}

void loop()
{
  if (Serial.available()) // if serial value is available
  {
    val = Serial.read(); // then read the serial value
    if (val == 'w')      //if value input is equals to d
    {
      if (gripper_pose < 90)
        gripper_pose += step_count/2;

      gripper.write(gripper_pose);
      delay(15); //delay for the servo to get to the position
    }
    else if (val == 's') //if value input is equals to a
    {
      if (gripper_pose > 0)
        gripper_pose -= step_count/2; //than position of servo motor decreases by 1 (clockwise)

      gripper.write(gripper_pose);
      delay(15); //delay for the servo to get to the position
    }
    else
    {
      //Serial.println("give correct command a,b");
    }
    Serial.println(poser);
  }
  else if (val == 'q')
  {
    if (girpper_handle_pose < 180)
      girpper_handle_pose += step_count;

    gripper_handle.write(girpper_handle_pose); // the servo will move according to position
    delay(15);                                 //delay for the servo to get to the position
  }
  else if (val == 'a')
  {
    if (girpper_handle_pose > 0)
      girpper_handle_pose -= step_count;

    gripper_handle.write(girpper_handle_pose); // the servo will move according to position
    delay(15);                                 //delay for the servo to get to the position
  }
  else if (val == 'e')
  {
    if (elbow_pose < 180)
      elbow_pose += step_count;

    elbow.write(elbow_pose);
    delay(15);
  }
  else if (val == 'd')
  {
    if (elbow_pose > 0)
      elbow_pose -= step_count;

    elbow.write(elbow_pose);
    delay(15);
  }
  else if (val == 'r')
  {
    if (wrist_pose < 180)
      wrist_pose += step_count;

    wrist.write(wrist_pose);
    delay(15);
  }
  else if (val == 'f')
  {
    if (wrist_pose > 0)
      wrist_pose -= step_count;

    wrist.write(wrist_pose);
    delay(15);
  }
}
