/* LibTomCrypt, modular cryptographic library -- Tom St Denis
 *
 * LibTomCrypt is a library that provides various cryptographic
 * algorithms in a highly modular and flexible manner.
 *
 * The library is free for all purposes without any express
 * guarantee it works.
 *
 * Tom St Denis, tomstdenis@gmail.com, http://libtomcrypt.org
 */
#include "tomcrypt.h"

/**
   @file cfb_getiv.c
   CFB implementation, get IV, Tom St Denis
*/

#ifdef CFB

/**
   Get the current initial vector
   @param IV   [out] The destination of the initial vector
   @param len  [in/out]  The max size and resulting size of the initial vector
   @param cfb  The CFB state
   @return CRYPT_OK if successful
*/
int cfb_getiv(unsigned char *IV, unsigned long *len, symmetric_CFB *cfb)
{
   LTC_ARGCHK(IV  != NULL);
   LTC_ARGCHK(len != NULL);
   LTC_ARGCHK(cfb != NULL);
   if ((unsigned long)cfb->blocklen > *len) {
      return CRYPT_BUFFER_OVERFLOW;
   }
   XMEMCPY(IV, cfb->IV, cfb->blocklen);
   *len = cfb->blocklen;

   return CRYPT_OK;
}

#endif

/* $Source: /cvs/cable/Cow/userspace/public/apps/sshd/libtomcrypt/src/modes/cfb/cfb_getiv.c,v $ */
/* $Revision: 1.3 $ */
/* $Date: 2015/08/20 02:27:56 $ */