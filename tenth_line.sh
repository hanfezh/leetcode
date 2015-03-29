#/bin/sh

count=1
cat file.txt | while read line
do 
	# echo "$count:$line"
	if [[ $count -eq 10 ]]; then
		echo $line
	fi
	count=$(($count + 1))
done
exit 0
