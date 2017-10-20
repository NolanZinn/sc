#include <SoftwareSerial.h>  

int bluetoothTx = 9;  // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 10;  // RX-I pin of bluetooth mate, Arduino D3
  float chargeLast;
  float chargeNow;
  float chargeEnd;
  int outpin = 11;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup() {
  pinMode(outpin,OUTPUT);
  
  Serial.begin(9600);  // Begin the serial monitor at 9600bps

  bluetooth.begin(115200);  // The Bluetooth Mate defaults to 115200bps
  bluetooth.print("$");  // Print three times individually
  bluetooth.print("$");
  bluetooth.print("$");  // Enter command mode
  delay(100);  // Short delay, wait for the Mate to send back CMD
  bluetooth.println("U,9600,N");  // Temporarily Change the baudrate to 9600, no parity
  // 115200 can be too fast at times for NewSoftSerial to relay the data reliably
  bluetooth.begin(9600);  // Start bluetooth serial at 9600

}

void loop() {


  String val;
  char c;
  char tab2[14];
  int pointer;

while(bluetooth.available())  // If the bluetooth sent any characters
  {
    // Send any characters the bluetooth prints to the serial monitor
    delay(10);
    c = (char)bluetooth.read();
    val += c;
  }
  
    if(val.length() > 0)
    {
        Serial.println(val);
        
        
        strncpy(tab2, val.c_str(), sizeof(tab2));
        tab2[sizeof(tab2) - 1] = 0;
        
        val="";
    
          for(int i;i<12;i++)
          {
            Serial.println(tab2[i]);
          }          
    }
  
  int one = (int) tab2[0] - 48;
  int two = (int) tab2[1] - 48;
  int three = (int) tab2[2] - 48;
  int four = (int) tab2[3] - 48;
  int five = (int) tab2[4] - 48;
  int six = (int) tab2[5] - 48;
  int seven = (int) tab2[6] - 48;
  int eight = (int) tab2[7] - 48;
  int nine = (int) tab2[8] - 48;
  int ten = (int) tab2[9] - 48;
  int eleven = (int) tab2[10] - 48;
  pointer = (int) tab2[11] - 48;
  
  
  //tab2[11] = '1';
  //int x = (int) tab2[11];
  //pointer = (int) tab2[11] - 48;

  Serial.print("Pointer: ");
  Serial.print(pointer);

  //int pointer=0;
  
  //int one,two,three,four,five,six,seven,eight,nine,ten,eleven;//initialize variables to store the 11 read digits into

  float interval = 20; //interval time in minuntes
  float checkin = 5;
  int checkPerInt=4;

  int countMax = round(interval/checkin);
  int count;



//read the pointer digit/char

while(pointer == 1) //initialize starting function
  {
    count = 0;

  //code to get numbers starts here

  String val;
  char c;

while(bluetooth.available())  // If the bluetooth sent any characters
  {
    // Send any characters the bluetooth prints to the serial monitor
    delay(10);
    c = (char)bluetooth.read();
    val += c;
  }
    if(val.length() > 0)
    {
        Serial.println(val);
        
 
        strncpy(tab2, val.c_str(), sizeof(tab2));
        tab2[sizeof(tab2) - 1] = 0;
        
        val="";
    
          for(int i;i<12;i++)
          {
            Serial.println(tab2[i]);
          }          
    }

  int one = (int) tab2[0] - 48;
  int two = (int) tab2[1] - 48;
  int three = (int) tab2[2] - 48;
  int four = (int) tab2[3] - 48;
  int five = (int) tab2[4] - 48;
  int six = (int) tab2[5] - 48;
  int seven = (int) tab2[6] - 48;
  int eight = (int) tab2[7] - 48;
  int nine = (int) tab2[8] - 48;
  int ten = (int) tab2[9] - 48;
  int eleven = (int) tab2[10] - 48;
  pointer = (int) tab2[11] - 48;

  Serial.print("Pointer in loop: ");
  Serial.println(pointer == 1);
  Serial.print(pointer);

  //code to get numbers ends here

  chargeNow = float(one)*10+float(two); //concatenate first two digits to form current battery percentage

  Serial.println("------");
  Serial.print("Charge Now: ");
  Serial.println(chargeNow);

  chargeEnd = 80; //create variable for end charge

  Serial.print("Charge Goal: ");
  Serial.println(chargeEnd);
  

  float timeNow = float(three)*10+float(four)+float(five)*0.1+float(six)*0.01; //concatenate 3-6 to form current time

  float timeEnd = float(seven)*10+float(eight)+float(nine)*0.1+float(ten)*0.01; //concatenate 7-10 to form end time

  Serial.print("Time Now: ");
  Serial.println(timeNow);
  Serial.print("Time End: ");
  Serial.println(timeEnd);

  float minNow = float(three)*600+float(four)*60+float(five)*10+float(six);//create current time in minutes
  float minEnd = float(seven)*600+float(eight)*60+float(nine)*10+float(ten);//create end time in minutes

  float minLeft = abs((1440-minNow)+ minEnd); //find the differene between end time and current time

  while (minLeft > 1440)//no charging things over a day
  {
    minLeft = minLeft - 1440;
  }

  minLeft = minLeft - 45;//leave time to charge at the end to 100% or 90%

  Serial.print("Time Left (minutes): ");
  Serial.println(minLeft);

   Serial.print("Pointer in first loop: ");
  Serial.println(pointer);
  Serial.print("Pointer == 1: ");
    Serial.println(pointer == 1);

  
  }//end pointer = 1
  Serial.println("End of loop one");
  Serial.print("Pointer = ");
  Serial.println(pointer);




  
  if (pointer == 0) //initialize standard function
  {
      
      count++;
      
      //enter this loop 5 minutes from begining count becomes 1
      //enter this loop 10 min from start count becomes 2
      //enter loop 15 minutes from start count becomes 3
      //enter loop 20 minutes from start count becomes 4
  
     //code to get numbers starts here
  
      /*one = 1;
      two = 5;
      three = 2;
      four = 2;
      five = 0;
      six = 5;
      seven = 0;
      eight = 8;
      nine = 3;
      ten = 0;
      eleven = 1;*/

    chargeEnd = 80; //create variable for end charge
  
    //code to get numbers ends here
  
    chargeLast = chargeNow;//set the last percentage read

    Serial.println("------");
    Serial.print("Last Charge: ");
    Serial.println(chargeLast);
  
    chargeNow = float(one)*10+float(two);//get new charge

    Serial.print("Charge Now: ");
    Serial.println(chargeNow);
  
    float changeChargeCheck = chargeNow-chargeLast; //get change in charge

    Serial.print("Charge in last 5 mins: ");
    Serial.println(changeChargeCheck);
  
    float changeChargeInt = changeChargeCheck*checkPerInt;//get change in charge per interval

    Serial.print("Charge in interval: ");
    Serial.println(changeChargeInt);
  
    float chargeNeed = chargeEnd-chargeNow;//find charge needed to finish charging

    Serial.print("Charge needed to get to 80: ");
    Serial.println(chargeNeed);
  
    int intervalNeed = ceil(chargeNeed/changeChargeInt);//number of intervals needed to finish charging

    Serial.print("Intervals needed to get to 80: ");
    Serial.println(intervalNeed);
  
    float intervalMinTotal = intervalNeed*interval;

    Serial.print("Charge Time needed to get to 80: ");
    Serial.println(intervalMinTotal);
  
    float minNow = float(three)*600+float(four)*60+float(five)*10+float(six);//create current time in minutes
    float minEnd = float(seven)*600+float(eight)*60+float(nine)*10+float(ten);//create end time in minutes
  
    float minLeft = abs((1440-minNow)+ minEnd); //find the differene between end time and current time
  
    while (minLeft > 1440)//no charging things over a day
      {
        minLeft = minLeft - 1440;
      }
    
    minLeft = minLeft - 45;//leave time to charge at the end to 100% or 90%

    Serial.print("Minutes untl 45 minutes before phone needed: ");
    Serial.println(minLeft);
  
    float spaceMinTotal = minLeft - intervalMinTotal;//total time for space between charging intervals;

    Serial.print("Minutes for all spaces: ");
    Serial.println(spaceMinTotal);
  
    double space = double(spaceMinTotal)/(intervalNeed-1);//minutes per space;

    Serial.print("Minutes per space: ");
    Serial.println(space);
  
    if(count%4==0)//if you go through 4 cycles
      {
        digitalWrite(outpin,HIGH);
        delay(space*60000);//delay of space*60000 milliseconds
      }

    
    
    if(chargeNow >= 80)
    {
      digitalWrite(outpin,HIGH);
      
      if(eleven == 1)
      {
        if(minLeft <= 0)
          {
          while(chargeNow<= 100)
            {
               digitalWrite(outpin,LOW);
            }
          }
        }

      if(eleven == 0)
      {
        if(minLeft <= -15)
          {
          while(chargeNow <= 90)
            {
               digitalWrite(outpin,LOW);
            }
          }
      }  
     }

    
    
      
  }//end pointer 1 loop

  //pointer = 2; //for testing purposes only

  if(pointer == 2)
    {
      digitalWrite(outpin,HIGH);
    }
    else
    {
      digitalWrite(outpin,LOW);
    }
}//end huge loop
