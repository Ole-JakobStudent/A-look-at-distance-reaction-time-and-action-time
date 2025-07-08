 
//pin brukt i esp32s
//Board: her brukt esp32 Dev Module 
const int reactiomaller{14};
const int ledPIN {2};
const int ledReaktion {13};


// verdier trengt for å gjør ting.
int  randomTime{0};
int startTime {0};
int endTime{0};
int minWaitingTime {300};
int maxWaitingTime {3601};
const int pauseTime(1000);
//300 ms til 3601
  

void setup() {
  // For å besteme moitor på: 115200
  Serial.begin(115200);  

  //Forteller koden hva pinsene skal gjøre
  pinMode(reactiomaller, INPUT);
  pinMode(ledPIN, OUTPUT);
  pinMode(ledReaktion, OUTPUT);


  Serial.println("Vi er på");
}

void loop() {
  // millis kan byttes ut med millis(); med micro();

  // Tar mellom (50ms) 300ms, til 3 sekunder mellom hver mulighet. 
   randomTime = random(minWaitingTime, maxWaitingTime);delay(randomTime);
   startTime = millis();
  digitalWrite(ledReaktion, HIGH);

// så lenge knappen ikke er trykket, så går koden forbi while funksjonen her som ikke gjøre noe.
   while(digitalRead(reactiomaller)==LOW){
    // skal være tom.
    }
  endTime = millis();// måler når man har klikket inn.  
  digitalWrite(ledPIN, LOW);
  digitalWrite(ledReaktion, LOW);
  //skrur av ledene. 
  
  // sjekker om man jukser eller problemer med utstyret.
  if(endTime-startTime>=  60){  // vi sier ingen mennker har raskere reaksjon en 60millisekunder.
    digitalWrite(ledPIN, HIGH);
    
    //Dette er forskjellen mellom lyset blir skurdd på til kanppen blir trykket. 
    //Serial.println("Delta, reksjonstid:, ");  
    Serial.println(endTime - startTime);
  }

  else
   {
    // you cheat or inhuman reactions.
    Serial.println("Delta,Gear brooken, human brooken or you cheating!, "); 
    Serial.println(endTime - startTime);
    }

// Skrur av led lys, gir en pause
digitalWrite(ledPIN, LOW);
digitalWrite(ledReaktion, LOW);
delay(pauseTime);
}
