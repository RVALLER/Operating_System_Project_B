/* Maria Bui, Ryan Valler, Steph Teixeira, Troy Josti */

main() {
	char line[80], buffer[13312];
	int sectorsRead, i;

	while (1) {
		syscall(0, "\r\nSHELL> ");
		syscall(1, line);

		for (i = 0; i < 80; i++) {
			if (line[i] == '\n' || line[i] == '\r' || line[i] == ' ')
				line[i] = '\0';
		}

		if (line[0] == 't' &&
			line[1] == 'y' &&
			line[2] == 'p' &&
			line[3] == 'e') {
			syscall(3, line+5, buffer, &sectorsRead);
			if (sectorsRead > 0)
				syscall(0, buffer);
			else
				syscall(0, "file not found\r\n");
		}
		else if (line[0] == 'e' &&
				line[1] == 'x' &&
				line[2] == 'e' &&
				line[3] == 'c') {
				syscall(3, line+5, buffer, &sectorsRead);
				if (sectorsRead > 0)
					syscall(4, line+5);
				else
					syscall(0, "program not found\r\n");
		}
		else
			syscall(0, "Bad Command!\r\n");
	}
}
