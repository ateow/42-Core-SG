#!/usr/bin/env python3
import cgitb
cgitb.enable()

# Infinite loop
i = 0
while (True):
    i += 1

print("Content-Type: text/html")    # HTML is following
print()                             # blank line, end of headers

print("<html>")
print("<head>")
print("<title>Test CGI</title>")
print("</head>")
print("<body>")
print("<h1>CGI Script with Infinite Loop</h1>")

print("</body>")
print("</html>")
