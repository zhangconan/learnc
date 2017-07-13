struct base64_context
{
	char line_separator[16];
	int line_sep_len;

	/**
	 * max chars per line, excluding line_separator.  A multiple of 4.
	 */
	int line_length;

	/**
	 * letter of the alphabet used to encode binary values 0..63
	 */
	unsigned char valueToChar[64];

	/**
	 * binary value encoded by a given letter of the alphabet 0..63
	 */
	int charToValue[256];
	int pad_ch;
};

