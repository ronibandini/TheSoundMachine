# TheSoundMachine
Arduino code for The Sound Machine based on Roald Dahl short story

Based on Roald Dahl short story, this Arduino based machine will let you "hear" plant mood according to soil moisture.  
Even when sounds of course do not come from the plants but from mp3 recordings, the experience results revealing and gives you conscience 
about plants being alive and the suffering from water deprivation.

For this machine I've used:

Arduino Nano
FC28 sensor
7 segment display
Button
4ohm speaker
DFPlayer mp3 player
MicroSD card
Custom case.

You can find complete instructions at https://www.hackster.io/roni-bandini and 3D printed case at https://www.thingiverse.com/thing:4214068

The code will check button status and when the button is pressed it will read FC28 sensor, analog values will be mapped to 0-100 percentage scale, the percentage will be printed in the 7 segment display and a custom recording will be played according to the moisture percentage. 
Then random numbers are used to determine which mp3 inside each category to play.

For mp3 you have to number them from 001.mp3 to 018.mp3 You can produce your own sounds or download from a sound repository

Twitter @RoniBandini
Instagram @RoniBandini 

