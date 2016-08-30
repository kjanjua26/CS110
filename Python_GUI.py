import tkinter as tk
from tkinter import ttk
from tkinter import scrolledtext
from tkinter import Menu

root = tk.Tk()

def _quit():
    root.quit()
    root.destroy()
    exit()

menuBar = Menu(root)
root.configure(menu = menuBar)
fileMenu = Menu(menuBar, tearoff=0)
helpMenu = Menu(menuBar, tearoff=0)
helpMenu.add_command(label='About')
menuBar.add_cascade(label='File', menu=fileMenu)
fileMenu.add_command(label="New")
fileMenu.add_command(label='Exit', command=_quit)
menuBar.add_cascade(label="Help", menu=helpMenu)

COLOR1 = 'Blue'
COLOR2 = 'Gold'
COLOR3 = 'Red'

scrolW = 30
scrolH = 3

def radCall():
    radSel = radVar.get()
    if radSel == 1: root.configure(background=COLOR)
    elif radSel == 2: root.configure(background=COLOR2)
    elif radSel == 3: root.configure(background=COLOR3)

def clickMe():
    action.configure(text="Hello" + ' ' + name.get() + ' ' +  ' ' + numberChosen.get())


scr = scrolledtext.ScrolledText(root, width=scrolW, height=scrolH, wrap=tk.WORD)
scr.grid(column=0, columnspan=3, row=7)

radVar = tk.IntVar()
rad1 = tk.Radiobutton(root, text=COLOR1, variable=radVar, value=1, command=radCall)
rad1.grid(column=0, row=5, sticky=tk.W)

rad2 = tk.Radiobutton(root, text=COLOR2, variable=radVar, value=2, command=radCall) # 11
rad2.grid(column=1, row=5, sticky=tk.W)

rad3 = tk.Radiobutton(root, text=COLOR3, variable=radVar, value=3, command=radCall) # 13
rad3.grid(column=2, row=5, sticky=tk.W)

chVarDis = tk.IntVar()
check1 = tk.Checkbutton(root, text='Disabled', variable=chVarDis, state='disabled')
check1.select()
check1.grid(column=0, row=4, sticky=tk.W)

chVarUn = tk.IntVar()
check2 = tk.Checkbutton(root, text='UnChecked', variable=chVarUn)
check2.deselect()
check2.grid(column=1, row=4, sticky=tk.W)

chVarEn = tk.IntVar()
check3 = tk.Checkbutton(root, text='Enabled', variable=chVarEn)
check3.select()
check3.grid(column=2, row=4, sticky =tk.W)

action = ttk.Button(root, text='Click Me!', command=clickMe)
ttk.Label(root, text='Choose a number: ').grid(column=1, row=0)
number = tk.StringVar()
numberChosen = ttk.Combobox(root, width=12, textvariable=number)
numberChosen['values'] = (1, 2, 4, 42, 100)
numberChosen.grid(column=1, row=1)
numberChosen.current(0)
action.grid(column=2, row=1)
root.title("Python GUI")
name = tk.StringVar()
nameEntered = ttk.Entry(root, width=12, textvariable=name)
nameEntered.grid(column=0, row=1)
nameEntered.focus()
ttk.Label(root, text='Enter a name: ').grid(column=0, row=0)
root.mainloop()
