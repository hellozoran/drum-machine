byte button[] = {22, 23, 24, 25, 26, 32, 38, 44};
byte led[] = {28, 29, 30, 34, 35, 36, 40, 41, 42, 45};
byte encoder[] = {31, 27, 37, 33, 43, 39};
byte triggerPad[] = {};
byte triggerLed[] = {};

#define NUMLEDS sizeof(led)
#define NUMENCODERS sizeof(encoder)
#define NUMBUTTONS sizeof(button)
#define NUMTRIGGERPADS sizeof(triggerPad)
#define NUMTRIGGERLEDS sizeof(triggerLed)

#define DEBOUNCE 10
byte pressed[NUMBUTTONS], justpressed[NUMBUTTONS], justreleased[NUMBUTTONS];
byte previous_keystate[NUMBUTTONS], current_keystate[NUMBUTTONS];

byte playState = 0;
byte recState = 0;
byte muteState = 0;
byte encoder1mode = 0;
byte drumKit = 1;
byte drumLoop = 1;
int playbackVolume = 50;
