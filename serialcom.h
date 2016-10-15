#ifndef SERIALCOMHEADER
#define SERIALCOMHEADER
int8_t serialSetup(uint16_t);
void serialReceive(void);
int8_t serialSend(uint8_t, char*);


#endif // SERIALCOMHEADER
