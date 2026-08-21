# 🌱🔊 The Sound Machine

**An Arduino-powered literary machine inspired by Roald Dahl's 1949 short story _The Sound Machine_, translating soil moisture into an imagined audible mood for plants.**

The Sound Machine is an electronic-literature project built around a simple fictional premise:

> What would a machine sound like if it allowed us to hear the condition of a plant?

A soil-moisture sensor measures the hydration level of a plant. An **Arduino Nano** converts that reading into a percentage and selects a corresponding prerecorded sound from a **DFPlayer Mini** and microSD card.

A well-watered plant may laugh.

A dry plant may complain, groan, or scream.

```text
Plant
  │
  ▼
Soil moisture sensor
  │
  ▼
Arduino Nano
  │
  ├── Moisture level
  │
  ├── Display / analog meters
  │
  └── Sound selection
          │
          ▼
     DFPlayer Mini
          │
          ▼
       Speaker
```

The machine does **not** claim to record actual plant voices. Its sounds are prerecorded and selected according to the measured soil moisture.

The project exists at the intersection of:

- 📚 literature
- 🌱 plants
- ⚡ Arduino
- 🎵 sound
- 🖨️ 3D printing
- 🧠 speculative interfaces
- 🔬 plant sensing
- 🎭 electronic art

---

## ✨ Features

- 🌱 Soil-moisture measurement
- 🧮 Arduino Nano controller
- 🎵 DFPlayer Mini MP3 playback
- 💾 microSD audio storage
- 🔊 4 Ω speaker
- 🔘 Physical activation button
- 📊 Visual moisture indication
- 🎚️ Adjustable sensitivity in the redesigned version
- 📟 Analog panel meters in the redesigned version
- 💡 Status LED
- 🔄 Startup audio
- 🎲 Avoids immediate repetition of sounds
- 🖨️ Custom 3D-printed enclosure
- 📖 21-page project manual included
- 🎭 Inspired directly by Roald Dahl's fiction
- 📜 GPL-3.0 licensed source code

---

# 📖 Literary origin

The project is inspired by:

## _The Sound Machine_ — Roald Dahl

Roald Dahl's short story **_The Sound Machine_** appeared in the September 17, 1949 issue of _The New Yorker_.

The protagonist, **Klausner**, builds an electronic device capable of translating ultrasonic vibrations into frequencies audible to humans.

In the story, he becomes convinced that flowers and trees produce sounds that humans normally cannot hear.

```text
Plant vibration
      │
      ▼
Klausner's fictional machine
      │
      ▼
Frequency conversion
      │
      ▼
Human hearing
```

The Arduino project does not attempt to reproduce the fictional acoustic electronics literally.

Instead, it translates the idea into a contemporary physical-computing object:

```text
Plant condition
      │
      ▼
Soil moisture
      │
      ▼
Arduino
      │
      ▼
Artificial voice
```

### Original story

**[The Sound Machine — The New Yorker](https://www.newyorker.com/magazine/1949/09/17/the-sound-machine)**

---

# 🧬 Two versions

The repository documents two iterations of the machine.

```text
The Sound Machine
       │
       ├── Version 1
       │     Digital moisture display
       │
       └── Klausner Machine
             Analog instrumentation
             Calibration control
             Redesigned enclosure
```

The repository contains two Arduino sketches:

```text
SoundMachine3.ino
SoundMachine5.ino
```

along with the complete project manual:

```text
LaMaquinaDeKlausner.pdf
```

---

# 1️⃣ Original Sound Machine

The first version was completed in early 2020.

Its hardware includes:

- Arduino Nano
- FC-28 soil-moisture sensor
- 7-segment display
- push button
- DFPlayer Mini
- microSD card
- 4 Ω speaker
- custom enclosure

The interface is deliberately simple.

```text
Insert sensor into soil
          │
          ▼
     Press button
          │
          ▼
 Read moisture level
          │
          ▼
 Map value to 0–100%
          │
          ├──────────────┐
          ▼              ▼
      Display %      Select sound
                         │
                         ▼
                     Speaker
```

---

## 💧 Moisture mapping

The analog soil reading is converted into a percentage representing the approximate moisture level.

Conceptually:

```cpp
rawSensorValue
      │
      ▼
map(...)
      │
      ▼
0 ... 100 %
```

The percentage then determines the emotional response of the machine.

The original implementation uses behavior such as:

```text
< 30% moisture
      │
      ▼
distressed / screaming sound
```

and:

```text
> 75% moisture
      │
      ▼
happy / laughing sound
```

Intermediate values select other recordings.

---

# 2️⃣ The Klausner Machine

The second version was completed later in 2020.

It is a substantial redesign of the original prototype.

Changes include:

```text
7-segment display
        ↓
2 analog panel meters

fixed sensor behavior
        ↓
adjustable sensitivity

basic sound selection
        ↓
anti-repetition routine

simple startup
        ↓
startup sound

original enclosure
        ↓
redesigned case
```

The goal was to make the physical object look less like a conventional Arduino project and more like the fictional scientific instrument described by Dahl.

---

## 🎛️ Redesigned controls

The Klausner Machine adds:

- two analog panel meters
- sensitivity potentiometer
- power switch
- LED
- calibration routines

The analog interface reinforces the appearance of an experimental scientific instrument.

```text
           ┌─────────────────┐
           │ Klausner Machine│
           └───────┬─────────┘
                   │
       ┌───────────┼────────────┐
       ▼           ▼            ▼
  Moisture      Analog       Sensitivity
   probe        meters          knob
       │
       └───────────┬────────────┘
                   ▼
             Arduino Nano
                   │
                   ▼
              DFPlayer
                   │
                   ▼
                Speaker
```

---

# 🧰 Hardware

## Original version

| Qty | Component | Purpose |
|---:|---|---|
| 1 | Arduino Nano | Main controller |
| 1 | FC-28 soil-moisture sensor | Moisture measurement |
| 1 | 7-segment display | Moisture percentage |
| 1 | DFPlayer Mini | MP3 playback |
| 1 | microSD card | Audio storage |
| 1 | 4 Ω speaker | Audio output |
| 1 | Push button | Measurement / playback |
| 1 | Custom enclosure | Physical interface |

---

## Klausner Machine

| Qty | Component | Purpose |
|---:|---|---|
| 1 | Arduino Nano | Main controller |
| 1 | Soil-moisture sensor | Plant hydration measurement |
| 1 | DFPlayer Mini | Audio playback |
| 1 | microSD card | Audio storage |
| 1 | 4 Ω speaker | Audio output |
| 2 | Analog panel meters | Visual indication |
| 1 | Potentiometer | Sensitivity calibration |
| 1 | Push button | User input |
| 1 | LED | Status indication |
| 1 | Power switch | Main control |
| 1 | Custom enclosure | Instrument body |

---

# 🌱 Soil-moisture sensor

The project measures the electrical properties of the soil using a resistive moisture probe.

A typical FC-28-style module provides an analog voltage corresponding approximately to soil conductivity.

```text
Wet soil
   │
   ▼
different electrical resistance
   │
   ▼
analog measurement
```

The Arduino reads this value and converts it into the scale used by the machine.

---

## ⚠️ Sensor calibration

Raw soil-moisture values vary significantly depending on:

- soil composition
- mineral content
- probe depth
- temperature
- sensor corrosion
- water conductivity
- power-supply voltage

The redesigned Klausner Machine therefore includes an adjustable calibration control.

For a new sensor or plant, determine representative values for:

```text
dry soil
```

and:

```text
wet soil
```

before interpreting the output as a percentage.

---

# 🎵 DFPlayer Mini

Audio is reproduced using a **DFPlayer Mini**-style MP3 module.

The module provides:

- microSD storage
- MP3 playback
- serial control
- direct speaker output
- compact standalone operation

The Arduino sends commands selecting which recording should be played.

```text
Arduino
   │
   │ serial command
   ▼
DFPlayer
   │
   ▼
microSD
   │
   ▼
MP3 recording
   │
   ▼
Speaker
```

---

# 💾 Audio files

Prepare the microSD card with the sound files required by the sketch.

The collection can contain recordings representing different states such as:

```text
startup
very dry
dry
normal
wet
very wet
```

The actual sounds are an artistic choice.

The original machine uses contrasting human-like sounds such as:

```text
groans
screams
laughs
giggles
```

to convert an otherwise ordinary sensor value into an emotional interface.

---

# 🔄 Sound repetition control

The redesigned version adds logic intended to avoid playing the same sample repeatedly.

Instead of:

```text
same moisture
    │
    ▼
same sound
    │
    ▼
same sound
    │
    ▼
same sound
```

the machine can select among several recordings associated with the same general state.

This makes repeated interaction less mechanically predictable.

---

# 🔘 Interaction

Typical operation is:

```text
1. Insert probe into soil

2. Turn on the machine

3. Adjust sensitivity if required

4. Press the measurement button

5. Arduino reads the sensor

6. Visual indicators react

7. A corresponding recording is played
```

The machine is intentionally interaction-driven rather than continuously producing audio.

---

# 🧪 What the machine actually measures

The Sound Machine measures:

```text
soil moisture proxy
```

It does not directly measure:

```text
plant emotion
plant pain
plant consciousness
plant acoustic emissions
```

The emotional interpretation is part of the literary and artistic interface.

```text
physical measurement
        +
fictional interpretation
        =
The Sound Machine
```

---

# 🔬 An unexpected scientific parallel

The project was created in **2020**, several years before a notable 2023 study on plant acoustics.

Researchers from **Tel Aviv University** later published experiments showing that stressed tomato and tobacco plants can emit airborne ultrasonic sounds.

The researchers recorded plants under conditions including:

- dehydration
- physical injury
- normal control conditions

and found that Machine Learning models could distinguish aspects of plant condition from those ultrasonic recordings.

The study was published in _Cell_ in March 2023.

This does **not** mean that The Sound Machine records those sounds.

The two systems work very differently:

```text
The Sound Machine

soil moisture
     │
     ▼
Arduino
     │
     ▼
prerecorded MP3
```

versus:

```text
Plant bioacoustics research

plant
  │
  ▼
ultrasonic microphone
  │
  ▼
40–80 kHz recordings
  │
  ▼
signal analysis / ML
```

The similarity is conceptual: both connect plant stress to sound, though through entirely different mechanisms.

### Research

**[Sounds emitted by plants under stress are airborne and informative — Cell / Tel Aviv University](https://cris.tau.ac.il/en/publications/sounds-emitted-by-plants-under-stress-are-airborne-and-informativ/)**

**[Plants Emit Sounds — Especially When Stressed — Tel Aviv University](https://english.tau.ac.il/node/3334)**

---

# 📁 Repository structure

```text
TheSoundMachine/
├── LICENSE
├── LaMaquinaDeKlausner.pdf
├── README.md
├── SoundMachine3.ino
└── SoundMachine5.ino
```

### `SoundMachine3.ino`

Arduino source representing an earlier iteration of The Sound Machine.

### `SoundMachine5.ino`

Later Arduino iteration associated with the redesigned Klausner Machine.

### `LaMaquinaDeKlausner.pdf`

21-page project guide containing additional construction information, circuits, source-code context and project documentation.

### `LICENSE`

GNU General Public License v3.0.

---

# 🚀 Installation

## 1. Clone the repository

```bash
git clone https://github.com/ronibandini/TheSoundMachine.git
cd TheSoundMachine
```

---

## 2. Install Arduino IDE

Download:

**[Arduino IDE](https://www.arduino.cc/en/software)**

---

## 3. Connect the Arduino Nano

Select the appropriate Nano board and processor configuration in:

```text
Tools
→ Board
```

Older Nano boards may require selecting the corresponding legacy bootloader option.

---

## 4. Prepare the microSD card

Format a compatible microSD card according to the requirements of the DFPlayer module.

Copy the required MP3 files to the card.

Keep file names and track numbering consistent with the Arduino sketch.

---

## 5. Connect the DFPlayer

The DFPlayer requires:

```text
power
ground
serial TX/RX
speaker output
```

Check the pin assignments in the selected Arduino sketch before wiring.

---

## 6. Connect the moisture sensor

Connect:

```text
VCC
GND
Analog output
```

to the Arduino.

The analog input used by the sketch must match the hardware wiring.

---

## 7. Add the interface

Depending on the selected version, connect either:

### Original

```text
7-segment display
button
```

or:

### Klausner Machine

```text
analog meters
potentiometer
button
LED
power switch
```

Refer to the circuit documentation included in:

[`LaMaquinaDeKlausner.pdf`](LaMaquinaDeKlausner.pdf)

---

## 8. Upload

Open the corresponding sketch:

```text
SoundMachine3.ino
```

or:

```text
SoundMachine5.ino
```

Compile and upload it to the Arduino Nano.

---

# 🖨️ Enclosure

Both versions use custom enclosures designed in **Fusion 360** and fabricated with a 3D printer.

The second enclosure was redesigned to resemble an older experimental instrument, with prominent analog meters and physical controls.

3D-printable designs by the author are available through:

**[Thingiverse — Roni Bandini](https://www.thingiverse.com/ronibandini/designs)**

---

# 📖 Project manual

The repository includes the complete:

## _La Máquina de Klausner_

21-page user guide.

**[Download `LaMaquinaDeKlausner.pdf`](LaMaquinaDeKlausner.pdf)**

The guide contains additional information about:

- project background
- components
- electronics
- circuit
- construction
- calibration
- source code
- operation

---

# 🎥 Demo

## Original Sound Machine

**[▶️ The Sound Machine — YouTube](https://www.youtube.com/watch?v=saBNWAI-_EE)**

The original demonstration shows the sensor inserted into a plant pot and the machine responding with prerecorded sounds according to moisture.

---

# 🔬 Ideas for extending the project

1. **🎙️ Add ultrasonic recording** — combine the moisture sensor with an ultrasonic microphone to experimentally record high-frequency plant emissions alongside the fictional MP3 responses.

2. **📊 Long-term plant telemetry** — log moisture, temperature, light and machine responses to a microSD card for later visualization.

3. **🌱 Multiple plant profiles** — store individual calibration ranges and sound libraries for different plant species.

---

# 📰 External references

## 🗞️ Independent editorial coverage

### Hackaday — Hearing Plants Giggle Is Just As Creepy As You Think

Hackaday published a dedicated article about The Sound Machine on **March 18, 2020**.

The article covers:

- Roald Dahl's inspiration
- soil-moisture sensing
- Arduino
- DFPlayer audio
- happy and distressed sounds
- the 3D-printed enclosure

**[Read the Hackaday article](https://hackaday.com/2020/03/18/hearing-plants-giggle-is-just-as-creepy-as-you-think/)**

---

## 🗞️ Elettronica In

Italian electronics magazine **Elettronica In** published:

### _Ascolta la salute delle tue piante!_

on May 7, 2020.

The article describes the moisture-controlled sound system, Arduino implementation, DFPlayer and 3D-printed enclosure.

**[Read the article](https://ei.futuranet.it/2020/05/07/ascolta-la-salute-delle-tue-piante/)**

---

## 🗞️ Open-Electronics

Open-Electronics also published coverage of the project:

### _Hearing Plants Giggle is Just as Creepy as You Think_

**[Read on Open-Electronics](https://www.open-electronics.org/hearing-plants-giggle-is-just-as-creepy-as-you-think/)**

---

# 🛠️ Project tutorials

## Hackster.io — Original version

### The Sound Machine (Hear Plant Mood)

Published March 10, 2020.

The tutorial documents:

- Arduino Nano
- FC-28 sensor
- 7-segment display
- button
- DFPlayer
- microSD
- speaker
- enclosure
- moisture mapping
- source repository

**[The Sound Machine — Hackster.io](https://www.hackster.io/roni-bandini/the-sound-machine-hear-plant-mood-76a185)**

---

## Hackster.io — Klausner Machine

### The Klausner Machine :: hear your plants

Published October 17, 2020.

This second project documents the redesigned machine with:

- two analog meters
- sensitivity potentiometer
- improved enclosure
- startup audio
- calibration
- sound anti-repetition logic

**[The Klausner Machine — Hackster.io](https://www.hackster.io/roni-bandini/the-klausner-machine-hear-your-plants-8b6714)**

---

# ✍️ Medium

## La Máquina del Sonido de Roald Dahl

Spanish-language article covering:

- the original literary inspiration
- Arduino implementation
- plant-moisture sensing
- Klausner Machine redesign
- project manual
- Hackaday coverage
- Literature Machines presentation

**[Read on Medium](https://bandini.medium.com/la-m%C3%A1quina-del-sonido-de-roald-dahl-85ece09b1cd6)**

---

# 🎤 Literature Machines

The Klausner Machine was included in **Literature Machines**, a talk about physical devices inspired by literature.

Other machines discussed in the presentation included projects inspired by:

- Julio Cortázar
- Mario Levrero
- Lewis Carroll
- Roald Dahl

The presentation was part of the **Maker Faire Rome / Maker Learn** program.

**[Literature Machines — Medium](https://bandini.medium.com/literature-machines-talk-b04ee30dfddb)**

---

# 📚 Roald Dahl reference

## The Sound Machine

The original story can be read through _The New Yorker_ archive:

**[The Sound Machine — Roald Dahl](https://www.newyorker.com/magazine/1949/09/17/the-sound-machine)**

The story's fictional machine detects frequencies beyond ordinary human hearing and converts them into audible sound.

---

# 🌱 Plant bioacoustics references

The project itself uses soil moisture and prerecorded MP3 files, but later research provides an interesting scientific counterpart to its fictional premise.

- **[Sounds emitted by plants under stress are airborne and informative — Tel Aviv University / Cell](https://cris.tau.ac.il/en/publications/sounds-emitted-by-plants-under-stress-are-airborne-and-informativ/)**
- **[Plants Emit Sounds — Especially When Stressed — Tel Aviv University](https://english.tau.ac.il/node/3334)**

---

# 📕 Contracultura Maker

The Sound Machine belongs to a broader series of projects where literature, old technologies, unusual interfaces and electronics are turned into physical machines.

More projects, technical context and essays are collected in:

**[Contracultura Maker — book](https://bandini.medium.com/libro-de-contracultura-maker-94d1bb0d951c)**

---

# 📚 Useful references

- **[Arduino](https://www.arduino.cc/)**
- **[Arduino Nano](https://docs.arduino.cc/hardware/nano/)**
- **[DFPlayer Mini](https://wiki.dfrobot.com/DFPlayer_Mini_SKU_DFR0299)**
- **[The Sound Machine — The New Yorker](https://www.newyorker.com/magazine/1949/09/17/the-sound-machine)**
- **[Plant stress sounds — Tel Aviv University](https://english.tau.ac.il/node/3334)**

---

# 🔗 You may also be interested in...

Other projects by **Roni Bandini** connecting literature, physical interfaces and electronic machines.

## 🧠📖 AI Remember

**Generative literature system using local LLMs to produce fictional memories beginning with “Me acuerdo…”.**

Another experiment where a literary structure becomes the operating rule of a machine.

**[github.com/ronibandini/AIRemember](https://github.com/ronibandini/AIRemember)**

---

## 📚⌨️ Kindle Typewriter

**A jailbroken Kindle Paperwhite converted into a distraction-free typewriter connected to a Raspberry Pi and thermal printer.**

A project combining literature, obsolete interfaces and physical output.

**[github.com/ronibandini/Kindle-Typewriter](https://github.com/ronibandini/Kindle-Typewriter)**

---

## 🧸📚 Furby

**A discarded Furby transformed into a literary electronic automaton.**

Another project that turns an existing object into a new interface for literature and sound.

**[github.com/ronibandini/furby](https://github.com/ronibandini/furby)**

---

# ⚠️ Notes

## The audio is prerecorded

The Sound Machine does not amplify or translate actual acoustic signals produced by the connected plant.

Its behavior is:

```text
soil reading
     │
     ▼
software mapping
     │
     ▼
prerecorded sound
```

The sounds are part of the artistic interpretation.

---

## Resistive soil sensors

FC-28-style resistive probes can corrode when powered continuously in wet soil.

For occasional measurements this may be acceptable, but for long-term monitoring consider:

- powering the probe only while taking a reading
- using a capacitive soil-moisture sensor
- periodically recalibrating the system

---

## Calibration

Do not assume that the same analog values represent identical moisture levels across different:

- soils
- pots
- sensors
- plants

Calibrate the system for the installation where it will be used.

---

# 📜 License

The source code in this repository is released under the **GNU General Public License v3.0**.

See [`LICENSE`](LICENSE) for details.

---

# 👤 Author

**Roni Bandini**

Maker, AI developer, electronic artist and writer.

- 🐙 GitHub: [@ronibandini](https://github.com/ronibandini)
- 💼 LinkedIn: [Roni Bandini](https://www.linkedin.com/in/ronibandini/)
- 📸 Instagram: [@ronibandini](https://www.instagram.com/ronibandini/)
- 🐦 X: [@RoniBandini](https://x.com/RoniBandini)
- ✍️ Medium: [bandini.medium.com](https://bandini.medium.com/)
- 🛠️ Hackster: [Roni Bandini](https://www.hackster.io/roni-bandini)

Buenos Aires, Argentina.
