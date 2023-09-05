#ifndef _strutils_h
#define _strutils_h

int str_split(char **src, char *buff, char sep, size_t src_len, size_t buff_len);
int str_index(char *src, char search, size_t src_len);
int str_len(char *src, int src_len);
char *str_trim(char *, size_t);

#endif /* _strutils_h */
