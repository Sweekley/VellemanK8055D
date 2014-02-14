/*
============================================================================
 Name        : Match.h
 Project	 : Groupcheck
 Author      : Scott Weekley
 Version     : 1.0A
 Description : Contains code for matching function. This will be
 	 	 	   A single function file.
============================================================================
* Enceladus Confidential
* 2013 Enceladus Technologies
* All Rights Reserved.
* ___________________________________________________________________
* NOTICE:
* The intellectual and technical concepts contained
* herein are proprietary to Enceladus Technologies.
* Dissemination of this information or reproduction of this material
* is strictly forbidden unless prior written permission is obtained
* from Enceladus Technologies.
*/

#ifndef Match_
#define Match_

//#include "Main.h"
#if !defined(WIN32) || !defined(_WIN32) || !defined(__WIN32)
#include <stdbool.h>
#include <stdio.h>
#endif
#include <string.h>

extern int compare(char input[], char comp[]); 	/* used to compare the text
						 						*  returns the point in the string
						 						*  where the compare begines
						 						*/

#endif /*Match*/
