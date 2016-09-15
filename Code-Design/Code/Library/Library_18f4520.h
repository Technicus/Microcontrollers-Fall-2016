/*
 * Library_18f4520.h
 *
 *
 */

// Included for compilerkeypadNumber_2

//
// #include <18f452.h> // Different compiler
// #include <18f4520.h> // Class compiler
#include "../../Library/18f4520.h"

// Set lock bits and fuses
#include "../../Library/FusesLockBits.h"

// All register addresses are defined as: #define REGISTER_<name-of-register> <hex-of-address>
#include "../../Library/Register_Addresses_Definitions.h"

// Pointers to TRIS PORT and LAT registers
#include "../../Library/TRIS_PORT_LAT.h"

// Structures for analog to digital circuits and defins for Q and L
#include "../../Library/Analog_To_Digital.h"

// Structures for interrupt curcuits
#include "../../Library/Interrupts.h"

// Custom libraries 

// keypad 
#include "../../Library/Keypad_Connection.h"

// LCD connections
#include "../../Library/Modified_LCD.h"
