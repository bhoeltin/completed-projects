Comments:

- No answers for the activity 2 questions. -2.0. Renaming and removing only change metadata/inode information. Moving requires creating new files, copying data, and removing the original files.

- 4-3: If you use `-h` for `du`, then you should use `-h` instead of `-n` for sort. Using `-h` in `du` but not `sort` gives you the wrong answer. -0.5.

- 5-2a: Your pipeline should extract the PID and send a signal to that PID. This would work: `ps ux | grep TROLL | awk '{print $2}' | xargs kill -KILL` -0.75.

- 5-2b: This uses more than one command. `pkill -KILL TROLL` or `killall -KILL TROLL` would work. -0.5

Score: 11.25/15
