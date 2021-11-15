echo "the second"
read s
h=$(($s/3600))
s=$(($s-(3600*$h)))
m=$(($s/60))
s=$(($s-(60*$m)))
echo "$h :$m :$s"
