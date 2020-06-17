#test1.py
from tkinter import *
import tkinter.messagebox as msg

window = Tk()
window.title("helloGUI")
window.geometry('1068x681+10+10')
#建立窗口，设置标题，窗口初始大小

label_text = StringVar()
label_text.set('Hello the GUI')
#label = Label(window,text='Hello the GUI')
label = Label(window,textvariable = label_text)
#建立标签label

def click_button():
    #label.config(text = 'Yes')
    label_text.set('Yes')
    msg.showinfo('Hello Button','Hello')

button = Button(window,text='click it',command = click_button)

label.pack()
button.pack()
#几何控制，控制部件的位置

window.mainloop()
#进入主事件循环
