#!/bin/sh
myvar=/afs/nd.edu/user15/pbui/pub/bin/cowsay

trap cleanup 1 2 15

cleanup()
{
  echo "Leaving so soon?" | $myvar
  exit 1
}

echo "What is your question??" | $myvar

read -p "Question?" question

while [ -z "$question" ]
do
    read -p "Please enter a question: " question
done

shuf -n 1 << EOF | $myvar

It is certain
It is decidedly so
Without a doubt
Yes, definitely
You may rely on it
As I see it, yes
Most likely
Outlook good
Yes
Signs point to yes
Reply hazy try again
Ask again later
Better not tell you now
Cannot predict now
Concentrate and ask again
Don't count on it
My reply is no
My sources say no
Outlook not so good
Very doubtful
EOF

