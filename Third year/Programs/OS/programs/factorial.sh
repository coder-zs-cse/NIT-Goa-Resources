echo "Enter a number"
read n
m=$n
output=1
while [ $m -gt 1 ]
do
	output=`expr $output \* $m`
	m=`expr $m - 1`
	
done

echo "$n! = $output"


