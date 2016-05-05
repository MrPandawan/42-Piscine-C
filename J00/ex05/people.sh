#!/bin/sh

ldapsearch -xLLL cn | grep -i '^cn: z' | sort -r | cut -d ' ' -f2-3
