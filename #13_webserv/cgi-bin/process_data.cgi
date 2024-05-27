#!/usr/bin/env python3
import sys

# Reading the input data from standard input
input_data = sys.stdin.read()

# Assuming the input data is URL-encoded form data:
from urllib.parse import parse_qs
data = parse_qs(input_data)

name = data.get('name', [''])[0]  # Default to empty string if not provided
age = data.get('age', [''])[0]

print("<html><body>")
print(f"<h1>Hello, {name}!</h1>")
if age:
    print(f"You are {age} years old.")
else:
    print("You didn't tell us your age.")
print("</body></html>")
