// Module KY023
// For more info see http://tkkrlab.nl/wiki/Arduino_KY-023_XY-axis_joystick_module
int JoyStick_X = A0; // x
int JoyStick_Y = A1; // y
int JoyStick_Z = A2; // key
  String goL ,goR,goS,goD,go1,goDir,goF,goB,goaxisX,goaxisY;
  String goup,godeep,goaxisZ,deepness;
  int k, x, y, z, m, c,v,b,upz,dnz;
int pinUPZ = 8; // key
int pinDNZ = 4; // key
int Smode=0;
int Deepmode=0;

int speed1 =7; // key
int speed2 = 11; // key
int speed3 = 5; // key NOT OK 

int deep1 = 6; // key

int deep2 = 13; // key


double  axisSpeed = 500;
double axisMove = 0.1;
double command ;



void setup ()
{
  pinMode (JoyStick_X, INPUT);
  pinMode (JoyStick_Y, INPUT);
  pinMode (JoyStick_Z, INPUT_PULLUP);

   pinMode (pinUPZ, INPUT_PULLUP);
    pinMode (pinDNZ, INPUT_PULLUP);

     pinMode (speed1, INPUT_PULLUP);
      pinMode (speed2, INPUT_PULLUP);
       pinMode (speed3, INPUT_PULLUP);
       
          pinMode (deep1, INPUT_PULLUP);
      pinMode (deep2, INPUT_PULLUP);


    
    while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.begin (9600); // 9600 bps
  goS=" F100 ";
   go1="10";
    deepness="1";

}
void loop ()

{
  

  x = analogRead (JoyStick_X);
  y = analogRead (JoyStick_Y);
    k = analogRead (JoyStick_Z);
    
  upz = digitalRead (pinUPZ); // OK PIN 3
  
  dnz = digitalRead (pinDNZ); //12 NOT OK  
  
  z = digitalRead (speed1); //10 PIN NOT OK 
  m = digitalRead (speed2);//OK PIN 11 
  c = digitalRead (speed3);//NOT OK 9
  
  b = digitalRead (deep2); // OK 7
  v = digitalRead (deep1); //OK PIN 13

    if(z == 0)
    {
      Smode=1;
        go1="1.0";
      }
          if( m== 0)
    {
       Smode=2;
         go1="10";
      }
             if(c == 0)
    {
       Smode=3;
         go1="100";
      }

      
      if(( k < 20) && (z == 0))
      {
          goS=" F100 ";
        }
        
          if(( k < 20) && (m == 0))
      {
          goS=" F500 ";
        }
        
               if(( k < 20) && (c == 0))
      {
          goS=" F1500 ";
        }
      

      
         if(b== 0)
    {
      Deepmode=1;
      deepness="0.1";
      }
          if( v== 0)
    {
       Deepmode=2;
            deepness="1";
      }
     if((b== 0) && ( v== 0))
    {
      Deepmode=3;
            deepness="10";
      }


  goD="G00";
  goaxisX=" X";
  goaxisY=" Y";
  //go1="1.0";
  goDir="-";

  //AXIS
  goL=goD+goaxisX+go1+goS;
  goR=goD+goaxisX+goDir+go1+goS;
  goF=goD+goaxisY+go1+goS;
  goB=goD+goaxisY+goDir+go1+goS;


//Z AXIS

  goaxisZ=" Z";
 String ZSpeed=" F10 ";
godeep=goD+goaxisZ+deepness+ZSpeed;
goup=goD+goaxisZ+goDir+deepness+ZSpeed;


  if( upz == 0)
  {
     Serial.println(goup);
        delay(1000);
    }
      if( dnz == 0)
  {
     Serial.println(godeep);
        delay(1000);
    }

  if(x >700)
  {
      Serial.println(goL);
      delay(1000);
   } 
   
  if(y >700)
  {
    //  Serial.print ("Y-PLUS");
      Serial.println(goF);
           delay(1000);
    }
      if(x <400)
  {
    //  Serial.print ("X-MION");
            Serial.println(goR);
                 delay(1000);
    }
      if(y <400)
  {
   //   Serial.print ("Y-MION");
          Serial.println(goB);
               delay(1000);
    }
  
}


