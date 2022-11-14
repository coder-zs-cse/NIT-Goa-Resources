echo "Enter a number"
read n
first=0
second=1
for (( i=1; $i <= $n; i= $i + 1 ))
do
	echo -n "$first "
	third=`expr $second + $first`
	first=$second
	second=$third

done
echo ""

