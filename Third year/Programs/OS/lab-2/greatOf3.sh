echo "Enter three numbers"
read a b c
if [ $a -gt $b -a $a -gt $c ]
then 
	echo "$a is the greatest"
elif [ $b -gt $c ]
then
	echo "$b is the greatest"
else 
	echo "$c is the greatest"
fi	
