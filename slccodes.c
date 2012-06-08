/* Little proggy to work out the serial number, hostid and MAC address of a
 * SPARCstation SLC, given the 4-digit value on the NVRAM barcode
 *
 * to compile:
 * gcc slccodes.c -o slccodes
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char *argv[] )
{
	int ibc, hostid, mac, sn;
	if ( argc != 2 || (strcmp(argv[1], "-h" ) == 0 )) {
		printf("enter the 4-digit vaue found on your NVRAM barcode\n");
		exit(1);
	}

	ibc = strtol( argv[1], ( char ** ) NULL, 36 );
	sn = ibc - 0xAA8C0;
	mac = ibc - 0x82DC0;
	hostid = 0x54000000 + sn;

	printf( "SLC with barcode %s\n", argv[1] );
	printf( "Serial number %i\n", sn );
	printf( "MAC address 08:00:20:%2.2X:%2.2X:%2.2X\n",
	        ( mac & 0xff0000 ) >> 16, ( mac & 0xff00 ) >> 8, mac & 0xff );
	printf( "Hostid %8.8X\n", hostid );

	return 0;
}


