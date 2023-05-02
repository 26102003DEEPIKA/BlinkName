from tkinter import*
import tkinter.font
from gpiozero import LED
import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BCM)

## hardware
Redled  = LED(14)
Greenled = LED(15)
Blueled = LED(18)

## GUI DEFINITIONS ##
win = Tk()
win.title("Led Toggler")
myFont = tkinter.font.Font(family = 'Helvetica', size = 12, weight = "bold")

## EVENT FUNTIONS ##
def ledToggle(led, button):
   if led.pin.number == Redled.pin.number:
          Greenled.off()
          Blueled.off()
   elif led.pin.number == Greenled.pin.number:
          Redled.off()
          Blueled.off()
   elif led.pin.number == Blueled.pin.number :
         Redled.off()
         Greenled.off()

   if led.is_lit:
       led.off()
       button["text"] = f"Turn {led.pin.color} LED on"
   else:
       led.on()
       button["text"] = f"Turn {led.pin.color} LED off"

def close():
    GPIO.cleanup()
    win.destroy()

## WIDGETS ##

ledButton1 = Button(win, text = 'Turn Red LED On', font = myFont, bg = 'bisque2', height = 1, width = 24)
ledButton1["command"] = lambda: ledToggle(Redled, ledButton1)
ledButton1.grid(row=0, column = 1)

ledButton2 = Button(win, text = 'Turn Green LED On', font = myFont, bg = 'bisque2', height = 1, width = 24)
ledButton2["command"] = lambda: ledToggle(Greenled, ledButton2)
ledButton2.grid(row = 1,column = 1)

ledButton3 = Button(win, text = 'Turn Blue LED On', font = myFont, bg = 'bisque2', height = 1, width = 24)
ledButton3["command"] = lambda: ledToggle(Blueled, ledButton3)
ledButton3.grid(row = 2,column = 1)

exitButton = Button(win, text = 'Exit', font = myFont, command = close, bg = 'red', height = 1, width = 6)
exitButton.grid(row = 3, column = 1)

win.protocol("WM_DELETE_WINDOW", close)

win.mainloop()
