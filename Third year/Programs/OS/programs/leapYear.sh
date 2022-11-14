echo "Enter an year"
read n
s=`expr $n % 100`
r=`expr $n % 400`
t=`expr $n % 4`
if [ $t -eq 0 -a $s -ne	0 -a $r -ne 0 ] 
then
	echo "$n is a leap year"

else
	echo "$n is not a leap year"

fi

