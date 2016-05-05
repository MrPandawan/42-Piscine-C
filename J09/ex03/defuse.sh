#!/bin/sh

ls -lT | grep bomb | cut -d ':' -f3 | cut -d ' ' -f1
