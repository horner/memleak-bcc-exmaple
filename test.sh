:

make

echo "Simple test"
./memleak-example &
LEAKPID=$!

echo Launched ./memleak-example as $LEAKPID
echo /usr/share/bcc/tools/memleak -p $LEAKPID -a
sudo /usr/share/bcc/tools/memleak -p $LEAKPID -a


exit

echo "Thread test"
./memleak-thread-example &
LEAKPID=$!

echo Launched ./memleak-thread-example as $LEAKPID
echo /usr/share/bcc/tools/memleak -p $LEAKPID -a
sudo /usr/share/bcc/tools/memleak -p $LEAKPID -a

