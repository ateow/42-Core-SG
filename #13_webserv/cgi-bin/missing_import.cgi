#!/usr/bin/env python3
import cgitb
cgitb.enable()

print("Content-Type: text/html\n")

print("<html><head><title>Missing Import</title></head><body>")
print("<h1>Trying to import a non-existent module!</h1>")

# Deliberate error: Importing a non-existent module
import non_existent_module

print("</body></html>")
