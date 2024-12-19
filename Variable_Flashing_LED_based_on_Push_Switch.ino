// **************************************************************************************************//
// **************************************************************************************************//
// Author: Roshan Jude Cardoza
// Title: Variable Flashing LED based on Push Switch
// Date Modified : 19/12/2024
// Version : 1.0
// **************************************************************************************************//
// **************************************************************************************************//

#define LED_PIN 10  
#define BUTTON_PIN 13        


int press_button = 0;                              
float time_elapsed_since_toggle = 0;            
float rate_of_blink = 0;                          
float time_button_pressed = 0;                   
const float delay_between_press = 500;          

void setup() 
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(115200);

  digitalWrite(LED_PIN,LOW); // Turning LED OFF initially 
}

void loop()
{

  float time_at_start = millis();



  int button_value = digitalRead(BUTTON_PIN);

  if (button_value == LOW)

  {
      // Checking how many times the switch is pressed and assigning time in milliseconds value (0.5 -> 1000 / 1 -> 500 / 2 -> 250)

      if ((time_at_start - time_button_pressed) > delay_between_press)
      {

        press_button++;

        if (press_button > 4)
        {
          press_button = 1;
        }

        if ( press_button == 1 )
        {        
          rate_of_blink = 1000;
        }

        if( press_button == 2 )
        {        
          rate_of_blink = 500;       
        }

        if( press_button == 3 )
        {        
          rate_of_blink = 250;
        }
        
        if ( press_button == 4)
        {
          digitalWrite(LED_PIN,LOW);        
        }
        
        time_button_pressed = time_at_start;
        
      }
      
    }
    

  
  // LOGIC FOR BLINKING: The timer starts initially and another time is kept to store the value during 
  // which the LED is turned ON or OFF. Once the LED has been set, the time is stored and the time difference
  // between the timer and the time set is taken. This value should be greater than or equal to the rate
  // at which the LED is blinking. If not, it exits the loop until the condition is met. Once it has been met
  // the LED is revered in polarity.
  
  if (press_button != 4 && press_button !=0) 
  {
    if ((time_at_start - time_elapsed_since_toggle) >= rate_of_blink) 
    {

      digitalWrite(LED_PIN, !digitalRead(LED_PIN));  
      time_elapsed_since_toggle = time_at_start;                   
    }
  } 
  else 
  {
    digitalWrite(LED_PIN, LOW);
  }
}