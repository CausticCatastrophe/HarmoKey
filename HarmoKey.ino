// This must be done before the Control Surface library.
#include <Control_Surface.h> // Include the Control Surface library
 
// Instantiate a debug MIDI interface.
//USBDebugMIDI_Interface midi;

// Instantiate a hardware MIDI interface with Serial
// Select the serial port to use.
auto &serial = Serial;
// Instantiate a Serial MIDI interface at the default MIDI baud rate.
SerialMIDI_Interface<decltype(serial)> midi = {serial, MIDI_BAUD};

//////////////////////////////////////////
// Pin Definitions
// The compiler will replace any mention of 
// a definition with the value at compile time.
//////////////////////////////////////////

const pin_t octUpPin = 2;
const pin_t octDownPin = 3;
const pin_t scaleDegree7Pin = 4;
const pin_t scaleDegree6Pin = 5;
const pin_t scaleDegree5Pin = 6;
const pin_t scaleDegree4Pin = 7;
const pin_t scaleDegree3Pin = 8;
const pin_t scaleDegree2Pin = 9;
const pin_t scaleDegree1Pin = 10;
const pin_t shiftPin = 11;
const pin_t augPin = 0;
const pin_t sus2Pin = A1;
const pin_t sus4Pin = A2;
const pin_t intervalPlay1Pin = A3;
const pin_t intervalPlay2Pin = A4;
const pin_t intervalPlay3Pin = A5;
const pin_t intervalPlay4Pin = A0;
const pin_t keySelectPin = A7;

uint16_t val_simpleAnalog;
float dividedBits = 93; // bit resolution of analog is 1023. Divide by steps. (1023 / 11)

// Instantiate a NoteButton objects
// NoteButton(pin_t pin, MIDIAddress address, uint8_t velocity = 0x7F)

Bank<7> bank(4);
IncrementDecrementSelector<7> bankSelector {bank, {octUpPin, octDownPin}, Wrap::Wrap};
using namespace MIDI_PC;

MIDIAddress note_C3 = {MIDI_Notes::C(3), CHANNEL_1};
MIDIAddress note_Db3 = {MIDI_Notes::Db(3), CHANNEL_1};
MIDIAddress note_D3 = {MIDI_Notes::D(3), CHANNEL_1};
MIDIAddress note_Eb3 = {MIDI_Notes::Eb(3), CHANNEL_1};
MIDIAddress note_E3 = {MIDI_Notes::E(3), CHANNEL_1};
MIDIAddress note_F3 = {MIDI_Notes::F_(3), CHANNEL_1};
MIDIAddress note_Gb3 = {MIDI_Notes::Gb(3), CHANNEL_1};
MIDIAddress note_G3 = {MIDI_Notes::G(3), CHANNEL_1};
MIDIAddress note_Ab3 = {MIDI_Notes::Ab(3), CHANNEL_1};
MIDIAddress note_A3 = {MIDI_Notes::A(3), CHANNEL_1};
MIDIAddress note_Bb3 = {MIDI_Notes::Bb(3), CHANNEL_1};
MIDIAddress note_B3 = {MIDI_Notes::B(3), CHANNEL_1};

MIDIAddress note_C4 = {MIDI_Notes::C(4), CHANNEL_1};
MIDIAddress note_Db4 = {MIDI_Notes::Db(4), CHANNEL_1};
MIDIAddress note_D4 = {MIDI_Notes::D(4), CHANNEL_1};
MIDIAddress note_Eb4 = {MIDI_Notes::Eb(4), CHANNEL_1};
MIDIAddress note_E4 = {MIDI_Notes::E(4), CHANNEL_1};
MIDIAddress note_F4 = {MIDI_Notes::F_(4), CHANNEL_1};
MIDIAddress note_Gb4 = {MIDI_Notes::Gb(4), CHANNEL_1};
MIDIAddress note_G4 = {MIDI_Notes::G(4), CHANNEL_1};
MIDIAddress note_Ab4 = {MIDI_Notes::Ab(4), CHANNEL_1};
MIDIAddress note_A4 = {MIDI_Notes::A(4), CHANNEL_1};
MIDIAddress note_Bb4 = {MIDI_Notes::Bb(4), CHANNEL_1};
MIDIAddress note_B4 = {MIDI_Notes::B(4), CHANNEL_1};

MIDIAddress note_C5 = {MIDI_Notes::C(5), CHANNEL_1};
MIDIAddress note_Db5 = {MIDI_Notes::Db(5), CHANNEL_1};
MIDIAddress note_D5 = {MIDI_Notes::D(5), CHANNEL_1};
MIDIAddress note_Eb5 = {MIDI_Notes::Eb(5), CHANNEL_1};
MIDIAddress note_E5 = {MIDI_Notes::E(5), CHANNEL_1};
MIDIAddress note_F5 = {MIDI_Notes::F_(5), CHANNEL_1};
MIDIAddress note_Gb5 = {MIDI_Notes::Gb(5), CHANNEL_1};
MIDIAddress note_G5 = {MIDI_Notes::G(5), CHANNEL_1};
MIDIAddress note_Ab5 = {MIDI_Notes::Ab(5), CHANNEL_1};
MIDIAddress note_A5 = {MIDI_Notes::A(5), CHANNEL_1};
MIDIAddress note_Bb5 = {MIDI_Notes::Bb(5), CHANNEL_1};
MIDIAddress note_B5 = {MIDI_Notes::B(5), CHANNEL_1};

Bankable::ManyAddresses::NoteButton<7> noteButtons[] {
  {bank,
   intervalPlay1Pin, // pin
   {
     note_C3,
     note_D3,
     note_E3,
     note_F3,
     note_G3,
     note_A3,
     note_B3
   }},
  {bank,
   intervalPlay2Pin, // pin
   {
     note_E3,
     note_F3,
     note_G3,
     note_A3,
     note_B3,
     note_C4,
     note_D4
   }},
  {bank,
   intervalPlay3Pin, // pin
   {
     note_G3,
     note_A3,
     note_B3,
     note_C4,
     note_D4,
     note_E4,
     note_F4
   }},
  {bank,
   intervalPlay4Pin, // pin
   {
     note_B3,
     note_C4,
     note_D4,
     note_E4,
     note_F4,
     note_G4,
     note_A4
   }}
};

// Creates a filtered analog input for the key selection.
FilteredAnalog<> simpleAnalog = keySelectPin;

// Create a Button object that reads a push button connected to pin 2:
Button pushbutton {shiftPin};

void setup() {
  //Serial.begin(115200);
  //while (!Serial);

  // Select the correct ADC resolution
  FilteredAnalog<>::setupADC();
  
  // Initialize the filter to whatever the value on the input is right now
  // (otherwise, the filter is initialized to zero and you get transients)
  simpleAnalog.resetToCurrentValue();

  // put your setup code here, to run once:
  Control_Surface.begin(); // Initialize Control Surface
}

void loop() {

  Control_Surface.loop(); // Update the Control Surface

}
