#!/usr/bin/env bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

echo "[*] This script replaces existing flags with those in flags.txt. Don't use spaces in flags!"
echo "[!] Replace flags? Y/n"
read response

if [[ $response ==  "n" ]]; then
	echo "[*] Exiting"
	exit 0
else
	echo "[*] Replacing flags"
fi

for flag in $(cat $DIR/flags.txt); do
	echo $flag 
	level=$(echo "$flag" | cut -d\: -f1)
	text=$(echo "$flag" | cut -d\: -f2)
	crypted=$(python $DIR/encoder.py $text)

        sed -i '/*SECRET/c\char *SECRET='\"${crypted}\"\;'\' $DIR/../src/${level}.c
        sed -i -e "s/\"'/\"/g" -e "s/'\"/\"/g" $DIR/../src/${level}.c
done
