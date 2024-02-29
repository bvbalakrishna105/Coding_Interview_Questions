# Coding_Interview_Questions

List of tools/modules
1. Kafka with Go
2. Postgresql with Go
3. Docker RabbitMq with Go
4. ZeroMQ with Go
5. SQLite with Go
6. Docker
7. Kubernetes
8. Go Lang
9. GRPC with Go
10. Web server gin with Go
11. Go Test framework
12. Client and Server with Go
13. Go with C++
14. Delve for Go
15. REDIS with Go


CSCOPE
++++++Navigation Shortcuts:

Ctrl+]: Go to the definition of the symbol under the cursor.
Ctrl+t: Go back to the previous location.
Ctrl+d: Scroll down one page.
Ctrl+u: Scroll up one page.
Ctrl+n: Move to the next search result.
Ctrl+p: Move to the previous search result.
Search Commands:

s: Find symbol definition.
g: Find global definition.
d: Find functions called by this function.
c: Find functions calling this function.
t: Find text string.
e: Find egrep pattern.
f: Find file.
i: Find files #including this file.
;: Repeat last search command.
:: Change path prefix for file and function search.
q: Quit cscope.
Miscellaneous Commands:

Ctrl+l: Redraw screen.
Ctrl+k: Clear search history.
Ctrl+h: Display help.

Setup ctags
+++++++++++
ctags -R

Git  Shortcuts and Aliases
++++++++++++++++++++++++++
nano ~/.gitconfig


[alias]
    co = checkout
    ci = commit
    st = status
    br = branch
    lg = log --graph --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset' --abbrev-commit --date=relative



GDB Shortcuts
+++++++++++++++
Basic Commands:

run: Start executing the program.
break <line>: Set a breakpoint at the specified line.
break <function>: Set a breakpoint at the beginning of a function.
break *<address>: Set a breakpoint at the specified memory address.
continue or c: Continue program execution after hitting a breakpoint.
next or n: Execute the next line of code (step over).
step or s: Execute the next line of code (step into function calls).
print <variable>: Print the value of a variable.
info breakpoints: Show information about set breakpoints.
delete <breakpoint-number>: Delete a breakpoint by its number.
quit or q: Exit GDB.
Display Commands:

display <expression>: Add an expression to the list of automatically displayed expressions.
undisplay <display-number>: Remove a display expression by its number.
info display: Show information about automatically displayed expressions.
Backtrace and Stack Commands:

bt: Print a backtrace of the call stack.
frame <frame-number>: Select a specific stack frame.
info locals: Show the values of local variables in the current stack frame.
Memory Commands:

x/<count><format> <address>: Examine memory at the specified address.
Example: x/4xw 0x12345678 (examine 4 words at address 0x12345678).
info registers: Display the contents of CPU registers.
Thread Commands:

info threads: Show information about threads in the program.
thread <thread-id>: Switch to a specific thread for debugging.
Breakpoint Commands:

watch <expression>: Set a watchpoint on a variable.
rwatch <expression>: Set a read watchpoint on a variable.
awatch <expression>: Set an access watchpoint on a variable.
Shortcut Keys:

Ctrl+l: Redraw screen.
Ctrl+c: Interrupt execution and return to GDB prompt.
Ctrl+d: Quit GDB.


+++++++++++++++++++++++++++++
VI Editor ShortCuts
++++++++++++++++++++++++++++
Basic Navigation:

h: Move the cursor left.
j: Move the cursor down.
k: Move the cursor up.
l: Move the cursor right.
0: Move to the beginning of the line.
$: Move to the end of the line.
gg: Move to the beginning of the file.
G: Move to the end of the file.
<line-number>G: Move to a specific line number.
Editing:

i: Insert text before the cursor.
a: Append text after the cursor.
I: Insert text at the beginning of the line.
A: Append text at the end of the line.
o: Open a new line below the current line.
O: Open a new line above the current line.
x: Delete the character under the cursor.
dd: Delete the current line.
yy: Yank (copy) the current line.
p: Paste the yanked text after the cursor.
P: Paste the yanked text before the cursor.
Search and Replace:

/: Search forward for a pattern.
?: Search backward for a pattern.
n: Move to the next occurrence of the search pattern.
N: Move to the previous occurrence of the search pattern.
:s/pattern/replacement/: Replace the first occurrence of a pattern on the current line.
:s/pattern/replacement/g: Replace all occurrences of a pattern on the current line.
:%s/pattern/replacement/g: Replace all occurrences of a pattern in the entire file.
Saving and Quitting:

:w: Save changes to the file.
:q: Quit (exit) the vi editor.
:q!: Quit without saving changes (force quit).
:wq or :x: Save changes and quit.
Miscellaneous:

u: Undo the last edit.
Ctrl+r: Redo the last undone edit.
Ctrl+g: Show the current line number and file status.
:set nu: Show line numbers.
:set nonu: Hide line numbers.
:set syntax=on: Enable syntax highlighting.

