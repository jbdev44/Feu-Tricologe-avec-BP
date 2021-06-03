char flag = 0;

int VG = 12 ; // LED Verte Gauche 
int OG = 11 ; // LED Orange Gauche 
int RD = 10 ; // LED Rouge Droite 
int VD = 9 ; // LED Verte Droite
int OD = 8 ; // LED Orange Droite 
int RG = 7 ; // LED Rouge Gauche 

 int PR = 6 ; // LED pieton Rouge
 int PV = 5 ; // LED pieton Vert

void setup()
{

  pinMode(VG, OUTPUT); //config Pin LED Verte Gauche en sortie 
  pinMode(OG, OUTPUT); //config Pin LED Orange Gauche en sortie 
  pinMode(RG, OUTPUT); //config Pin LED Rouge Gauche en sortie 
  pinMode(VD, OUTPUT); //config Pin LED Verte Droite en sortie 
  pinMode(OD, OUTPUT); //config Pin LED Orange Droite en sortie 
  pinMode(RD, OUTPUT); //config Pin LED Rouge Droite en sortie 
  pinMode(PR, OUTPUT); //config Pin LED Pieton Vert en sortie
  pinMode(PV, OUTPUT); //config Pin LED Pieton Rouge en sortie
  
  pinMode(2, INPUT); //config Pin02 en entrée classique
  
  digitalWrite(RG, HIGH); //LED Rouge Gauche
  digitalWrite(OG, LOW); //LED Orange Gauche
  digitalWrite(VG, LOW); //LED Verte Gauche
  digitalWrite(RD, HIGH); //LED Rouge Droite
  digitalWrite(OD, LOW);  //LED Orange Droite
  digitalWrite(VD, LOW);  //LED Verte Droite
  digitalWrite(PR, HIGH);  //LED Pieton Rouge
  digitalWrite(PV, LOW);  //LED Pieton Vert
  
  attachInterrupt(digitalPinToInterrupt(2), bp, FALLING);
  delay(1000);
}

void loop()
{
  while(flag == 0)
  {
    digitalWrite(RG, LOW);
    digitalWrite(VG, HIGH);
    delay(2000); // attente 2sec
    digitalWrite(VG, LOW);
    digitalWrite(OG, HIGH);
    delay(1000); // attente 1sec
    digitalWrite(OG, LOW);
    digitalWrite(RG, HIGH);
    delay(1000); // attente 1sec
    
    if (flag == 1)
    {
      digitalWrite(PR, LOW); //étein PR
      digitalWrite(PV, HIGH); //allume PV
      delay(5000); // attente 5sec
      digitalWrite(PR, HIGH); //allume PR
      digitalWrite(PV, LOW); //étein PV
      delay(1000);
      flag = 0;
    }
    
    digitalWrite(RD, LOW);
    digitalWrite(VD, HIGH);
    delay(2000); // attente 2sec
    digitalWrite(VD, LOW);
    digitalWrite(OD, HIGH);
    delay(1000); // attente 1sec
    digitalWrite(OD, LOW);
    digitalWrite(RD, HIGH);
    delay(1000); // attente 1sec

  } 
  
  digitalWrite(PR, LOW); //étein PR
  digitalWrite(PV, HIGH); //allume PV
  delay(5000); // attente 5sec
  digitalWrite(PR, HIGH); //allume PR
  digitalWrite(PV, LOW); //étein PV 
  delay(1000);
  flag = 0;  
}

void bp()
{ flag = 1 ;
}
