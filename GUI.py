import tkinter 
from tkinter import *
from tkinter import messagebox
import time
import serial


#ser = serial.Serial('COM4', 9600)


def open_gripper ():
    messagebox.showinfo( "Hello Python", "Gripper Open")
    #ser.write(str(1))
    return

def close_gripper ():
    messagebox.showinfo( "Hello Python", "Gripper closed")
    return

#initializing GUI
root = Tk()

root.geometry("400x400")
motorControl = Frame(root)
motorControl.pack()

forwardFrame = Frame(motorControl)
forwardFrame.pack()

backFrame = Frame(motorControl)
backFrame.pack (side = BOTTOM)

speedControl = Frame(root)
speedControl.pack()

#arm
armControl = Frame(root)
armControl.pack()

armLabel = Label(armControl, text = "Arm Components", bg = "red", padx = 100)
armLabel.pack()

#base
baseFrame=Frame(root)
baseFrame.pack()
baseLabel = Label(baseFrame, text = "Base", bg = "green", padx = 100)
baseLabel.pack()
baseleft=Button(baseFrame,text="Left",height=2,width=5)
baseleft.pack(side=LEFT)
baseright=Button(baseFrame,text="Right",height=2,width=5)
baseright.pack(side=RIGHT)

#Shoulder

shoulderFrame=Frame(root)
shoulderFrame.pack()
shoulderLabel = Label(shoulderFrame, text = "Shoulder", bg = "green", padx = 100)
shoulderLabel.pack()
shoulderleft=Button(shoulderFrame,text="Front",height=2,width=5)
shoulderleft.pack(side=LEFT)
shoulderright=Button(shoulderFrame,text="Back",height=2,width=5)
shoulderright.pack(side=RIGHT)

#ELBOW

elbowFrame=Frame(root)
elbowFrame.pack()
elbowLabel = Label(elbowFrame, text = "Elbow", bg = "green", padx = 100)
elbowLabel.pack()
elbowleft= Button(elbowFrame,text="Front",height=2,width=5)
elbowleft.pack(side=LEFT)
elbowright= Button(elbowFrame,text="Back",height=2,width=5)
elbowright.pack(side=RIGHT)

#Wrist

wristFrame=Frame(root)
wristFrame.pack()
wristLabel= Label(wristFrame, text="Wrist", bg="green", padx=100)
wristLabel.pack()
wristleft= Button(wristFrame,text="Front",height=2,width=5)
wristleft.pack(side=LEFT)
wristright= Button(wristFrame,text="Back",height=2,width=5)
wristright.pack(side=RIGHT)

#Gripper

gripperFrame = Frame(root)
gripperFrame.pack()


gripperLabel = Label(gripperFrame, text = "Gripper", bg = "green", padx = 20)
gripperLabel.pack()


gripOpenBut = Button(gripperFrame, text ="Open", height = 2, width = 5, command = open_gripper  )
gripOpenBut.pack(side = RIGHT)

gripCloseBut = Button(gripperFrame, text ="Close", height = 2, width = 5,command = close_gripper )
gripCloseBut.pack(side = RIGHT)


root.mainloop()
