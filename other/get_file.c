#define FDFS_STORAGE_DATA_DIR_FORMAT  "%02X"
void get_file_name(char *filename,int *filename_len,const char *szFormattedExt){
    int len;
    int ext_name_len = 7;
    char encoded[] = "hello";
	len = sprintf(filename, FDFS_STORAGE_DATA_DIR_FORMAT"/" \
			FDFS_STORAGE_DATA_DIR_FORMAT"/", \
			12,
			13);
    printf("%d\n",len);
    //最多就是encoded的长度
	memcpy(filename+len, encoded, *filename_len);
	memcpy(filename+len+(*filename_len), szFormattedExt, ext_name_len);
    printf("%d\n",len);
	*filename_len += len + ext_name_len;
	*(filename + (*filename_len)) = '\0';
}
