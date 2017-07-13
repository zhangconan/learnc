#define BASE64_IGNORE  -1
void testmemset(const int nLineLength, \
		const unsigned char chPlus, const unsigned char chSplash, \
		const unsigned char chPad){
	/**
	 * letter of the alphabet used to encode binary values 0..63
	 */
	unsigned char valueToChar[64];
	/**
	 * binary value encoded by a given letter of the alphabet 0..63
	 */
	int charToValue[256];
    int i;
    int pad_ch;
     for (i=0; i<=25; i++)
      {
         valueToChar[i] = (char)('A'+i);
      }
      // 26..51 -> 'a'..'z'
      for (i=0; i<=25; i++ )
      {
         valueToChar[i+26] = (char)('a'+i);
      }
      // 52..61 -> '0'..'9'
      for (i=0; i<=9; i++ )
      {
         valueToChar[i+52] = (char)('0'+i);
      }
      valueToChar[62] = chPlus;
      valueToChar[63] = chSplash;
      printf("%s\n",valueToChar);
      //printf("%c\n",valueToChar[63]);
      //printf("%s\n","ÎÒºÃ");
      memset(charToValue, BASE64_IGNORE, sizeof(charToValue));
      //printf("%d\n",sizeof(charToValue)/sizeof(int));
      for(i=0;i<256;i++){
        printf("%d",charToValue[i]);
      }
      printf("\n");
      //printf("%s\n","ÄãºÃ");
      for (i=0; i<64; i++ )
      {
         charToValue[valueToChar[i]] = i;
      }
      pad_ch = chPad;
      charToValue[chPad] = -2;
      for(i=0;i<256;i++){
        printf("%d",charToValue[i]);
      }
      printf("\n");
      printf("%d",sizeof(charToValue)/sizeof(int));
}

