echo "Enter number to make opreation : " 
read number
result=0
sum=0
counter=0
while [ $number -gt 0 ]
do
	lastdigits=$(( number%10 ))
	sum=$(( sum+lastdigits))
	result=$(( (result*10) +lastdigits ))
	number=$(( number/10 ))
	counter=$(( counter+1))
done
echo "Number digits in reverse order = $result"
echo "sum of its digits = $sum"
echo "average of its digits = $(( $sum/$counter))"
