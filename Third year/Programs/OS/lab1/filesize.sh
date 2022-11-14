echo "Enter the file path"
read FILE
echo $(du $FILE -sh)
size=$(du $f -s | awk '{print $1}')
