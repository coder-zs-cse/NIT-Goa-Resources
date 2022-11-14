echo "1.Addition"
echo "2.Subtraction"
echo "3.Multiplication"
echo "4.Division"

echo "Enter the first number"
read a
echo "Enter the second number"
read b
echo "Enter the operation choice you want to perform"
read op



case $op in 
1)output=`expr $a + $b`;;
2)output=`expr $a - $b`;;
3)output=`expr $a \* $b`;;
4)output=`expr $a / $b`;;
*)echo="Invalid option selection";;
esac

echo "$output"
