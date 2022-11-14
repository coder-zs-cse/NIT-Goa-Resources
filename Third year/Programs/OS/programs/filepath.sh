echo "Enter file path"
read FILE

if [ -f "$FILE" ]
then
	echo "$FILE is a regular file path"

elif [ -d "$FILE" ]
then 
	echo "$FILE is a directory"
fi
ls -l $FILE
