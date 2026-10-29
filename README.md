# INTRODUCTION

This project came on a whim of curiosity (as many wonderful things do) during the tail-end of 2025. I had always felt that
my family members loved to bother me *a bit* too much when I was in my room, and I wanted to see if that feeling was real,
or if it was just my low tolerance for sudden visits overpowering my perception. My remedy came in the form of this short study.

Emphasis on **short**--this study only spanned 2 weeks, and only measured the frequency of *my* door opening, not that of my family 
members as well. I also neglected to specify how many of these tracked openings were simply a result of me entering and leaving 
myself. These oversights leave a bit of a bad taste in my mouth, so I do plan on revisiting this project once again when I have the 
opportunity...and a lot more circuit boards and sensors (hopefully with non-radar wireless capabilities too!)

# PROCESS
## Materials
1x Adafruit Circuit Playground Express; Herein referred to as CPX

1x Data capable micro-usb cable.

1x Computing device, capable of running the Arduino IDE or other board interfaces.

## Setup
The setup was simple. I take an Arduino board, put it on my door (which had a handy shoe rack to support it), hook it up to
my computer, and have the Arduino record my door opening. Manually logging visits was also an option, but I didn't want to rely
on my memory, and I wanted to capture instances where I may not have been in the room too.
I chose to track acceleration to mark my room visits because it was the least noisy measure to use. You usually have to open
the door to visit me, so I knew I would always capture the relevant inputs. Other sensory data (e.g light, sound, infrared)
were too easily influenced by erroneous happenings, at least with the sensors on the board.

Tracking the data was easy, moving it wasn't as much. The CPX is loaded with inputs, but lacks with meaningful digital outputs.
No Bluetooth, no Wi-Fi, no secondary output cables, just a single micro-USB data link and a two way infrared (which would have been
too noisy and too much of a hassle for this experiment) This would make i very difficult to write to something like a CSV or a live
spreadsheet.

There were options on using the built in HDI controller. to log it's readings, but I wasnt sure that would be fast enough and it
would add a bit too much complexity at my scale. I ultimately just had it log the data points on seperate lines in the connected
serial port, and copied the data from the serial port monitor at the end of the day, moving it to a rolling CSV. It adds manual labor,
and there are alternatives like puTTY if you want to keep the session rolling and only compile your data at the end, but this worked
for my purposes. 

# FINDINGS AND CONCLUSIONS
I had my door opened an average of 29.71 times a day, with single day highs and lows of 34 and 23, respectively.
The data is more clustered together than I would have thought, but I can chock that up to a small period of observation and room for
growth in my setup. I feel like 29.71 is a lot, but I cant fully contextualize it without doing some niche literature review, or
addressing my previously stated shortcomings and oversights in design

There a few visualzations, tables, and the data itself living on a Google Doc found [**here**](https://docs.google.com/spreadsheets/d/1Z0vlZ4UaVL-yHoYKVpEWCui0iDL8olZwhZw15_rSmsw/edit?usp=sharing)
This was a fun project to do, and one I look forward to revisiting again more thoroughly. The questions I can ask data  abit limited in a spreadhseet,
so I would also look forward to migrating the data to a more tailored platform, like a SQL workbook. 

Thank you for your interest, and (hopfully) look forward to the updated study!
