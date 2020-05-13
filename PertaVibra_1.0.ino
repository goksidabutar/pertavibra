/*
------------------- PERTAVIBRA ----------------------
-- Vibration Inspection Based on Realtime Analyzer --
_________________________________________________
Dibuat oleh: Gok Sidabutar, PT. Pertamina GAS
Bimbingan Profesi Sarjana 2019 - On Job Trainee
_________________________________________________
*/

#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// Di bawah ini adalah pustaka frekuensi buzzer untuk
// masing-masing nada

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3123
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978


// Pin untuk buzzer melodi
#define buzzer 25

// Pin untuk motor 1,2,3 dan 4
int led_utama = 23;
int motor1 = 39;
int motor2 = 41;
int motor3 = 43;
int motor4 = 45;
int lcdkeys;


// Pin Untuk Sensor
int sensor1 = 8;
int sensor2 = 9;
int sensor3 = 10;
int sensor4 = 11;
int sensorValue = 0;
int val;

// melodi untuk Musik-0
int melodi[] = {
  NOTE_G7, NOTE_G7,
};
// Tempo untuk Musik-0
int tempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};


//melodi untuk Musik-2
int melodi2[] = {
  NOTE_A7,NOTE_A7,NOTE_A7,NOTE_A7,NOTE_A7,NOTE_A7, 0, 0, NOTE_A7
};
// Tempo untuk Musik-2
int tempo2[] = {
  12, 12, 12,
  12, 12, 12,
  6, 6,
  6, 6,
};

//melodi untuk Musik-3
int melodi3[] = {
  NOTE_G7, 0, 0, 0, 0, NOTE_G7, 0, 0, 0, 0, NOTE_D7, 0, 0, 0, 0
};
// Tempo untuk Musik-3
int tempo3[] = {
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
};

//melodi untuk Musik-4
int melodi4[] = {
  NOTE_G7, 0, 0, 0, 0, NOTE_G7, 0, 0, 0, 0, NOTE_D7, 0, 0, 0, 0
};
// Tempo untuk Musik-4
int tempo4[] = {
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
};

//melodi untuk Musik-5
int melodi5[] = {
  NOTE_G7, 0, 0, 0, 0, NOTE_G7, 0, 0, 0, 0, NOTE_D7, 0, 0, 0, 0
};
// Tempo untuk Musik-5
int tempo5[] = {
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
};

//melodi untuk Musik-6
int melodi6[] = {
  NOTE_G7, 0, 0, 0, 0, NOTE_G7, 0, 0, 0, 0, NOTE_D7, 0, 0, 0, 0
};
// Tempo untuk Musik-6
int tempo6[] = {
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
};
//melodi untuk Musik-7
int melodi7[] = {
  NOTE_G7, 0, 0, 0, 0, NOTE_G7, 0, 0, 0, 0, NOTE_D7, 0, 0, 0, 0
};
// Tempo untuk Musik-7
int tempo7[] = {
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
};

//melodi untuk Musik-8
int melodi8[] = {
  NOTE_G7, 0, 0, 0, 0, NOTE_G7, 0, 0, 0, 0, NOTE_D7, 0, 0, 0, 0
};
// Tempo untuk Musik-8
int tempo8[] = {
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
};

//melodi untuk Musik-9
int melodi9[] = {
  NOTE_G7, 0, 0, 0, 0, NOTE_G7, 0, 0, 0, 0, NOTE_D7, 0, 0, 0, 0
};
// Tempo untuk Musik-9
int tempo9[] = {
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
};

//melodi untuk Musik-10
int melodi10[] = {
  NOTE_G7, 0, 0, 0, 0, NOTE_G7, 0, 0, 0, 0, NOTE_D7, 0, 0, 0, 0
};
// Tempo untuk Musik-10
int tempo10[] = {
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
  3, 3, 3,
};


void setup(void)
{
  pinMode(23, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(29, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(35, OUTPUT);
  pinMode(37, OUTPUT);
  pinMode(39, OUTPUT);
  pinMode(41, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(45, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(49, OUTPUT);
  pinMode(51, OUTPUT);
  pinMode(53, OUTPUT);
  
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT); 

  lcd.clear();
  delay(2000);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Pertagas CSA");
  lcd.setCursor(0,1);
  lcd.print("VIBRA 4.0");

  Serial.begin(9600);
  
  // Menonaktifkan semua relay terlebih dahulu
  digitalWrite(27, HIGH);//
  digitalWrite(29, HIGH);//
  digitalWrite(31, HIGH);//
  digitalWrite(33, HIGH);//
  digitalWrite(35, HIGH);//
  digitalWrite(37, HIGH);//
  digitalWrite(39, HIGH);//
  digitalWrite(41, HIGH);//
  digitalWrite(43, HIGH);//
  digitalWrite(45, HIGH);//
  digitalWrite(47, HIGH);//
  digitalWrite(49, HIGH);//
  digitalWrite(51, HIGH);//
  digitalWrite(53, HIGH);//

}

/*********     MAIN PROGRAM    *********/


// Program Utama

void loop()
   {
 


   }




///////////////////////////////////////////////
/*       SUB PROGRAM START FROM HERE         */
///////////////////////////////////////////////

void rata_rata_mati(){

}

void rata_rata_nyala(){

}

void apakah_berisi(){
  
}



///////////////////////////////////////////////
/*     TESTING PROGRAM START FROM HERE       */
///////////////////////////////////////////////


// Program Menu Awal
void menu_awal(){
  lcd.clear();
  lcd.print("Selamat Datang");
  delay(2000);
  lcd.clear();
  lcd.print("Pilih Fitur");
  delay(2000);
  button();
}

// Program DEMO
void demo_progress(){
  lcd.clear();
  lcd.print("Selamat Datang");
  delay(2000);
  lcd.clear();
  lcd.print("Fitur Demo");
  delay(2000);
    lcd.clear();
  lcd.print("PertaVIBRA 1.0");
  delay(2000);
  button();

// Menyalakan dan mematikan motor secara bergantian

  start_motor_1();
  stop_motor_1();
  start_motor_2();
  stop_motor_2();
  start_motor_3();
  stop_motor_3();
  start_motor_4();
  stop_motor_4();
  
}


///////////////////////////////////////////////
/*      SENSOR PROGRAM START FROM HERE       */
///////////////////////////////////////////////

// Program pembacaan sensor 1
void baca_sensor_1(){
  
  sensorValue = analogRead(sensor1);
  digitalWrite(led_utama, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  sing(1);
  lcd.print("Nilai sensor 1 ");
  lcd.setCursor(0, 1);
  lcd.print(sensorValue, DEC);
  delay(200);
}

// Program pembacaan sensor 2
void baca_sensor_2(){
  
  sensorValue = analogRead(sensor2);
  digitalWrite(led_utama, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  sing(1);
  lcd.print("Nilai sensor 2 ");
  lcd.setCursor(0, 1);
  lcd.print(sensorValue, DEC);
  delay(200);
}

// Program pembacaan sensor 3
void baca_sensor_3(){
  
  sensorValue = analogRead(sensor3);
  digitalWrite(led_utama, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  sing(1);
  lcd.print("Nilai sensor 3 ");
  lcd.setCursor(0, 1);
  lcd.print(sensorValue, DEC);
  delay(200);
}

// Program pembacaan sensor 4
void baca_sensor_4(){
  
  sensorValue = analogRead(sensor4);
  digitalWrite(led_utama, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  sing(1);
  lcd.print("Nilai sensor 4 ");
  lcd.setCursor(0, 1);
  lcd.print(sensorValue, DEC);
  delay(200);
}



///////////////////////////////////////////////
/*      MOTOR PROGRAM START FROM HERE        */
///////////////////////////////////////////////
// Program Start Motor 1
void start_motor_1(){
  
  lcd.clear();
  lcd.print("Motor 1 menyala");
  sing(1);
  digitalWrite(motor1, LOW);
  digitalWrite(led_utama, HIGH);
  tone(buzzer, 100);
  delay(5000);

  }

// Program Start Motor 2
void start_motor_2(){

  lcd.clear();
  lcd.print("Motor 2 menyala");
  sing(1);
  digitalWrite(motor2, LOW);
  digitalWrite(led_utama, HIGH);
  tone(buzzer, 100);
  delay(5000);

  }

// Program Start Motor 3
void start_motor_3(){

  lcd.clear();
  lcd.print("Motor 3 menyala");
  sing(1);
  digitalWrite(motor3, LOW);
  digitalWrite(led_utama, HIGH);
  tone(buzzer, 100);
  delay(5000);

  }

// Program Start Motor 4
void start_motor_4(){

  lcd.clear();
  lcd.print("Motor 4 menyala");
  sing(1);
  digitalWrite(motor4, LOW);
  digitalWrite(led_utama, HIGH);
  tone(buzzer, 100);
  delay(5000);

  }

// Program Stop Motor 1
 void stop_motor_1(){
  
  sing(2);
  digitalWrite(motor1, HIGH);
  digitalWrite(led_utama, LOW);
  noTone(buzzer);
  }

// Program Stop Motor 2
  void stop_motor_2(){
  
  sing(2);
  digitalWrite(motor2, HIGH);
  digitalWrite(led_utama, LOW);
  noTone(buzzer);
  }

 // Program Stop Motor 3
  void stop_motor_3(){
  
  sing(2);
  digitalWrite(motor3, HIGH);
  digitalWrite(led_utama, LOW);
  noTone(buzzer);
  }

// Program Stop Motor 4
  void stop_motor_4(){
  
  sing(2);
  digitalWrite(motor4, HIGH);
  digitalWrite(led_utama, LOW);
  noTone(buzzer);
  }


///////////////////////////////////////////////
/*     BUTTON PROGRAM START FROM HERE        */
///////////////////////////////////////////////  

// Program Tombol
void button() {
  Serial.println(lcdkeys);
  lcdkeys=analogRead(0);
  if (lcdkeys<50) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("DEVICE 1");
  lcd.setCursor(0, 1);
  lcd.print("IS ON");
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, LOW);
  }
  else if(lcdkeys<250) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DEVICE 2");
    lcd.setCursor(0, 1);
    lcd.print("IS ON");
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, HIGH);
    
  }
  else if(lcdkeys<450) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DEVICE 3");
    lcd.setCursor(0, 1);
    lcd.print("IS ON");
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, HIGH);
  }
  else if(lcdkeys<650) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DEVICE 4");
    lcd.setCursor(0, 1);
    lcd.print("IS ON");
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, HIGH);
  }
  else if(lcdkeys<850) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("BLUECORE TECH");
    lcd.setCursor(0, 1);
    lcd.print("OFF");
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, HIGH);  
  }
}



///////////////////////////////////////////////
/*       SOUND PROGRAM START FROM HERE       */
///////////////////////////////////////////////
int song = 0;
void sing(int s) {
  song = s;


    if (song == 10) {
    int size = sizeof(melodi10) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      int noteDuration = 1000 / tempo10[thisNote];
      buzz(buzzer, melodi10[thisNote], noteDuration);

      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      buzz(buzzer, 0, noteDuration);
    }
  } 

      if (song == 9) {
    int size = sizeof(melodi9) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      int noteDuration = 1000 / tempo9[thisNote];
      buzz(buzzer, melodi9[thisNote], noteDuration);

      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      buzz(buzzer, 0, noteDuration);
    }
  } 

      if (song == 8) {
    int size = sizeof(melodi8) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      int noteDuration = 1000 / tempo8[thisNote];
      buzz(buzzer, melodi8[thisNote], noteDuration);

      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      buzz(buzzer, 0, noteDuration);
    }
  } 

      if (song == 7) {
    int size = sizeof(melodi7) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      int noteDuration = 1000 / tempo7[thisNote];
      buzz(buzzer, melodi7[thisNote], noteDuration);

      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      buzz(buzzer, 0, noteDuration);
    }
  } 
  
    if (song == 6) {
    int size = sizeof(melodi6) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      int noteDuration = 1000 / tempo6[thisNote];
      buzz(buzzer, melodi6[thisNote], noteDuration);

      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      buzz(buzzer, 0, noteDuration);
    }
  } 

    if (song == 5) {
    int size = sizeof(melodi5) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      int noteDuration = 1000 / tempo5[thisNote];
      buzz(buzzer, melodi5[thisNote], noteDuration);

      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      buzz(buzzer, 0, noteDuration);
    }
  } 
  
    if (song == 4) {
    int size = sizeof(melodi4) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      int noteDuration = 1000 / tempo4[thisNote];
      buzz(buzzer, melodi4[thisNote], noteDuration);

      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      buzz(buzzer, 0, noteDuration);
    }
  } 
  
    if (song == 3) {
    int size = sizeof(melodi3) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      int noteDuration = 1000 / tempo3[thisNote];
      buzz(buzzer, melodi3[thisNote], noteDuration);

      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      buzz(buzzer, 0, noteDuration);
    }
  } 
  
    if (song == 2) {
    int size = sizeof(melodi2) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      int noteDuration = 1000 / tempo2[thisNote];
      buzz(buzzer, melodi2[thisNote], noteDuration);

      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      buzz(buzzer, 0, noteDuration);
    }
  } 

    else {
    int size = sizeof(melodi) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      int noteDuration = 1000 / tempo[thisNote];
      buzz(buzzer, melodi[thisNote], noteDuration);
      
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      buzz(buzzer, 0, noteDuration);
    }
  }
}

void buzz(int targetPin, long frequency, long length) {
  digitalWrite(23, HIGH);
  long delayValue = 1000000 / frequency / 2; 
  long numCycles = frequency * length / 1000;
  
  for (long i = 0; i < numCycles; i++) {
    digitalWrite(targetPin, HIGH);
    delayMicroseconds(delayValue);
    digitalWrite(targetPin, LOW);
    delayMicroseconds(delayValue);
  }
  digitalWrite(23, LOW);

}
