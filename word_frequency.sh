#! /bin/sh
# Read from the file words.txt and output the word frequency list to stdout.

: << DEBUG
cat words.txt | awk \
'{
	for (i = 1; i <= NF; i++) {
		words[$i] += 1;
	}
}
END {
	max = 1;
	for (k in words) {
		v = words[k];
		nwords[v] = k;
		if (v > max) {
			max = v;
		}
	}
	for (i = max; i > 0; i--) {
		if (nwords[i] > 0) {
			printf("%s %d\n", nwords[i], i);
		}
	}
}'
DEBUG

cat words.txt | awk \
'{
	for (i = 1; i <= NF; i++) {
		words[$i] += 1;
	}
}
END {
    for (k in words) {
        printf("%s %d\n", k, words[k]);
    }
}' | sort -k2nr
