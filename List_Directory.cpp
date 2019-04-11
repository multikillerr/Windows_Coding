#include<stdio.h>
#include<ctype.h>
#include<direct.h>
#include<stdlib.h>
#include<iostream>
int main() {
	int ch, drive, curdrive;
	static char path[_MAX_PATH];
	curdrive = _getdrive();
	printf("All the available drives are:\n");
	for (drive = 1; drive <= 26; drive++) {
		if (!_chdrive(drive)) {
			printf("%c\n", drive + 'A' - 1);

			if (drive + 'A' - 1 == 'D')
			{
				printf("Drive Found!!");
				if (_getdcwd(drive, path, _MAX_PATH) != NULL) {
					printf("Current Directory is: %c", drive+'A'-1);
					putchar('\n');
				}
			}
		}
		_chdrive(curdrive);
	}
	return 0;
}