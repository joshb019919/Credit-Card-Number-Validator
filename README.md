Use Luhn's algorithm to validate Visa, Discover, and American Express credit card numbers.

### Usage: ./credit card numbers (numbers only) ###

### Luhn's Algorithm, by Hans Peter Luhn of IBM
Multiply every other digit by 2, starting with the number’s 
second-to-last digit, and then add those products’ digits 
together.

Add the sum to the sum of the digits that weren’t multiplied by 2.

If the total’s last digit is 0 (or, put more formally, if the 
total modulo 10 is congruent to 0), the number is valid!

A program based on [specifications](https://cs50.harvard.edu/x/2020/psets/1/credit/ "Substitution Cipher") given by HarvardX's online cs50 course.
