#!/usr/bin/env python3
import cgitb
cgitb.enable()

print("Content-Type: text/html\n")

print("<html><head><title>Runtime Error</title></head><body>")
print("<h1>Attempting to divide by zero!</h1>")

result = 10 / 0

print(f"<p>The result is {result}</p>")
print("</body></html>")
