/*minimal working example (MWE)*/ 

#define BODCR _SFR_IO8(0x30) //Definimos la dirección de registro directamente de BODCR ya que en el core del ATTINY13 que estoy usando no lo han definido.

void setup() {
  power_down_mode(); //DORMIR - Dormimos chip con nuestra función
}

void loop() {
}

void power_down_mode(){ //Función para poner ATTINY13 a dormir profundo para bajar consumo al mínimo (según DATASHEET)
  bitWrite(ACSR,ACD,1); //Deshabilitamos comparador analógico AC para ahorrar energía
  bitWrite(ADCSRA,ADEN,0); //Deshabilita el ADC
  BODCR = B00000010; //Desactiva el Brown-out Detector (BOD) para disminuir consumo
  
  //FUNCIÓN EN C obtenida del DATASHEET para apagar el WATCHDOG TIMER (es como un contador para interrupciones por software en segundos, esto consume energía)
  noInterrupts(); //DORMIR - Esto es para deshabilitar todas las interrupciones y poder deshabilitar el Watchdog timer
  asm("wdr"); //Reset Watchdog Timer
  /* Clear WDRF in MCUSR */
  MCUSR &= ~(1<<WDRF);
  /* Write logical one to WDCE and WDE */
  /* Keep old prescaler setting to prevent unintentional time-out */
  WDTCR |= (1<<WDCE) | (1<<WDE);
  /* Turn off WDT */
  WDTCR = 0x00;
  interrupts();
  //FIN función apagado Watchdog timer (WDT)

  MCUCR = B00110000; //Habilita el modo sleep y define el tipo (power down mode), en este modo el oscilador se para y solo funcionan el Watchdog Timer (si no lo hemos apagado) y las interrupciones externas
  asm("sleep"); //Pone el microcontrolador a dormir
}