/*
============================================================================
 Name        : Match.c
 Project	 : Groupcheck
 Author      : Scott Weekley
 Version     : 1.0A
 Description : Contains code for matching function. This will be
 	 	 	   A single function file.
 Notes		 : Ideas expanded from
		       http://www.programmingsimplified.com
		       The code has been adjusted from this website because
		       it would return the wrong numbers. Some other adjustments
		       have been made.
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
#include "Match.h"

int compare(char input[], char comp[]) {
  int c, d, e, text_length, pattern_length, position = -1;

  text_length    = strlen(input);
  pattern_length = strlen(comp);

  if (pattern_length > text_length) {
    return -1;
  }

  for (c = 0; c <= (text_length - pattern_length); c++) {
    position = e = c;
    --position;
    for (d = 0; d < pattern_length; d++) {
      if (comp[d] == input[e]) {
        e++;
      }
      else {
        break;
      }
    }
    if (d == pattern_length) {
      return position;
      break;
    }
  }

  return -1;
}
