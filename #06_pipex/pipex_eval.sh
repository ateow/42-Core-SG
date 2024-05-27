make re
echo "================================================"
echo "   CREATE INFILE"
echo "================================================"
touch infile
echo "hello" > infile
echo "world" >> infile
echo "h" >> infile
cat infile

echo "================================================"
echo "    MANDATORY TEST - 2 Command"
echo "================================================"
./pipex infile "grep h" "wc -l" myoutfile
< infile grep h | wc -l > bashoutfile
echo "./pipex infile \"grep h\" \"wc -l\" myoutfile"
echo "my pipex | cat myoutfile" 
cat myoutfile
echo ""
echo "< infile grep 'h' | wc -l > bashoutfile "
echo "bash comd | cat bashoutfile"
cat bashoutfile

echo "================================================"
echo "    MANDATORY ERROR"
echo "================================================"
echo "./pipex infile \"grep h\" myoutfile"
./pipex infile "grep h" myoutfile

echo "================================================"
echo "    MANDATORY ERROR - INVALID CMD 1"
echo "================================================"
./pipex infile "g123rep h" "wc -l" myoutfile
echo ""
< infile g123rep h | wc -l > bashoutfile
echo ""
echo "./pipex infile \"g123rep h\" \"wc -l\" myoutfile"
echo "my pipex | cat myoutfile" 
cat myoutfile
echo ""
echo "< infile g123rep 'h' | wc -l > bashoutfile "
echo "bash comd | cat bashoutfile"
cat bashoutfile

echo "================================================"
echo "    MANDATORY ERROR - INVALID CMD 2"
echo "================================================"
./pipex infile "grep h" "w123c -l" myoutfile
echo ""
< infile grep h | w123c -l > bashoutfile
echo ""
echo "./pipex infile \"grep h\" \"w123c -l\" myoutfile"
echo "my pipex | cat myoutfile" 
cat myoutfile
echo ""
echo "< infile grep 'h' | w123c -l > bashoutfile "
echo "bash comd | cat bashoutfile"
cat bashoutfile

echo "================================================"
echo "    BONUS TEST - 3 Command"
echo "================================================"
./pipex infile "ls -la srcs" "grep .c" "wc -l" myoutfile
< infile ls -la srcs | grep .c | wc -l > bashoutfile
echo "/pipex infile \"ls -la srcs\" \"grep .c\" \"wc -l\" myoutfile"
echo "my pipex | cat myoutfile" 
cat myoutfile
echo ""
echo "< infile ls -la srcs | grep .c | wc -l > bashoutfile"
echo "bash comd | cat bashoutfile"
cat bashoutfile

echo "================================================"
echo "  BONUS TEST (here_doc) - hello\n world\n EOF "
echo "================================================"
./pipex here_doc EOF "cat" "grep h" myoutfile
cat << EOF | grep 'h' >> bashoutfile
hello
world
EOF
echo "./pipex here_doc EOF \"cat\" \"grep h\" myoutfile"
echo "my pipex | cat myoutfile" 
cat myoutfile
echo ""
echo "cat << EOF | grep 'h' >> bashoutfile"
echo "bash comd | cat bashoutfile"
cat bashoutfile
echo ""
echo ""
echo ""
echo "================================================"
echo "    MEMORY CHECK - VALID"
echo "================================================"
echo ""
valgrind ./pipex infile "grep h" "grep h" "wc -l" outfile
echo ""
echo "================================================"
echo "    MEMORY CHECK - Invalid File"
echo "================================================"
echo ""
valgrind ./pipex inf123ile "grep h" "grep h" "wc -l" outfile
echo ""
echo "================================================"
echo "    MEMORY CHECK - Invalid First Command"
echo "================================================"
echo ""
valgrind ./pipex infile "gr123ep h" "grep h" "wc -l" outfile
echo ""
echo "================================================"
echo "    MEMORY CHECK - Invalid Second Command"
echo "================================================"
echo ""
valgrind ./pipex infile "grep h" "gr123ep h" "wc -l" outfile
echo ""
echo "================================================"
echo "    MEMORY CHECK - Invalid Third Command"
echo "================================================"
echo ""
valgrind ./pipex infile "grep h" "grep h" "wc23 -l" outfile
echo ""
echo ""
echo ""
echo ""




#./pipex infile "grep h" "grep h" "wc -l" outfile
#./pipex here_doc EOF "grep h" "grep h" "wc -l" outfile
