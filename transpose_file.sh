#! /bin/sh
# Read from the file file.txt and print its transposed content to stdout.
# Given a text file file.txt, transpose its content.
# You may assume that each row has the same number of columns and each field is separated by the ' ' character.

# echo "name age\nalice 21\nryan 30" | awk \
cat file.txt | awk \
'{ \
	for (i = 1; i <= NF; i++) { \
		data[FNR, i] = $i; \
		# print(i, $i); \
	} \
} \
END \
{ \
	# print(NF, FNR); \
	for (i = 1; i <= NF; i++) { \
		for (j = 1; j <= FNR; j++) { \
			if (j == 1) {
				printf("%s", data[j, i]); \
			} else { \
				printf(" %s", data[j, i]); \
			} \
		} \
		printf("\n"); \
	} \
}' 
