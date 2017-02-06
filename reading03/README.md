Reading 03
==========

1. echo "All your base are belong to us" | tr a-z A-Z
2. echo "monkeys love bananas" | sed 's/monkeys/gorillaz/'
3. echo "     monkeys love bananas" | sed -e 's/^[ \t]*//'
4. cat /etc/passwd | head | grep root | cut -d : -f 7
5. cat /etc/passwd | sed -r 's_/bin/(bash|csh|tsch)_/usr/bin/python_' | grep python
6. cat /etc/passwd | grep -r "4[0-9]*7"
7. comm -12 text1.txt text2.txt
8. diff -c text1.txt text2.txt