#!/bin/sh

ldapsearch -LLL -Q  sn='*bon*' sn | grep -i sn -c
