import base64
flag = open("my_encodings.txt","rb").read()

def isBase64(s):
    try:
        return base64.b64encode(base64.b64decode(s)) == s
    except Exception:
        return False
        
def isBase32(s):
    try:
        return base64.b32encode(base64.b32decode(s)) == s
    except Exception:
        return False
def isBase16(s):
    try:
        return base64.b16encode(base64.b16decode(s)) == s
    except Exception:
        return False
def isBase85(s):
    try:
        return base64.b85encode(base64.b85decode(s)) == s
    except Exception:
        return False

while b'SSS{' not in flag:
    if isBase16(flag):
        flag = base64.b16decode(flag)
    elif isBase32(flag):
        flag = base64.b32decode(flag)
    elif isBase64(flag):
        flag = base64.b64decode(flag)
    elif isBase85(flag):
        flag = base64.b85decode(flag)
print(flag)
