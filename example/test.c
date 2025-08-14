#include <kutil.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

	char *tex = malloc(sizeof(char) * 125);
	scanf("%s", tex);

	char* fmt_str = format_string("Hello, %s!", tex);
	printf("%s\n", fmt_str);
	free(tex);
	return 1;
}
