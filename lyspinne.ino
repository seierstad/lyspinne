// her forteller vi hvor de forskjellige tingene er koblet til
#define R0DPINNE 2
#define GULPINNE 3
#define GR0NNPINNE 4

// her forteller vi andre ting som ikke skal forandre seg i løpet av programmet
#define BLINKELENGDE 200
#define SEKUNDLENGDE 1000


void setup() {
  // her er oppstartfunksjonen som kjører én gang når vi setter på strømmen
  
  pinMode(R0DPINNE, OUTPUT);   // her sier vi at R0DPINNE skal brukes til å sende signaler
  pinMode(GULPINNE, OUTPUT);  // her sier vi at GULPINNE skal brukes til å sende signaler
  pinMode(GR0NNPINNE, OUTPUT); // her sier vi at GR0NNPINNE skal brukes til å sende signaler
}

void ett_blink(int farge, int lystid, int pausetid) {
  digitalWrite(farge, HIGH);
  delay(lystid);
  digitalWrite(farge, LOW);
  delay(pausetid);
}

int bytt_farge(int farge) {
  if (farge == GR0NNPINNE) {
     return R0DPINNE;
  } else {
    return farge + 1;
  }
}

int periode = SEKUNDLENGDE;
int tid = BLINKELENGDE;
int farge = R0DPINNE;
int sekunder = 0;

void loop() {
  // her er hovedprogrammet som kjører igjen og igjen (i loop)

  //*
  ett_blink(farge, tid, periode - tid);

  sekunder = sekunder + 1;

  if (sekunder == 60) {
    farge = bytt_farge(farge);
    sekunder = 0;
    periode = periode + 2;
  }
  

  //*/
}
