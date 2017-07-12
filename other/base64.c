char *base64_encode_ex(const char *src, \
		const int nSrcLen, char *dest, int *dest_len)
{
  int linePos;
  int leftover;
  int combined;
  char *pDest;
  int c0, c1, c2, c3;
  unsigned char *pRaw;
  unsigned char *pEnd;
  const char *ppSrcs[2];
  int lens[2];
  char szPad[3];
  int k;
  int loop;
  if (nSrcLen <= 0)
  {
       *dest = '\0';
       *dest_len = 0;
       return dest;
  }
  linePos = 0;
  lens[0] = (nSrcLen / 3) * 3;
  lens[1] = 4;
  leftover = nSrcLen - lens[0];
  ppSrcs[0] = src;
  ppSrcs[1] = szPad;

  szPad[0] = szPad[1] = szPad[2] = '\0';
  switch (leftover)
  {
      case 0:
      default:
           loop = 1;
           break;
      case 1:
           loop = 2;
           szPad[0] = src[nSrcLen-1];
           break;
      case 2:
           loop = 2;
           szPad[0] = src[nSrcLen-2];
           szPad[1] = src[nSrcLen-1];
           break;
  }

  pDest = dest;
  for (k=0; k<loop; k++)
  {
      pEnd = (unsigned char *)ppSrcs[k] + lens[k];
      printf("%s\n",pEnd);
      for (pRaw=(unsigned char *)ppSrcs[k]; pRaw<pEnd; pRaw+=3)
      {
         printf("%s\n",pRaw);
         // Start a new line if next 4 chars won't fit on the current line
         // We can't encapsulete the following code since the variable need to
         // be local to this incarnation of encode.
         linePos += 4;
         // get next three bytes in unsigned form lined up,
         // in big-endian order
         combined = ((*pRaw) << 16) | ((*(pRaw+1)) << 8) | (*(pRaw+2));

         // break those 24 bits into a 4 groups of 6 bits,
         // working LSB to MSB.
         c3 = combined & 0x3f;
         combined >>= 6;
         c2 = combined & 0x3f;
         combined >>= 6;
         c1 = combined & 0x3f;
         combined >>= 6;
         c0 = combined & 0x3f;

         // Translate into the equivalent alpha character
         // emitting them in big-endian order.
         //*pDest++ = 'a';
         //*pDest++ = 'b';
         //*pDest++ = 'c';
         //*pDest++ = 'd';
      }
  }

  return dest;
}
