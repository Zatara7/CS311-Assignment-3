#ifndef SMSA_DRIVER_INCLUDED
#define SMSA_DRIVER_INCLUDED

////////////////////////////////////////////////////////////////////////////////
//
//  File           : smsa_driver.h
//  Description    : This is the driver for the SMSA simulator.
//
//   Author        : Patrick McDaniel
//   Modifier	   : Hayder Sharhan
//   Created       : Tue Sep 17 07:15:09 EDT 2013
//   Last Modified : Mon Oct 21 2013
//

// Include Files
#include <stdint.h>

// Project Include Files
#include <smsa.h>

//
// Type Definitions
typedef uint32_t SMSA_VIRTUAL_ADDRESS; // SMSA Driver Virtual Addresses


// Interfaces
////////////////////////////////////////////////////////////////////////////////
////
//// Function     : smsa_vmount
//// Description  : Mount the SMSA disk array virtual address space
////
//// Inputs       : none
//// Outputs      : -1 if failure or 0 if successful

int smsa_vmount( void );

////////////////////////////////////////////////////////////////////////////////
////
//// Function     : smsa_vunmount
//// Description  :  Unmount the SMSA disk array virtual address space
////
//// Inputs       : none
//// Outputs      : -1 if failure or 0 if successful

int smsa_vunmount( void );

////////////////////////////////////////////////////////////////////////////////
////
//// Function     : smsa_vread
//// Description  : Read from the SMSA virtual address space
////
//// Inputs       : addr - the address to read from
////                len - the number of bytes to read
////                buf - the place to put the read bytes
//// Outputs      : -1 if failure or 0 if successful

int smsa_vread( SMSA_VIRTUAL_ADDRESS addr, uint32_t len, unsigned char *buf );

////////////////////////////////////////////////////////////////////////////////
////
//// Function     : smsa_vwrite
//// Description  : Write to the SMSA virtual address space
////
//// Inputs       : addr - the address to write to
////                len - the number of bytes to write
////                buf - the place to read the read from to write
//// Outputs      : -1 if failure or 0 if successful

int smsa_vwrite( SMSA_VIRTUAL_ADDRESS addr, uint32_t len, unsigned char *buf );

////////////////////////////////////////////////////////////////////////////////
////
//// Function     : get_current_drum
//// Description  : Will return the drum referenced by the address
////
//// Inputs       : addr - the address to decompose
//// Outputs      : -1 if failure or the drum ID if successful

int get_current_drum( SMSA_VIRTUAL_ADDRESS addr );

////////////////////////////////////////////////////////////////////////////////
////
//// Function     : get_current_block
//// Description  : Will return the block referenced by the address
////
//// Inputs       : addr - the address to decompose
//// Outputs      : -1 if failure or the block ID if successful
	
int get_current_block( SMSA_VIRTUAL_ADDRESS addr );

////////////////////////////////////////////////////////////////////////////////
////
//// Function     : get_current_offset
//// Description  : Will return the offset referenced by the address
////
//// Inputs       : addr - the address to decompose
//// Outputs      : -1 if failure or the offset if successful

int get_current_offset( SMSA_VIRTUAL_ADDRESS addr );

////////////////////////////////////////////////////////////////////////////////
////
//// Function     : get_opcode
//// Description  : Will combine the three inputs into opcode that could 
////                      communicate with smsa.
////
//// Inputs       : command - 0 through 9 instructions that tell smsa what to do
////                drumID - The drum ID if needed
////                blockID - the block ID if needed
//// Outputs      : -1 if failure or funcitonal opcode if successful

uint32_t get_opcode( int command, int drumID, int blockID );

////////////////////////////////////////////////////////////////////////////////
//
// Function     : load_workload_file
// Description  : Will load whatever is in the file smsa_data.dat to smsa.
//
// Inputs       : none.
// Outputs      : -1 if failure or 0 if success

int load_workload_file( void );

////////////////////////////////////////////////////////////////////////////////
//
// Function     : save_workload_file
// Description  : Will save whatever is currently in smsa to smsa_data.dat.
//
// Inputs       : none.
// Outputs      : -1 if failure or 0 if successful.

int save_workload_file ( void );

#endif
