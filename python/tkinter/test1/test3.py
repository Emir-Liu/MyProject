#test3.py
from tkinter import *
import tkinter.messagebox as msg

window = Tk()
window.title("Calculator")
window.geometry('1068x681+10+10')
#建立窗口，设置标题，窗口初始大小

label_text = StringVar()
label_text.set('Hello The Calculator')
in_put = ''
str_num = '0'
pre_num = 0
number = 0
pre_ope= 0
label = Label(window,textvariable = label_text)
#建立标签label
def deal(dat):
    global in_put,str_num
    in_put += dat
    label_text.set(in_put)
    if dat.isdigit():
        str_num += dat
    else:
        global number,pre_num,pre_ope
        number = int(str_num)
        msg.showinfo('str_num',str_num)
        msg.showinfo('number',str(number))
        msg.showinfo('pre_num',str(pre_num))
        str_num = '0'
        if dat == '=':
            in_put = ''
            if pre_ope == 1:
                number += pre_num
                pre_number = number
            msg.showinfo('Answer',number)
        elif dat == '+':
            pre_num = number
            number = 0
            pre_ope = 1
def click_1():
    tmp='1'
    deal(tmp)
def click_add():
    tmp='+'
    deal(tmp)
def click_equ():
    tmp='='
    deal(tmp)
#建立按键函数

button_1 = Button(window,text='1',command = click_1)
button_add = Button(window,text='+',command = click_add)
button_equ = Button(window,text='=',command = click_equ)


label.pack()
button_1.pack()
button_add.pack()
button_equ.pack()
#几何控制，控制部件的位置

window.mainloop()
#进入主事件循环
