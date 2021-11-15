tt=0
echo "the num"
read n

for (( i = 2 ;i < n ;i++))
do 
 for (( j = 2 ;j < n ;j++))
do 
t=$(($i*$j))
 if [ $t -eq $n ]
 then
 echo "the number is not prime "
 tt=1
 break 
 fi
done
if [ $tt -eq 1 ]
then
break
fi
done

if [ $tt -eq 0 ]
then
echo "the number is prime "
fi

