# Glove

## Description

This project details the building of a musical instrument involving pressure
sensors attached to a glove. This instrument can then be used to play any five MIDI
notes with a synthesizer. Below there is video of it in action, photos of the
finished product and detailed instructions on building your own if you'd
like. Happy tinkering!

Special thanks to Professor Bryan Pardo of Northwestern University and
Professor Michael Gurevich of the University of Michigan for the inspiration
and guidance they provided.

### Video

#### Opening riff of Kids by MGMT

[![Kids](http://img.youtube.com/vi/K9sMBz1EEFs/0.jpg)](http://www.youtube.com/watch?v=K9sMBz1EEFs)

#### Part of Swing Low Sweet Chariot

[![Swing Low Sweet Chariot](http://img.youtube.com/vi/9VP2x4p4Dz0/0.jpg)](http://www.youtube.com/watch?v=9VP2x4p4Dz0)

### Photos

#### Board & Glove

![Board & Glove](http://i.imgur.com/JKGfHn3.jpg "Board & Glove")

#### Board

![Board](http://i.imgur.com/uUJmy3Y.jpg "Board")

#### Glove

![Glove](http://i.imgur.com/4paEGjq.jpg "Glove")

## Make Your Own

The following instructions specify how to make an exact replica of my glove but
feel free to experiment with and modify anything you'd like!

### Circuitry

#### Parts

- 5 pressure sensors ([Force sensitive resistors](http://www.openmusiclabs.com/learning/sensors/fsr/))
- 1 button
- 5 resistors (1k Ohms)
- 1 Arduino microchip (I used an Uno but others would work as well)
- Various wires

#### Construction

1. Connect one lead of each pressure sensor to ground and the other lead in serial with power, a resistor and a connection to one of the Arduino's analog ports.
2. Connect one of the button leads to ground and the other in serial with power and a connection to one of the Arduino's digital ports.
3. Attach pressure sensors to pads of glove (I used hot glue for the adhesive)
4. Enjoy!

### Arduino Code

The Arduino code involved in this project is incredibly basic. It simply reads
the pressure level from each of the 5 sensors and whether or not the button is
pressed. This information is then written to the computer's serial stream over USB.

### Max/MSP Code

If you would like to modify or play around with the code I recommend using the
`master` patch along with the library patches contained in the dev folder. If you
have no interest in changing my software but want to make your own glove and
play it I recommend the self-contained `glove` patch in the prod folder.

#### Prod folder

Once you've built your glove you should be able to open the `glove` patch
and start playing! Hopefully the UI is intuitive to use and the included
instructions clarify anything that isn't intuitive but if you have questions
please feel free to open an issue and I'm happy to help!

#### Dev folder

The Max code consists of one central `master` patch and several Library patches.
Using these library patches allows for abstraction and enables easier future
development. In order for them to work they must be placed in the Library folder
of your Max installation. Assuming Max was installed with defaults this would be
(adjusting the Max version number as necessary):

- MacOS: 		`~/Documents/Max 7/Library`
- Windows:	`C:\Users\{USERNAME}\Documents\Max 7\Library`

I was unable to find a software synth for Windows that respected MIDI volume
data so I chose to have additional pressure beyond a threshold trigger pitch bend
but if you would like to have fine control over volume of your notes and you
find a synthesizer that respects MIDI volume data that should be a relatively
straightforward change.

The Max code deals with serializing pressure values from the Arduino, the user
interface, and triggering of note and pitch bend data to a virtual synthesizer.
The comments should help explain some of the code, for any additional questions
feel free to ask.

### Synthesizer

There are many different software synthesizers one could use with this program.
It can be connected to a DAW like Ableton and then played with any of the MIDI
instruments in that program, or it can be run with standalone synths. I developed
the code using a standalone synth, specifically [Tethys](http://www.urbanite.karoo.net/tnaudio.htm).
There are many other standalone synths that could be used as well though not all
may respect pitch bend values and some may need code modifications to work exactly
as you'd like.

P.S. for Windows users: Unfortunately Windows has poor (read non-existent)
routing of Midi signals between various programs so a 3rd party utility is needed
to expose Midi connections from your synth to Max and vice versa. I recommend
[loopMIDI](https://www.tobias-erichsen.de/software/loopmidi.html)
but there are multiple other alternatives if that doesn't work for you.