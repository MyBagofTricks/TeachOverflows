#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys

def encoder(plaintext, key):
    offset = lambda x: 65 if x.isupper() else 97
    encoded = [] 
    for l in plaintext:   
        if l.isalpha():
            encoded.append(magic_shift(l, key) ^ key)
        else:
            encoded.append(ord(l) ^ key)
    return [hex(x) for x in encoded]
                                                                                   
def magic_shift(letter, key):
    offset = lambda x: 65 if x.isupper() else 97
    return ( (((ord(letter) - offset(letter) ) + key%26) % 26) + offset(letter))

if __name__ == "__main__":
    if len(sys.argv) < 2:
        raise SystemExit
    plaintext = "".join(sys.argv[1:len(sys.argv)])
    if plaintext == "":
        plaintext = "bu773r_0v3rf10ws_@re_FuN_@nd_3duc@t10n@l"
    elif len(plaintext) > 255:
        print("Error: Flag must be less than 255 characters")
        raise SystemExit
    key = len(plaintext)
    secret = encoder(plaintext, key)
    formatted = str(secret).replace("[", "{").replace("]", "}").replace(", ", ",").replace("'","")
    output = ("int SECRET[{}] = {};".format(str(key), formatted))
    print(output)

