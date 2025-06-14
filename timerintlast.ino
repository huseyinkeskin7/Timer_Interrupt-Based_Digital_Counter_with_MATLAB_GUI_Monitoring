volatile int data1 = 0;              // to store sensor value
volatile int data2 = 0;              // to store sensor value
int Fs0  ;  // User input for Fs0
int Fs1 ;  // User input for Fs1

int analogPin1; //analogpin1
int analogPin2; //analogpin2
char value; //to store message from MATLAB

//the flag states for both timer interrupts
int prev_i1 =0; 
int prev_i2 =0;
volatile int current_i1=0;
volatile int current_i2=0;

String datatoprint1; //channel 1 data to send Matlab
String datatoprint2;//channel 2 data to send Matlab

void setup() {

  Serial.begin(115200); // serial communication

}

void loop() {
  if (current_i1>prev_i1) { //if the timerO interrupt triggered
    
      datatoprint1 = String('0') + "," + String(data1) + ","  + String(current_i1);
      Serial.println(datatoprint1); //print data from timer0 interrupt: data format.   timer no , data, current data index(runs)
      prev_i1=current_i1;
  }
  if (current_i2>prev_i2) { //if the timer2 interrupt triggered

    datatoprint2 =String('2') + "," + String(data2) + ","  + String(current_i2);
      Serial.println(datatoprint2);//print data from timer2 interrupt: data format.   timer no , data, current data index(runs)
      prev_i2=current_i2;
  }


  if (Serial.available() > 0) {  // checking the Arduino is getting data from MATLAB
    value = Serial.read();       // read the data received from MATLAB

    //AnalogPin1
    if (value == 'a') { //A01 // check the data from MATLAB and setting pins
        analogPin1 = A0;
    }
    if (value == 'b') {//A11
        analogPin1 = A1;
    }
    if (value == 'c') {//A21
        analogPin1 = A2;
    }
    if (value == 'd') {//A31
        analogPin1 = A3;
    }
    if (value == 'e') {//'A41'
        analogPin1 = A4;
    }
    if (value == 'f') {//'A51'
        analogPin1 = A5;
    }
    //AnalogPin2
    if (value == 'g') {  //'A02' check the data from MATLAB and setting pins
        analogPin2 = A0;
    }
    if (value == 'h') {//'A12'
        analogPin2 = A1;
    }
    if (value == 'i') {//'A22'
        analogPin2 = A2;
    }
    if (value == 'k') {//'A32'
        analogPin2 = A3;
    }
    if (value == 'l') {//'A42'
        analogPin2 = A4;
    }
    if (value == 'm') {//'A52'
        analogPin2 = A5;
    }
    //Timer frequency settings
    if (value =='1'){
      Fs0=70;
      setupTimer0();
    }
    if (value =='2'){
      Fs0=100;
      setupTimer0();
    }
    if (value =='3'){
      Fs0=150;
      setupTimer0();
    }
    if (value =='4'){
      Fs1=70;
      setupTimer1();
    }if (value =='5'){
      Fs1=100;
      setupTimer1();
    }
    if (value =='6'){
      Fs1=150;
      setupTimer1();
    }
  }
}

void setupTimer0() { //function to set the Timer 0
  cli();       // stop interrupts
  TCCR0A = 0;  // set entire TCCR0A register to 0
  TCCR0B = 0;  // same for TCCR0B
  TCNT0 = 0;   // initialize counter value to 0
  if (Fs0 == 70)
    OCR0A = 222;
  else if (Fs0 == 100)
    OCR0A = 155;
  else if (Fs0 == 150)
    OCR0A = 103;
  TCCR0A |= (1 << WGM01);                             // turn on CTC mode
  TCCR0B |= (1 << CS02) | (0 << CS01) | (1 << CS00);  // Set prescaler for 1024
  TIMSK0 |= (1 << OCIE0A); 
  sei();                        // enable timer compare interrupt
}

void setupTimer1() { //function to set the Timer 2
  cli();
  TCCR2A = 0; // set entire TCCR2A register to 0
  TCCR2B = 0; // same for TCCR2B
  TCNT2  = 0; // initialize counter value to 0
  if (Fs0 == 70)
    OCR2A = 222;
  else if (Fs0 == 100)
    OCR2A = 155;
  else if (Fs0 == 150)
    OCR2A = 103;
  TCCR2A |= (1 << WGM21);                                      
    // Set CS12, CS11 and CS10 bits for 1024 prescaler
  TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20); 
  TIMSK2 |= (1 << OCIE2A);
  sei(); // allow interrupts                                             
}


ISR(TIMER0_COMPA_vect) {
  data1 = analogRead(analogPin1); //analog read for choosen channel
  current_i1++;   //increase data index in every data receive

}

ISR(TIMER2_COMPA_vect) {
  data2 = analogRead(analogPin2); //analog read for choosen channel
  current_i2++;   //increase data index in every data receive

}