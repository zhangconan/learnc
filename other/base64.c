#include "base64.h"
#include <stdbool.h>

/**
* Marker value for chars we just ignore, e.g. \n \r high ascii
*/
#define BASE64_IGNORE  -1

/**
* Marker for = trailing pad
*/
#define BASE64_PAD   -2

char *base64_encode_ex_old(const char *src, \
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

void base64_init_ex(struct base64_context *context, const int nLineLength, \
		const unsigned char chPlus, const unsigned char chSplash, \
		const unsigned char chPad)
{
      int i;
      //memset(context, 0, sizeof(struct base64_context));

      context->line_length = nLineLength;
      context->line_separator[0] = '\n';
      context->line_separator[1] = '\0';
      context->line_sep_len = 1;

      // build translate valueToChar table only once.
      // 0..25 -> 'A'..'Z'
      for (i=0; i<=25; i++)
      {
         context->valueToChar[i] = (char)('A'+i);
      }
      // 26..51 -> 'a'..'z'
      for (i=0; i<=25; i++ )
      {
         context->valueToChar[i+26] = (char)('a'+i);
      }
      // 52..61 -> '0'..'9'
      for (i=0; i<=9; i++ )
      {
         context->valueToChar[i+52] = (char)('0'+i);
      }
      context->valueToChar[62] = chPlus;
      context->valueToChar[63] = chSplash;
      for(i=0;i<sizeof(context->charToValue)/sizeof(int);i++){
        context->charToValue[i] = -1;
      }
      memset(context->charToValue, -1, sizeof(context->charToValue));
      for (i=0; i<64; i++ )
      {
         context->charToValue[context->valueToChar[i]] = i;
      }

      context->pad_ch = chPad;
      context->charToValue[chPad] = BASE64_PAD;
}

char *base64_encode_ex(const char *src, \
		const int nSrcLen,const bool bPad)
{
    char *dest[sizeof(int) * 5];
    int dest_len = 0;
    int nLineLength = 0;
    unsigned char chPlus = '-';
     unsigned char chSplash = '_';
		unsigned char chPad = '.';
   struct base64_context context;

        int i;
      //memset(context, 0, sizeof(struct base64_context));

      context.line_length = nLineLength;
      context.line_separator[0] = '\n';
      context.line_separator[1] = '\0';
      context.line_sep_len = 1;

      // build translate valueToChar table only once.
      // 0..25 -> 'A'..'Z'
      for (i=0; i<=25; i++)
      {
         context.valueToChar[i] = (char)('A'+i);
      }
      // 26..51 -> 'a'..'z'
      for (i=0; i<=25; i++ )
      {
         context.valueToChar[i+26] = (char)('a'+i);
      }
      // 52..61 -> '0'..'9'
      for (i=0; i<=9; i++ )
      {
         context.valueToChar[i+52] = (char)('0'+i);
      }
      context.valueToChar[62] = chPlus;
      context.valueToChar[63] = chSplash;
      for(i=0;i<sizeof(context.charToValue)/sizeof(int);i++){
        context.charToValue[i] = -1;
      }
      //memset(context->charToValue, -1, sizeof(context.charToValue));
      for (i=0; i<64; i++ )
      {
         context.charToValue[context.valueToChar[i]] = i;
      }

      context.pad_ch = chPad;
      context.charToValue[chPad] = BASE64_PAD;


  //base64_init_ex(&context, 0, '-', '_', '.');
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
       dest_len = 0;
       return dest;
  }

  linePos = 0;
  lens[0] = (nSrcLen / 3) * 3;
  lens[1] = 3;
  leftover = nSrcLen - lens[0];
  ppSrcs[0] = src;
  ppSrcs[1] = szPad;
  printf("输出src的值：%s\n",src);
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
  for(i=0;i<3;i++){
        printf("%c\n",(int)szPad[i]);
  }
  printf("输出szPad的值：%s\n",szPad);
    printf("输出ppSrcs[1]的值：%s\n",ppSrcs[1]);
  pDest = dest;
  printf("%d\n",dest_len);
  for (k=0; k<loop; k++)
  {
      pEnd = (unsigned char *)ppSrcs[k] + lens[k];
      for (pRaw=(unsigned char *)ppSrcs[k]; pRaw<pEnd; pRaw+=3)
      {
         // Start a new line if next 4 chars won't fit on the current line
         // We can't encapsulete the following code since the variable need to
         // be local to this incarnation of encode.
         printf("pRaw的值%s\n",pRaw);
         linePos += 4;
         if (linePos > context.line_length)
         {
            if (context.line_length != 0)
            {
               memcpy(pDest, context.line_separator, context.line_sep_len);
               pDest += context.line_sep_len;
               dest_len += context.line_sep_len;
            }
            linePos = 4;
         }

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
         *pDest++ = context.valueToChar[c0];
         *pDest++ = context.valueToChar[c1];
         *pDest++ = context.valueToChar[c2];
         *pDest++ = context.valueToChar[c3];
         dest_len += 4;
      }
  }
   printf("0之前%s\n",dest);
  *pDest = '\0';
   printf("0之后%s\n",dest);
  // deal with leftover bytes
  switch (leftover)
  {
     case 0:
     default:
        // nothing to do
        break;
     case 1:
        // One leftover byte generates xx==
        if (bPad)
        {
           *(pDest-1) = context.pad_ch;
           *(pDest-2) = context.pad_ch;
        }
        else
        {
           *(pDest-2) = '\0';
            printf("%s\n","输出截取之后的字符串");
            printf("%s\n",dest);
           dest_len -= 2;
        }
        break;
     case 2:
        // Two leftover bytes generates xxx=
        if (bPad)
        {
           *(pDest-1) = context.pad_ch;
        }
        else
        {
           *(pDest-1) = '\0';
           dest_len -= 1;
        }
        break;
  } // end switch;
  printf("最终结果%s\n",dest);
  printf("%d\n",sizeof(dest)/sizeof(dest[0]));
  printf("%d",dest_len);
  return dest;
}

char *testPointMinus(char *dest,int *dest_len){

    char *pDest;
    pDest = dest;
    int i;
    //相当于给dest赋值
    for(i=0;i<4;i++){
        *pDest++ = 'a'+i;
        *pDest++ = 'b'+i;
        *pDest++ = 'c'+i;
        *pDest++ = 'd'+i;
    }
     printf("%s\n","开始");
    printf("%s\n",pDest);
    printf("%s\n","开始2");
    printf("%s\n",dest);
  *pDest = '\0';
    printf("%s",pDest);
    printf("%s\n","结束");
    printf("%s\n",dest);
    //数组的长度
  *dest_len = pDest - dest;
  printf("%d",dest_len);
}

