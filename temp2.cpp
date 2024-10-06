//setarea pinilor

int led_rosu=12;
int led_verde=13;
int led_albastru=5; //PWM
int ButonPin=7;
int verde =8;
int senzor= 6; 

int stare_buton=0;
float temp;
int count =0; //counterul
int n =0;


void setup()
{
  
  pinMode(ButonPin, INPUT);
  pinMode(led_rosu,OUTPUT);
  pinMode(led_verde,OUTPUT);
  pinMode(led_albastru,OUTPUT);

 // digitalWrite(led_rosu, HIGH); 
  
  Serial.begin(9600);
  digitalWrite(led_rosu, HIGH);

}

void temperatura()
{
  int citire = analogRead(senzor);
  float voltaj = citire * (5000 / 1024.0);
  float grade = voltaj / 10;
  
    // printam in serial temperatura
  Serial.print(grade);
  Serial.print(" \xB0"); //simbol grade
  Serial.println("C");
  delay(1000);
  
}


void loop()
{
 int stare_buton = 0;         //variabila care ne ajuta sa citim starea butonului

 stare_buton = digitalRead(ButonPin);
  
 if (stare_buton == HIGH && n == 0)//daca se apasa butonul
 {
   
   //calcul grade
  int citire = analogRead(senzor);
  float voltaj = citire * (5000 / 1024.0);
  float grade = voltaj / 10;
   //sfarsit calcul grade
   
   count++;
   
     if (count %2==0) //if countul nostru este numar par(la a 2-a apasare)    
     {
      	digitalWrite(led_rosu, HIGH);
   	 	digitalWrite(led_verde, LOW);
        digitalWrite(led_albastru, LOW);
        delay(1000);
 
       
     }
   	
  	 else{
   	////stingere aprindere leduri
     		digitalWrite(led_verde, HIGH); 
       		digitalWrite(led_rosu, LOW);

	
   // temp//
 			temperatura();
   	////sfarsit senzor temp
   
   			if(grade <= 60)
 			{
				analogWrite(led_albastru,10);
				
   			}
  			else if(grade>60 && grade<=90)
   			{
     			analogWrite(led_albastru,50);
				
   			}
   			else if(grade>90&&grade<=120)
   			{
     			analogWrite(led_albastru,100);
				
   			}
   			else if(grade>120)
   			{
     			analogWrite(led_albastru,255);
				
   			}
        delay(1000);
 
     
   		}
    n = 1; 
 }  
  else if(stare_buton == LOW) 
  {    
    n = 0;
  } 
   
   
   

 }
