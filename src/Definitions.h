byte led[] = {28, 29, 30, 34, 35, 36, 40, 41, 42};
#define NUMLEDS sizeof(led)
byte encoder[] = {31, 27, 37, 33, 43, 39};
#define NUMENCODERS sizeof(encoder)
byte button[] = {22, 23, 24, 25, 26, 32, 38};
#define NUMBUTTONS sizeof(button)


const int encRight = 1;
const int encLeft = 2;
const int encNoChange = 3;
int encValueA = 0;
int encValueB = 0;
int encDirection = encNoChange;
const int encMinValue = 1;
const int encMaxValue = 100;
const int encStep = 1;


const int enc2Right = 1;
const int enc2Left = 2;
const int enc2NoChange = 3;
int enc2ValueA = 0;
int enc2ValueB = 0;
int enc2Direction = enc2NoChange;
int enc2OldValue = -1;
const int enc2MinValue = 24;
const int enc2MaxValue = 240;
const int enc2Step = .25;


const int enc3Right = 1;
const int enc3Left = 2;
const int enc3NoChange = 3;
int enc3ValueA = 0;
int enc3ValueB = 0;
int enc3Direction = enc3NoChange;
int enc3OldValue = -1;
const int enc3MinValue = 0;
const int enc3MaxValue = 100;
const int enc3Step = 5;


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
int bpm = 120;
