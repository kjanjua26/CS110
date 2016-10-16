import aiml
import os

k = aiml.Kernel()

k.learn("star.aiml")
k.learn("under.aiml")
k.learn("command.aiml")
k.learn("1.aiml")
k.learn("2.aiml")
k.learn("3.aiml")
k.learn("4.aiml")
k.learn("5.aiml")
k.learn("6.aiml")
k.learn("8.aiml")
k.learn("9.aiml")
k.learn("B.aiml")
k.learn("A.aiml")
k.learn("C.aiml")
k.learn("E.aiml")
k.learn("ins.aiml")


while True:
    input = raw_input("Ask me anything: ") 
    if input == "quit":
      sys.exit(0)
    response = k.respond(input) 
    print 'Zeus: ', response

print commands.getoutput("C:\Python27\Lib\eSpeak -v en+f4 -p 99 -s 160 2>/dev/null  + response + ")
