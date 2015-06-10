# qtezhelp - Easy Help System for Qt Programs using WebKit

Copyright 2015 by
Al Williams WD5GNR http://www.awce.com al.williams@awce.com
All Rights Reserved

Platform: Linux

License: GPL2


# Features:


* Very easy online help system
* Create HTML files for help
* Store in resources or files
* Modeless help dialog is reused for each help topic
* Launch to general home page or specific help topic
* 5 minutes to add to your code

# How to Use
I included HTML help for another program of mine (qrigol) to get you started. Note that you can have
the help browser open up any HTML page, so if you don't like how I did mine, that's fine.

That being said, I prepared help.html to have a frameset (yes, I know, no one likes frames anymore).
The left frame loads index.html which is a list of topic hyperlinks and the right frame loads
main.html. Note the links in index.html target the frame named "main" (the right hand frame).

You also need a .html file for every topic you want. I store these in my resources. You could put them in files
if you launched the help using file://.

Note that security won't let frames load other pages anymore, so any outside link will need to target something
like _top (see the examples).

# Adding to code
Very simple:
1) Add webkit to your .pro file (see this .pro file for an example)
2) Add helpdialog.* to your project
3) When you want to launch help, create a HelpDialog (only once) and call showHelp on it. See the example code.

# User Controls
The user can search for text on the page, go back or forward, or go back to the index.

# Report
Report bugs to al.williams@awce.com or better still, use GitHub.
