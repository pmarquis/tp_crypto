#include <stdio.h>
#include "integration.h"

// Les types et macros sont maintenant dans integration.h
// Les tableaux sont dans aes_data.c

void display_inout(char *str, u8 array[16])
{
	u8 i;
	printf("%s", str);
	for (i=0; i<16; i++)
	  printf("0x%02X ", array[i]);
	printf("\n\n");  
}

void input2state(u8 input[16], u8 state[4][4])
{
	u8 r,c;
    for (c=0; c<4; c++)
	  for (r=0; r<4; r++)
	    state[r][c] = input[r+4*c];
}

void state2output(u8 state[4][4], u8 output[16])
{
	u8 r,c;
    for (c=0; c<4; c++)
	  for (r=0; r<4; r++)
	    output[r+4*c] = state[r][c];
}

void copy_state(u8 state_in[4][4], u8 state_out[4][4])
{
	u8 r,c;
    for (c=0; c<4; c++)
	  for (r=0; r<4; r++)
	    state_out[r][c] = state_in[r][c];
}

void display_state(u8 state[4][4])
{
	u8 r;
	for (r=0; r<4; r++)
	  printf("0x%02X 0x%02X 0x%02X 0x%02X\n", state[r][0], state[r][1], state[r][2], state[r][3]);
}


int main(void)
{
  u8 input[16] = {0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d, 0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34};
  u8 key[16]   = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};

  //u8 input[16] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};
  //u8 key[16]   = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};

  u8 ciphered[16];
  u8 plained[16];
  u32 sub_key[44];
  
  KeyExpansion(key,sub_key);
  
  display_inout("input = \0", input);

  Cipher(input, ciphered, sub_key);    
  display_inout("ciphered = \0", ciphered);
  
  InvCipher(ciphered, plained, sub_key);    
  display_inout("plained = \0", plained);
  
  return 0;
}

		 
