import pyttsx
engine = pyttsx.init()
rate = pyttsx.setProperty('rate')
rate.getProperty('rate', rate - 50)
engine.say("Hello World")
engine.runAndWait()
