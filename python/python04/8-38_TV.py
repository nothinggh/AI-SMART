class Television:
    def __init__(self, ch, vol, on):
        self.ch = ch
        self.vol = vol
        self.on = on

    def show(self):
        print(self.ch, self.vol, self.on)

class App:
    def __init__(self):
     pass
    def setSilentMode(self,t):
     t.vol =2
    


# Televisio() # default 생성자
# myTV=Television() # Err
myTV=Television(11,10,True) # 인자가 3개 있는 생성자
app=App()
app.setSilentMode(myTV)

myTV.show()