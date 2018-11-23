#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys

def encoder(plaintext, key):
    offset = lambda x: 65 if x.isupper() else 97
    encoded = bytearray()          
    for l in plaintext:   
        if l.isalpha():
            encoded.append(magic_shift(l, key) ^ key)
        else:
            encoded.append(ord(l) ^ key)
    return encoded        
                                                                                   
def magic_shift(letter, key):
    offset = lambda x: 65 if x.isupper() else 97
    return ( (((ord(letter) - offset(letter) ) + key%26) % 26) + offset(letter))

def get_user_input(text):
    # Python2/3 input helper function
    if sys.hexversion > 0x03000000:
        return input(text)
    else:
        return raw_input(text)


if __name__ == "__main__":
    print("\nThis script generates and encodes a flag for the stack smashing exercises.")
    print("Copy and Paste the result it into the appropriate stack.c file,")
    print("replacing the current value, then build it. Maximum 255 ASCII characters.\n")
    password = get_user_input("Enter a your flag (Leave blank for default flag): ")
    if password == "":
        password = "bu773r_0v3rf10ws_@re_FuN_@nd_3duc@t10n@l"
    elif len(password) > 255:
        print("Error: Flag must be less than 255 characters")
        raise SystemExit
    print("Using flag: {password}".format(password=password))
    key = len(password)
    secret = encoder(password, key)
    print("Encoded flag:")
    print("".join("'{}'".format(''.join('\\x{:02x}'.format(b) for b in secret))))

