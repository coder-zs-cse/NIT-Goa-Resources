echo "Enter the algebraic expression"
read s
a= ${s:1:1}
echo "$a"
b= $s | cut -b 2
echo "$b"

