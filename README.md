#LASER Comm
Did you know NASA has a [LASER communication][NASA LASER] system on the International Space Station?  With NASA as inspiration, we at Vesta Technology wanted to see what kind of LASER communication we could do with Mercury 16.  This project uses a LASER to communicate!

[NASA LASER]: http://phaeton.jpl.nasa.gov/external/projects/optical.cfm

The transmit circuit is driven by the Tx pin of the USART1 module on the PIC16f1947.  The signal is passed through a transistor that acts as a switch to blink, really fast, a LASER diode harvested from a cheap LASER pointer.  The receiving circuit uses a photodiode to collect the LASER light and sends the signal through a comparator to clean it up into a nice digital signal.  Then, it's sent to the Rx pin of USART1.  The project flashes the onboard LED when transmission is successful and prints the number of errors when it's not.

This project relies on __usart.h__ and __usart1async.h__ from the Common folder of [Onboard Mercury 16][mer16].  Please be sure you have downloaded them and saved them in a folder named Common, in the same folder that your project directory is in.  `#include "../Common/usart.h`

[mer16]: https://github.com/VestaTechnology/Onboard_Mercury_16

![](https://github.com/VestaTechnology/LASER-Comm/blob/master/schematic.png)

This project would be fun to expand on and split the transmit and receive circuits so they each have their own Mercury 16.  I wonder how far you could send a signal.  Placing a magnifying glass in front of the receiving diode helps focus the beam for long range transmissions.  

Please share all that you come up with using this project.  Also, suggest improvements for the transmit and receive circuits.  I don't have any experience driving a LASER diode.  

Feel free to create a pull request, submit an issue, [contact us][contact] or send us an [email][mail].

[contact]: https://www.vestatech.com/support/contact-us/
[mail]: mailto:support@vestatech.com?subj=Github/Mercury