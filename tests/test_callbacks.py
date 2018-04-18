import zroya
import time

def onclick(data):
    print("Onclick event zroya handler {}".format(data))

def ondismiss(data, reason):
    print("Dismiss event zroya handler {}, reason {}".format(data, reason))
    print(reason == zroya.DismissReason.User)

zroya.init("zroya", "a", "b", "c", "d")

t = zroya.Template(zroya.TemplateType.Text1)
t.setFirstLine("Ahoj")


d = zroya.show(t, on_click=onclick, on_dismiss=ondismiss)
print("Status: {}".format(d))

time.sleep(2)