#!/usr/bin/expect

spawn ./phonebook
sleep 0.01

# Contact 1
send "ADD\r"
sleep 0.01
send "jeremychoochongkai\r"
sleep 0.01
send "choo\r"
sleep 0.01
send "jojo\r"
sleep 0.01
send "9823918\r"
sleep 0.01
send "he has fear of spiders\r"
sleep 0.01

send "SEARCH\r"
sleep 0.01
send "0\r"
sleep 0.01

# Contact 2
send "ADD\r"
sleep 0.01
send "jane\r"
sleep 0.01
send "doe a dear a female deer\r"
sleep 0.01
send "janey\r"
sleep 0.01
send "1234567\r"
sleep 0.01
send "loves hiking\r"
sleep 0.01

send "SEARCH\r"
sleep 0.01
send "1\r"
sleep 0.01

# Contact 3
send "ADD\r"
sleep 0.01
send "john\r"
sleep 0.01
send "0123456789\r"
sleep 0.01
send "johnny\r"
sleep 0.01
send "2345678\r"
sleep 0.01
send "avid reader\r"
sleep 0.01

send "SEARCH\r"
sleep 0.01
send "2\r"
sleep 0.01

# Contact 4
send "ADD\r"
sleep 0.01
send "alice\r"
sleep 0.01
send "wonder\r"
sleep 0.01
send "dally\r"
sleep 0.01
send "3456789\r"
sleep 0.01
send "enjoys painting\r"
sleep 0.01

send "SEARCH\r"
sleep 0.01
send "4\r"
sleep 0.01

# Contact 5
send "ADD\r"
sleep 0.01
send "bob\r"
sleep 0.01
send "builder\r"
sleep 0.01
send "bobby\r"
sleep 0.01
send "9876543\r"
sleep 0.01
send "likes to build\r"
sleep 0.01

send "SEARCH\r"
sleep 0.01
send "abc\r"
sleep 0.01

# Contact 6
send "ADD\r"
sleep 0.01
send "clara\r"
sleep 0.01
send "clark\r"
sleep 0.01
send "clary\r"
sleep 0.01
send "8765432\r"
sleep 0.01
send "interested in astronomy\r"
sleep 0.01

send "SEARCH\r"
sleep 0.01
send "5\r"
sleep 0.01

# Contact 7
send "ADD\r"
sleep 0.01
send "david\r"
sleep 0.01
send "dane\r"
sleep 0.01
send "dave\r"
sleep 0.01
send "7654321\r"
sleep 0.01
send "guitar player\r"
sleep 0.01

send "SEARCH\r"
sleep 0.01
send "8\r"
sleep 0.01

# # Contact 8
send "ADD\r"
sleep 0.01
send "emily\r"
sleep 0.01
send "earnest\r"
sleep 0.01
send "em\r"
sleep 0.01
send "6543210\r"
sleep 0.01
send "baker and chef\r"
sleep 0.01

# Finish with the SEARCH command
send "SEARCH\r"
sleep 0.01
send "invalid number\r"
sleep 0.01

send "ADD\r"
sleep 0.01
send "replace\r"
sleep 0.01
send "replace\r"
sleep 0.01
send "replace\r"
sleep 0.01
send "replace\r"
sleep 0.01
send "replace\r"
sleep 0.01
send "SEARCH\r"
sleep 0.01
send "0\r"
sleep 0.01

send "ADD\r"
sleep 0.01
send "replace\r"
sleep 0.01
send "replace\r"
sleep 0.01
send "replace\r"
sleep 0.01
send "replace\r"
sleep 0.01
send "replace\r"
sleep 0.01
send "SEARCH\r"
sleep 0.01
send "invalid number\r"
sleep 0.01

send "ADD\r"
sleep 0.01
send "replace\r"
sleep 0.01
send "replace\r"
sleep 0.01
send "replace\r"
sleep 0.01
send "replace\r"
sleep 0.01
send "replace\r"
sleep 0.01
send "SEARCH\r"
sleep 0.01
send "invalid number\r"
sleep 0.01

send "ADD\r"
sleep 0.01
send "replace\r"
sleep 0.01
send "replace\r"
sleep 0.01
send "replace\r"
sleep 0.01
send "replace\r"
sleep 0.01
send "replace\r"
sleep 0.01
send "SEARCH\r"
sleep 0.01
send "invalid number\r"
sleep 0.01

send "ADD\r"
sleep 0.01
send "replace\r"
sleep 0.01
send "replace\r"
sleep 0.01
send "replace\r"
sleep 0.01
send "replace\r"
sleep 0.01
send "replace\r"
sleep 0.01
send "SEARCH\r"
sleep 0.01
send "invalid number\r"
sleep 0.01

interact
