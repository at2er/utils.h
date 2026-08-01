#include <stdio.h>

static char *read_file(const char *path);

char *
read_file(const char *path)
{
	long len;
	char *result;
	FILE *stream;
	assert(path);
	if (!(stream = fopen(path, "r")))
		return NULL;

	fseek(stream, 0, SEEK_END);
	len = ftell(stream);
	fseek(stream, 0, SEEK_SET);

	result = malloc(len + 1);
	if (!result)
		goto end;
		
	fread(result, sizeof(char), len, stream);

end:
	fclose(stream);
	return result;
}
